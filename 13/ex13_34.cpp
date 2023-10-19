
#include <utility>
// for move, we don't supply a using declaration for move

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <set>
using std::set;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Folder;

class Message
{
    friend void swap(Message &, Message &);
    friend class Folder;

public:
    // folders is implicitly initialized to the empty set
    explicit Message(const std::string &str = "") : contents(str) {}

    // copy control to manage pointers to this Message
    Message(const Message &);            // copy constructor
    Message &operator=(const Message &); // copy assignment
    ~Message();                          // destructor
    Message(Message &&);                 // move constructor
    Message &operator=(Message &&);      // move assignment

    // add/remove this Message from the specified Folder's set of messages
    void save(Folder &);
    void remove(Folder &);
    void debug_print(); // print contents and it's list of Folders,
                        // printing each Folder as well
private:
    std::string contents;       // actual message text
    std::set<Folder *> folders; // Folders that have this Message

    // utility functions used by copy constructor, assignment, and destructor
    // add this Message to the Folders that point to the parameter
    void add_to_Folders(const Message &);
    void move_Folders(Message *);
    // remove this Message from every Folder in folders
    void remove_from_Folders();

    // used by Folder class to add self to this Message's set of Folder's
    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};
// declaration for swap should be in the same header as Message itself
void swap(Message &, Message &);

class Folder
{
    friend void swap(Message &, Message &);
    friend class Message;

public:
    ~Folder();                         // remove self from Messages in msgs
    Folder(const Folder &);            // add new folder to each Message in msgs
    Folder &operator=(const Folder &); // delete Folder from lhs messages
                                       // add Folder to rhs messages
    Folder(Folder &&);                 // move Messages to this Folder
    Folder &operator=(Folder &&);      // delete Folder from lhs messages
                                       // add Folder to rhs messages

    Folder() = default; // defaults ok

    void save(Message &);   // add this message to folder
    void remove(Message &); // remove this message from this folder

    void debug_print(); // print contents and it's list of Folders,
private:
    std::set<Message *> msgs; // messages in this folder

    void add_to_Messages(const Folder &); // add this Folder to each Message
    void remove_from_Msgs();              // remove this Folder from each Message
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
    void move_Messages(Folder *); // move Message pointers to point to this Folder
};

void Folder::save(Message &m)
{
    msgs.insert(&m);
    m.addFldr(this);
}

void Folder::remove(Message &m)
{
    msgs.erase(&m);
    m.remFldr(this);
}

Folder::Folder(const Folder &f) : msgs(f.msgs)
{
    add_to_Messages(f);
}

Folder &Folder::operator=(const Folder &rhs)
{
    remove_from_Msgs();
    msgs = rhs.msgs;
    add_to_Messages(rhs);
    return *this;
}

void Folder::add_to_Messages(const Folder &f)
{
    for (auto m : f.msgs)
    {
        m->addFldr(this);
    }
}

void Folder::remove_from_Msgs()
{
    for (auto m : msgs)
    {
        m->remFldr(this);
    }
    msgs.clear();
}

Folder::~Folder()
{
    remove_from_Msgs();
}

void Folder::move_Messages(Folder *f)
{
    msgs = std::move(f->msgs);
    f->msgs.clear();
    for (auto m : msgs)
    {
        m->remFldr(f);
        m->addFldr(this);
    }
}

Folder::Folder(Folder &&f)
{
    move_Messages(&f);
}

Folder &Folder::operator=(Folder &&f)
{
    if (this != &f)
    {
        remove_from_Msgs();
        move_Messages(&f);
    }
    return *this;
}

void Folder::debug_print()
{
    cerr << "Folder contains " << msgs.size() << " messages" << endl;
    int ctr = 1;
    for (auto m : msgs)
    {
        cerr << "Message " << ctr++ << ":\n\t" << m->contents << endl;
    }
}

// ==================messages====================
void Message::debug_print()
{
    cerr << "Message:\n\t" << contents << endl;
    cerr << "Appears in " << folders.size() << " Folders" << endl;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
    {
        f->remMsg(&lhs);
    }
    for (auto f : rhs.folders)
    {
        f->remMsg(&rhs);
    }
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders)
    {
        f->addMsg(&lhs);
    }
    for (auto f : rhs.folders)
    {
        f->addMsg(&rhs);
    }
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
    {
        f->addMsg(this);
    }
}

void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders);
    for (auto f : folders)
    {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

// remove this Message from every Folder in folders
void Message::remove_from_Folders()
{
    for (auto f : folders)
    {
        f->remMsg(this);
    }
    folders.clear();
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) // copy constructor
{
    add_to_Folders(m);
}

Message &Message::operator=(const Message &rhs) // copy assignment
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message() // destructor
{
    remove_from_Folders();
}
Message::Message(Message &&m) : contents(std::move(m.contents)) // move constructor
{
    move_Folders(&m);
}
Message &Message::operator=(Message &&rhs) // move assignment
{
    if (this != &rhs)
    {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}

int main()
{
    string s1("contents1");
    string s2("contents2");
    string s3("contents3");
    string s4("contents4");
    string s5("contents5");
    string s6("contents6");

    // all new messages, no copies yet
    Message m1(s1);
    Message m2(s2);
    Message m3(s3);
    Message m4(s4);
    Message m5(s5);
    Message m6(s6);

    Folder f1;
    Folder f2;

    m1.save(f1);
    m3.save(f1);
    m5.save(f1);
    m1.save(f2);
    m2.save(f2);
    m4.save(f2);
    m6.save(f2);

    m1.debug_print();
    f2.debug_print();

    // create some copies
    Message c1(m1);
    Message c2(m2), c4(m4), c6(m6);

    m1.debug_print();
    f2.debug_print();

    // now some assignments
    m2 = m3;
    m4 = m5;
    m6 = m3;
    m1 = m5;

    m1.debug_print();
    f2.debug_print();

    // finally, self-assignment
    m2 = m2;
    m1 = m1;

    m1.debug_print();
    f2.debug_print();

    vector<Message> vm;
    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m1);

    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m2);

    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m3);

    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m4);

    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m5);

    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m6);

    vector<Folder> vf;
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(f1);

    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(f2);

    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(Folder(f1));

    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(Folder(f2));

    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(Folder());

    Folder f3;
    f3.save(m6);
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(f3);

    return 0;
}