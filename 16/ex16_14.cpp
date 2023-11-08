#include <iostream>
#include <string>
using std::string;

template <string::size_type height, string::size_type width>
class Screen {
public:
    using size_type = string::size_type;
    using content_type = char;
    explicit Screen(content_type c = ' '): cursor(0), contents(height * width, c) {}
    const Screen& display(std::ostream &os) const;
private:
    void do_display(std::ostream &os) const;
    size_type cursor = 0;
    string contents;
};

template <string::size_type height, string::size_type width>
void Screen<height, width>::do_display(std::ostream &os) const {
    for (size_type i = 0; i != contents.size(); ++i) {
        os << contents[i];
        if ((i + 1) % width == 0 && i + 1 != contents.size()) {
            os << '\n';
        }
    }
}

template <string::size_type height, string::size_type width>
const Screen<height, width>& Screen<height, width>::display(std::ostream &os) const {
    do_display(os);
    return *this;
}

int main() {
    Screen<3, 4> s('X');
    s.display(std::cout);
    std::cout << std::endl;
}

