//
// Set
// Problem: https://www.acmicpc.net/problem/11723
//

#include <cstdio>
#include <cstring>

using namespace std;
const int MAX{20};
int M, x;
bool set[MAX + 1];
int count{0};
char str[10];

int main() {
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%s %d", str, &x);
        if (strcmp(str, "add") == 0) {
            if (!set[x]) {
                set[x] = true;
                count += 1;
            }
        } else if (strcmp(str, "remove") == 0) {
            if (set[x]) {
                set[x] = false;
                count -= 1;
            }
        } else if (strcmp(str, "check") == 0) {
            printf("%d\n", set[x]);
        } else if (strcmp(str, "toggle") == 0) {
            if (set[x]) {
                set[x] = false;
                count -= 1;
            } else {
                set[x] = true;
                count += 1;
            }
        } else if (strcmp(str, "all") == 0) {
            for (int i = 1; i <= 20; i++) {
                set[i] = true;
            }
            count = 20;
        } else if (strcmp(str, "empty") == 0) {
            for (int i = 1; i <= 20; i++) {
                set[i] = false;
            }
            count = 0;
        }
    }
    return 0;
}