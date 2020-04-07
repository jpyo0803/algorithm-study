#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

unordered_map<string, int> count1;
unordered_map<string, int> count2;


int main() {
    count1.clear();
    count2.clear();

    ifstream freq1("documents/document1.txt");
    if (freq1.fail()) {
        cout << "failed to open document1.txt\n";
        exit(-1);
    }
    ifstream freq2("documents/document2.txt");
    if (freq2.fail()) {
        cout << "failed to open document2.txt\n";
        exit(-1);
    }

    string str;

    int total_count1 = 0;
    int total_count2 = 0;

    while (!freq1.eof()) {
        freq1 >> str;
        count1[str] += 1;
        total_count1 += 1;
    }
    while (!freq2.eof()) {
        freq2 >> str;
        count2[str] += 1;
        total_count2 += 1;
    }

    double res_dp = 0;
    for (auto content : count1) {
        int x = content.second;
        int y = count2[content.first];
        if (x > 0 && y > 0) {
            res_dp += x * y;
        }
    }

    double tc = total_count1 * total_count2;
    
    double dd = acos(res_dp / tc);
    dd = dd / 3.141592 * 180.0;
    cout << dd << endl;

    return 0;
}