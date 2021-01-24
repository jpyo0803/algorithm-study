#include <cstdio>

using namespace std;

int main() {
	int answer = 0;
	for (int i = 0; i < 8; i++) {
		char line[9];
		scanf("%s", line);
		bool flip = (i % 2 == 0);
		for (int j = 0; j < 8; j++) {
			if (line[j] == 'F' && flip) answer++;
			flip = !flip;
		}
	}
	printf("%d\n", answer);
	return 0;
}
