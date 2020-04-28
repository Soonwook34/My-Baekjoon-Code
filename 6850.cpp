#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

vector<pair<int, int>> t_point;
vector<pair<int, int>> point;
stack<pair<int, int>> s;

void polarSort(int, int);
bool compare(pair<int, int>, pair<int, int>);
inline double getAngle(pair<int, int>);
inline double getDistance(pair<int, int>);
inline double getSignArea(pair<int, int>, pair<int, int>, pair<int, int>);
void makePolygon();
double getPolygonArea();
int main() {
	int n;
	scanf("%d", &n);

	t_point.resize(n);

	int start = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &t_point[i].first, &t_point[i].second);
		if (t_point[i].second < t_point[start].second)
			start = i;
		else if (t_point[i].second == t_point[start].second)
			if (t_point[i].first < t_point[start].first)
				start = i;
	}
	
	if (n < 3) {
		printf("0\n");
		return 0;
	}

	polarSort(n, start);

	makePolygon();

	printf("%d\n", (int)(getPolygonArea() / 50));

	return 0;
}

void polarSort(int n, int start) {
	//시작 점을 맨 앞으로
	pair<int, int> t;
	t = t_point[start];
	t_point[start] = t_point[0];
	t_point[0] = t;
	//시작 점을 (0, 0)으로 만들기 위해 모든 점 이동
	int x = t_point[0].first;
	int y = t_point[0].second;
	for (int i = 0; i < n; i++) {
		t_point[i].first -= x;
		t_point[i].second -= y;
	}
	//x축과의 각도로 정렬(시작 점이 원점이므로)
	sort(t_point.begin() + 1, t_point.end(), compare);

	point.push_back(t_point[0]);
	point.push_back(t_point[1]);
	int j = 1;
	for (int i = 2; i < n; i++) {
		if (getAngle(point[j]) == getAngle(t_point[i]))
			continue;
		point.push_back(t_point[i]);
		j++;
	}
}

bool compare(pair<int, int> a, pair<int, int> b) {
	double polar_a = getAngle(a);
	double polar_b = getAngle(b);
	if (polar_a < polar_b)
		return true;
	//각도가 같다면 거리 순으로 정렬
	else if (polar_a == polar_b)
		if (getDistance(a) >= getDistance(b))
			return true;
	return false;
}

inline double getAngle(pair<int, int> a) {
	return atan2(a.second, a.first);
}

inline double getDistance(pair<int, int> a) {
	return sqrt(a.first * a.first + a.second * a.second);
}

inline double getSignArea(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	return (a.first * b.second - a.second * b.first + b.first * c.second - b.second * c.first + c.first * a.second - c.second * a.first) / 2.0;
}

void makePolygon() {
	s.push(point[0]);
	s.push(point[1]);
	pair<int, int> a, b;
	for (int i = 2; i < point.size(); i++) {
		b = s.top();
		s.pop();
		a = s.top();

		if (getSignArea(a, b, point[i]) > 0) {
			s.push(b);
			s.push(point[i]);

		}
		else {
			s.push(point[i]);
			/*b = a;
			s.pop();
			a = s.top();
			if (getSignArea(a, b, point[i]) > 0) {
				s.push(b);
				s.push(point[i]);
			}
			else {
				s.push(point[i]);
			}*/
		}
	}
}

double getPolygonArea() {
	point.clear();
	point.resize(s.size());
	for (int i = s.size() - 1; i >= 0; i--) {
		point[i] = s.top();
		s.pop();
	}

	double area = 0;
	pair<int, int> a = point[0];
	pair<int, int> b = point[1];
	pair<int, int> c = point[1];

	for (int i = 2; i < point.size(); i++) {
		b = c;
		c = point[i];
		area += getSignArea(a, b, c);
	}

	return area;
}
