#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
#define DEBUG 1
struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};


typedef long long int64;
struct Line {
  int a, b, c;
};
bool operator<(Line const&  l1, Line const &l2)
{
  if (l1.a != l2.a) {
    return l1.a < l2.a;
  }
  if (l1.b != l2.b) {
    return l1.b < l2.b;
  }
  return l1.c < l2.c;
}
bool operator<(Point const&  p1, Point const &p2)
{
  if (p1.x < p2.x) {
    return true;
  }
  
  return p1.y < p2.y;
}
class Solution {
public:
    Line getLine(const Point& l1, const Point& l2) {
        if (DEBUG) cout << l1.x << ", " << l1.y << " | " << l2.x << ", " << l2.y << endl;

        int64 dx = (int64)l1.x - l2.x;
        int64 dy = (int64)l1.y - l2.y;
        int64 g = _gcd(abs(dx), abs(dy));
        Line l;
        l.a = dy / g;
        l.b = - dx / g;
        l.c = l.a * l1.x + l.b * l1.y;
        Line ll;
        ll.a = -l.a;
        ll.b = -l.b;
        ll.c = -l.c;
        if (ll < l) {
          cout << "HAHAHA\n";
          if (l < ll) {
            cout << "WTF!!\n";
          }
          l = ll;
        }
        if (DEBUG) cout << l.a << ", " << l.b << ", " << l.c << endl;
        return l;
        return std::move(l);
    }
    
    int maxPoints(vector<Point> &points) {
        int r = 0, n = points.size();
        if (n <= 2) {
            return n;
        }
        
        map<Line, set<int>> lines;
        int64 maxCount = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    continue;
                }
                Line l = getLine(points[i], points[j]);
                lines[l].insert(i);
                lines[l].insert(j);
                if (lines[l].size() > maxCount) {
                    if (DEBUG) cout << "maxCount: " << lines[l].size() << ", " << i << ", " << j << endl;
                    maxCount = lines[l].size();
                }
            }
        }
        
        if (maxCount == 0) {
          return points.size();    
        }
        
        return maxCount;
    }
    
    int64 _gcd(int64 n, int64 m){
        return m == 0 ? n : _gcd(m, n % m);
    }
};

#define TEST(x) (cout << #x << ": " << s.maxPoints(x) << endl)

int main() {
	Solution s;
	vector<Point> t1 = {
		{1, 1},
		{-1, -1},
		{2, 2}
	};
  TEST(t1);
	vector<Point> t2 = {
		{-4, 1},
		{-7, 7},
		{-1, 5},
    {9, -25}
	};
  TEST(t2);
	vector<Point> t3 = {
		{0, 0},
		{1, 1},
		{0, 0}
	};
  TEST(t3);
	vector<Point> t4 = {
		{2, 3},
		{3, 3},
		{-5, 3}
	};
  TEST(t4);
  vector<Point> t5 = {
    {0,9},{138,429},{115,359},{115,359},{-30,-102},{230,709},{-150,-686},{-135,-613},{-60,-248},{-161,-481},{207,639},{23,79},{-230,-691},{-115,-341},{92,289},{60,336},{-105,-467},{135,701},{-90,-394},{-184,-551},{150,774}
  };
  TEST(t5);
  vector<Point> t6 = {
{-230,324},{-291,141},{34,-2},{80,22},{-28,-134},{40,-23},{-72,-149},{0,-17},{32,-32},{-207,288},{7,32},{-5,0},{-161,216},{-48,-122},{-3,39},{-40,-113},{115,-216},{-112,-464},{-72,-149},{-32,-104},{12,42},{-22,19},{-6,-21},{-48,-122},{161,-288},{16,11},{39,23},{39,30},{873,-111}
  };
  TEST(t6);
  vector<Point> t7 = {
    {0, 0}, {0, 0}, {0, 0}
  };
  TEST(t7);
  vector<Point> t8 = {
    {1, 1}, {1, 1}, {1, 1}
  };
  TEST(t8);
  vector<Point> t9 = {
    {0, 0}, {0, 0}, {0, 0},
    {1, 1}, {1, 1}, {1, 1}, {1, 1},
    {1, -1}, {1, -1}, {1, -1}, {-1, 1}, {-1, 1}
  };
  TEST(t9);
  vector<Point> t10 = {
    {3, 10},
    {0, 2},
    {0, 2},
    {3, 10}
  };
  TEST(t10);
}
