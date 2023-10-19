#include<string>
#include<vector>
#include<iostream>


using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::begin;
using std::end;
using std::size_t;

int main() {
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];

    for (size_t i = 0; i < rowCnt; i++) {
        for (size_t j = 0; j < colCnt; j++) {
            ia[i][j] = i * colCnt + j;
        }
    }
    cout << "loop with index" << endl;
    for (size_t i = 0; i < rowCnt; i++) {
        for (size_t j = 0; j < colCnt; j++) {
            cout << ia[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "loop with for range" << endl;
    // for (int (&row)[colCnt] : ia) {
    for (auto &row : ia) {
        for (int col: row) {
            cout << col << ' ';
        }
        cout << endl;
    }

    cout << "loop with pointer" << endl;
    for (auto p = ia; p != ia + rowCnt; p ++) {
        for (auto q = *p; q != *p + colCnt; q++) {
            cout << *q << ' ';
        }
        cout << endl;
    }

    cout << "loop with pointers and begin / end" << endl;
    for (auto p = begin(ia); p != end(ia); p++) {
        for (auto q = begin(*p); q != end(*p); q++) {
            cout << *q << ' ';
        }
        cout << endl;
    }

    using int_array = int[4];
    cout << "loop with type def" << endl;
    for (int_array *p = begin(ia); p != end(ia); p++) {
        for (int* q = begin(*p); q != end(*p); q++) {
            cout << *q << ' ';
        }
        cout << endl;
    }

}