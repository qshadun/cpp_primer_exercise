#include<string>
#include<vector>
#include<iostream>


using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::toupper;


int main() {
    vector<int> grades;
    vector<int> scores(11, 0);
    int grade;
    while (cin >> grade) {
        grades.push_back(grade);
        scores[grade/10] ++;
    }
    for (auto g: grades) {
        cout << g << " ";
    }
    cout << endl;

    for (auto sc: scores) {
        cout << sc << " ";
    }
    cout << endl;

    vector<int> alt_scores(11, 0);
    for (auto it = grades.begin(); it != grades.end(); it++) {
        int g = *it;
        *(alt_scores.begin() + g / 10) +=1;
    }
    cout << "size of alt_scores: " << alt_scores.size() << endl;
    for (auto sc: alt_scores) {
        cout << sc << " ";
    }
    cout << endl;
}