//
// Line Segment Group
// Problem: https://www.acmicpc.net/problem/2162
//

#include <cstdio>
#include <vector>

using namespace std;
const int MAX{3000};
int N, x1, y1, x2, y2;
int parent[MAX];
int group_size[MAX];

class Point {
public:
    Point() = default;

    Point(int _x, int _y) : x{_x}, y{_y} {}

    Point operator-(const Point &rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }

    int x, y;
};

class segment {
public:
    segment(int x1, int y1, int x2, int y2) {
        p1.x = x1;
        p1.y = y1;
        p2.x = x2;
        p2.y = y2;
    }

    Point p1, p2;
};

vector<segment> segments;

int direction(const Point &pi, const Point &pj, const Point &pk) {
    Point pji = pj - pi;
    Point pki = pk - pi;
    return (pki.x * pji.y - pji.x * pki.y);
}

bool on_segment(const Point &pi, const Point &pj, const Point &pk) {
    return (min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x) && min(pi.y, pj.y) <= pk.y && pk.y <= max(pi.y, pj.y));
}

bool segments_intersect(const segment &s1, const segment &s2) {
    int d1 = direction(s2.p1, s2.p2, s1.p1);
    int d2 = direction(s2.p1, s2.p2, s1.p2);
    int d3 = direction(s1.p1, s1.p2, s2.p1);
    int d4 = direction(s1.p1, s1.p2, s2.p2);

    if (((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0)) && ((d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0))) return true;
    else if (d1 == 0 && on_segment(s2.p1, s2.p2, s1.p1)) return true;
    else if (d2 == 0 && on_segment(s2.p1, s2.p2, s1.p2)) return true;
    else if (d3 == 0 && on_segment(s1.p1, s1.p2, s2.p1)) return true;
    else if (d4 == 0 && on_segment(s1.p1, s1.p2, s2.p2)) return true;

    return false;
}

int find_root(int curr) {
    if (parent[curr] == curr) {
        return curr;
    }
    int root = find_root(parent[curr]);
    parent[curr] = root;
    return root;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        segments.emplace_back(x1, y1, x2, y2);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (segments_intersect(segments[i], segments[j])) {
                int ri = find_root(i);
                int rj = find_root(j);
                if (ri != rj) {
                    parent[rj] = ri;
                }
            }
        }
    }

    int group_count{0};
    for (int i = 0; i < N; i++) {
        if (i == parent[i]) group_count += 1;
    }

    int most_freq{0};
    for (int i = 0; i < N; i++) {
        int root = find_root(i);
        group_size[root] += 1;
        if (most_freq < group_size[root]) {
            most_freq = group_size[root];
        }
    }
    printf("%d\n%d", group_count, most_freq);

    return 0;
}