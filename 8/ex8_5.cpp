#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <fstream>

#include <string>
using std::string;

#include <vector>
using std::vector;

vector<string> read(const string &filename)
{
    std::ifstream ifs(filename);
    vector<string> result;
    string tmp;
    if (ifs)
    {
        while (ifs >> tmp)
        {
            result.push_back(tmp);
        }
    }
    else
    {
        std::cerr << "failed to open file: " << filename << endl;
    }
    return result;
}
int main()
{
    string filename;
    cout << "please input a file name: ";
    cin >> filename;

    vector<string> vs = read(filename);
    for (string s: vs) {
        cout << s << ' ';
    }
    cout << endl;

}