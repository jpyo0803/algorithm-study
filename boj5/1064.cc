//
// 평행사변형
// Link: https://www.acmicpc.net/problem/1064
//

#include <iostream>
#include <math.h>

using namespace std;

struct Point {
	int x, y;
	Point(int xx, int yy) : x(xx), y(yy) {}
};

double Max(double x, double y) { return x < y ? y : x; }
double Min(double x, double y) { return x < y ? x : y; }

double Distance(const Point& A, const Point& B) {
	int dx = A.x - B.x;
	int dy = A.y - B.y;
	return sqrt(dx * dx + dy * dy);
}

bool AreTheyLine(const Point& A, const Point& B, const Point& C) {
	int dx1, dy1, dx2, dy2;
	dx1 = A.x - B.x;
	dy1 = A.y - B.y;
	dx2 = B.x - C.x;
	dy2 = B.y - C.y;
	return dy1 * dx2 == dy2 * dx1;
}

double Solve(const Point& A, const Point& B, const Point& C) {
	if (AreTheyLine(A, B, C)) return -1.0;

	double dist1 = Distance(A, B);
	double dist2 = Distance(B, C);
	double dist3 = Distance(A, C);

	double max_dule = 0.0;
	double min_dule = 999999999999999.9;

	max_dule = Max(dist1 + dist2, max_dule);
	min_dule = Min(dist1 + dist2, min_dule);
	
	max_dule = Max(dist1 + dist3, max_dule);
	min_dule = Min(dist1 + dist3, min_dule);

	max_dule = Max(dist2 + dist3, max_dule);
	min_dule = Min(dist2 + dist3, min_dule);

	return (max_dule - min_dule) * 2.0;
}

int main() {
	int x, y;
	cin >> x >> y;
	Point A(x, y);
	cin >> x >> y;
	Point B(x, y);
	cin >> x >> y;
	Point C(x, y);

	cout << fixed;
	std::cout.precision(15);
	std::cout << Solve(A, B, C) << std::endl;

	return 0;
}
