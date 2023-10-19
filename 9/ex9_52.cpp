#include <string>
using std::string; using std::stoi; using std::to_string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl; using std::cerr;

#include <stack>
using std::stack;

int main() {
    stack<string> st;
    string expr = "1 + (2 - (3 + 4))";
    for (char c : expr) {
        if (c == ')') {
            string rand2 = st.top();
            st.pop();
            string op = st.top();
            st.pop();
            string rand1 = st.top();
            st.pop();
            
            if (st.top() != "(") {
                cerr << "ill matched parenthesis" << endl;
                return 0;
            } else {
                st.pop();
            }
            if (op == "+") {
                st.push(to_string(stoi(rand1) + stoi(rand2)));
            } else {
                st.push(to_string(stoi(rand1) - stoi(rand2)));
            }
        } else if (c != ' ') {
            st.push(string(1, c));
        }
    }
    while (st.size() > 1) {
        string rand2 = st.top();
        st.pop();
        string op = st.top();
        st.pop();
        string rand1 = st.top();
        st.pop();
        if (op == "+") {
                st.push(to_string(stoi(rand1) + stoi(rand2)));
            } else {
                st.push(to_string(stoi(rand1) - stoi(rand2)));
            }
    }
    cout << st.top() << endl;
}