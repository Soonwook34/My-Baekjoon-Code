#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int n;
int start;						//시작 점의 인덱스
vector<pair<int, int>> point;	//후보가 되는 점들의 집합
stack<pair<int, int>> s;		//문제의 조건을 만족하는 다각형을 만들 점들의 집합

void polarSort();																//점들을 시작 점과의 각도 올림차순으로 정렬하는 함수
bool compare(pair<int, int>, pair<int, int>);									//polaSort()에서 각도 비교 함수
inline double getAngle(pair<int, int>, pair<int, int>);							//기준 점 x와 점 a의 각도를 구하는 getAngle(a, x)
inline double getDistance(pair<int, int>, pair<int, int>);						//점 a와 x의 거리를 구하는 getDistance(a, x)
inline double getSignArea(pair<int, int>, pair<int, int>, pair<int, int>);		//점 a, b, c로 이루어진 삼각형의 sign area를 구하는 getSignArea(a, b, c)
void makePolygon();																//주어진 점들로 가장 넓은 다각형을 만들어 그 점들을 스택 s에 저장하는 함수
bool isPointValid(pair<int, int>);												//주어진 점으로 스택 s의 마지막으로 들어간 점이 가장 넓은 다각형을 만드는데 필요한지 알려주는 함수
double getPolygonArea();														//스택 s에 주어진 점들로 만들어진 다각형의 넓이를 구하는 함수

int main() {
	scanf("%d", &n);
	//점 입력 받기
	point.resize(n);
	start = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &point[i].first, &point[i].second);
		//y가 가장 작으면서 x가 가장 작은 점(시작 점) 찾기
		if (point[i].second < point[start].second)
			start = i;
		else if (point[i].second == point[start].second)
			if (point[i].first < point[start].first)
				start = i;
	}
	//점이 3개 미만일 경우 예외처리
	if (n < 3) {
		printf("0\n");
		return 0;
	}

	polarSort();

	makePolygon();

	int area = (int)getPolygonArea();
	printf("%d\n", area/50);

	return 0;
}

void polarSort() {
	//시작 점을 가장 앞으로 당김
	pair<int, int> x = point[start];
	point[start] = point[0];
	point[0] = x;
	//정렬
	sort(point.begin() + 1, point.end(), compare);

	//시작 점으로부터 각도가 같은 점들 중 시작 점과 가장 멀리 있는 점만 남긴다
	int j = 1;
	for (int i = 2; i < n; i++) {
		if (getAngle(point[i], x) == getAngle(point[j], x))
			continue;
		j++;
		point[j] = point[i];
	}
	point.erase(point.begin() + j + 1, point.end());
	n = point.size();

	return;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	pair<int, int> x = point[0];
	double angle_a = getAngle(a, x);
	double angle_b = getAngle(b, x);
	//각도 오름차순으로 정렬
	if (angle_a < angle_b)
		return true;
	//각도가 같다면 거리 내림차순으로 정렬
	else if (angle_a == angle_b)
		if (getDistance(a, x) >= getDistance(b, x))
			return true;
	return false;
}

inline double getAngle(pair<int, int> a, pair<int, int> x) {
	return atan2(a.second - x.second, a.first - x.first);
}

inline double getDistance(pair<int, int> a, pair<int, int> x) {
	return sqrt((a.first - x.first) * (a.first - x.first) + (a.second - x.second) * (a.second - x.second));
}

inline double getSignArea(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	return (a.first * b.second - a.second * b.first + b.first * c.second - b.second * c.first + c.first * a.second - c.second * a.first) / 2.0;
}

void makePolygon() {
	s.push(point[0]);
	s.push(point[1]);
	for (int i = 2; i < n; i++) {
		//다음 점이 맞으면
		if (isPointValid(point[i])) {
			s.push(point[i]);
		}
		//다음 점이 아니면
		else {
			//조건을 만족할때까지 스택에서 점 제거
			while (s.size() >= 2 && !isPointValid(point[i])) {
				s.pop();
			}
			s.push(point[i]);
		}
	}
}

bool isPointValid(pair<int, int> c) {
	//스택에서 a, b 가져오기 (스택은 원상복구)
	pair<int, int> a, b;
	b = s.top();
	s.pop();
	a = s.top();
	s.push(b);
	//sign area가 양수인지 여부를 리턴
	return getSignArea(a, b, c) > 0;
}

double getPolygonArea() {
	//스택 s의 점들을 point로 옮긴다
	point.clear();
	point.resize(s.size());
	for (int i = s.size() - 1; i >= 0; i--) {
		point[i] = s.top();
		s.pop();
	}

	//넓이 구하기
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
