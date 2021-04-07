//
// 회사에 있는 사람
// Link: https://www.acmicpc.net/problem/7785
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

int N;
set<string> company;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	string name, status;
	for (int n = 0; n < N; n++) {
		cin >> name >> status;
		if (status == "enter") company.insert(name);
		else company.erase(name);
	}

	for (auto rev_it = company.rbegin(); rev_it != company.rend(); rev_it++) {
		cout << *rev_it << "\n";
	}

	return 0;
}
