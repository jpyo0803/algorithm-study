//
// 소수 경로 
// Link: https://www.acmicpc.net/problem/1963
//

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int T, ipn, tpn;

bool pn_table[10000];
bool visited[10000];

void ErastothenesSieve() {
	for (int i = 2; i < 10000; i++) {
		if (pn_table[i]) continue;
		for (int j = i + i; j < 10000; j += i) {
			pn_table[j] = true;
		}
	}
}

int DigitChange(int number, int where, int to) {
	string nstr = to_string(number);
	nstr[where] = to + '0';	
	return stod(nstr);
}

int Bfs(int ipn, int tpn) {
	for (int i = 0; i < 10000; i++) visited[i] = false;
	vector<int> frontier, next;
	frontier.push_back(ipn);
	visited[ipn] = true;
	int level = 0;

	while (!frontier.empty()) {
		next.clear();
		for (auto cpn : frontier) {
			if (cpn == tpn) return level;
			for (int i = 0; i < 4; i++) {
				if (i == 0) {
					for (int j = 1; j < 10; j++) {
						int npn = DigitChange(cpn, i, j);
						if (!visited[npn] && !pn_table[npn]) {
							next.push_back(npn);
							visited[npn] = true;
						}
					}
				} else {
					for (int j = 0; j < 10; j++) {
						int npn = DigitChange(cpn, i, j);
						if (!visited[npn] && !pn_table[npn]) {
							next.push_back(npn);
							visited[npn] = true;
						}
					}
				}
			}
		}
		swap(frontier, next);
		level++;
	}
	return -1;
}

int main() {
	ErastothenesSieve();
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d%d", &ipn, &tpn);
		int result = Bfs(ipn, tpn);
		if (result == -1) printf("Impossible\n");
		else printf("%d\n", result);
	}
	return 0;
}
