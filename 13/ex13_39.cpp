#include <iostream>
using std::cout; using std::endl; using std::istream;
#include <memory>
#include <utility>
#include <initializer_list>
#include <string>
using std::pair;
using std::string;
#include <algorithm>
#include <fstream>
using std::ifstream;


class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<string>);

    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);

    StrVec(StrVec &&) noexcept;
    StrVec &operator=(StrVec &&) noexcept;

    ~StrVec() noexcept;

    void push_back(string &);
    void push_back(string &&);

    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    string *begin() const { return elements; }
    string *end() const { return first_free; }

    // operator functions
    StrVec &operator=(std::initializer_list<string>);
    string &operator[](size_t n)
    {
        return elements[n];
    }
    const string &operator[](size_t n) const
    {
        return elements[n];
    }

    // emplace member covered in chapter 16
	template <class... Args> void emplace_back(Args&&...);
private:
    static std::allocator<string> alloc;
    string *elements;
    string *first_free;
    string *cap;

    void check_n_alloc()
    {
        if (size() == capacity())
        {
            reallocate();
        }
    }

    void free();
    void reallocate();

    pair<string *, string *> alloc_n_copy(const string *, const string *);
};

// definition for static data member
std::allocator<string> StrVec::alloc;  

inline
pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}
inline
void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements; /* empty */ ) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

inline
void StrVec::reallocate() {
    auto newCapacity = size() ? 2 * size() : 1;
    auto newData = alloc.allocate(newCapacity);
    auto dest = newData;
    auto oldElem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*oldElem++));
    }
    free();
    
    elements = newData;
    first_free = dest;
    cap = elements + newCapacity;
}

inline
StrVec::~StrVec() noexcept { free(); }

inline
StrVec::StrVec(StrVec&& s) noexcept: elements(s.elements), first_free(s.first_free), cap(s.cap)          // move constructor
{
    s.elements = s.first_free = s.cap = nullptr;
}

inline
StrVec::StrVec(std::initializer_list<std::string> il)
{
	// call alloc_n_copy to allocate exactly as many elements as in il
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

inline 
StrVec & StrVec::operator=(StrVec&& rhs) noexcept // move assignment
{
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

inline
StrVec::StrVec(const StrVec& s)           // copy constructor
{
    auto newData = alloc_n_copy(s.elements, s.first_free);
    elements = newData.first;
    first_free = cap = newData.second;
}

StrVec & StrVec::operator=(const StrVec& s) // copy assignment
{
    auto newData = alloc_n_copy(s.elements, s.first_free);
    free();
    elements = newData.first;
    first_free = cap = newData.second;
    return *this;
}

inline
void StrVec::push_back(string &s) {
    check_n_alloc();
    alloc.construct(first_free++, s);
}

inline
void StrVec::push_back(string &&s) {
    check_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

template <class... Args>
inline
void StrVec::emplace_back(Args&&... args)
{
    check_n_alloc(); // reallocates the StrVec if necessary
	alloc.construct(first_free++, std::forward<Args>(args)...);
}


void print(const StrVec &svec)
{
	for (auto it : svec)
		cout << it << " " ;
	cout <<endl;
}

StrVec getVec(istream &is)
{
	StrVec svec;
	string s;
	while (is >> s)
		svec.push_back(s);
	return svec;
}
	
int main()
{
	StrVec sv = {"one", "two", "three"};
	// run the string empty funciton on the first element in sv
	if (!sv[0].empty()) 
		sv[0] = "None"; // assign a new value to the first string 

	// we'll call getVec a couple of times
	// and will read the same file each time
	ifstream in("data/storyDataFile");
	StrVec svec = getVec(in);
	print(svec);
	in.close();

	cout << "copy " << svec.size() << endl;
	auto svec2 = svec;
	print(svec2);

	cout << "assign" << endl;
	StrVec svec3;
	svec3 = svec2;
	print(svec3);

	StrVec v1, v2;
	v1 = v2;                   // v2 is an lvalue; copy assignment

	in.open("data/storyDataFile");
	v2 = getVec(in);          // getVec(in) is an rvalue; move assignment
	in.close();

	StrVec vec;  // empty StrVec
	string s = "some string or another";
	vec.push_back(s);      // calls push_back(const string&)
	vec.push_back("done"); // calls push_back(string&&)

	// emplace member covered in chpater 16
	s = "the end";
	vec.emplace_back(10, 'c'); // adds cccccccccc as a new last element
	vec.emplace_back(s);  // uses the string copy constructor
	string s1 = "the beginning", s2 = s;
	vec.emplace_back(s1 + s2); // uses the move constructor

	return 0;
}

