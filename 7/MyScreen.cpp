#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const
    {
        ++access_ctr;
        return contents[cursor];
    }
    char get(pos, pos) const;
    Screen &move(pos, pos);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os) {
        os << "non const: ";
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const {
        os << "const: ";
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;
    void do_display(std::ostream &os) const {
        os << contents;
    }
};

inline char Screen::get(pos r, pos c) const
{
    ++access_ctr;
    return contents[r * width + c];
}

inline Screen &Screen::move(pos r, pos c)
{
    ++access_ctr;
    cursor = r * width + c;
    return *this;
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return * this;
}

inline Screen &Screen::set(pos r, pos col, char c) {
    contents[r * width + col] = c;
    return *this;
}

int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    const Screen constScreen(5, 5, 'Y');
    constScreen.display(cout);
    cout << endl;
    return 0;
}