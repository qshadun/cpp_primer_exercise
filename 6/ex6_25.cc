#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstring>
using std::strlen;
using std::strcpy;
using std::strcat;

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        char *a1 = argv[1], *a2 = argv[2];
        size_t len = strlen(a1) + strlen(a2) + 1;
        char* s = (char*) malloc(len);
        strcpy(s, a1);
        strcat(s, a2);
        cout << s << endl;
        free(s);
    }
     cout << sizeof(char) << endl;
}