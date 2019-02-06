#include <bits/stdc++.h>

using namespace std;

typedef long long g_t;

struct Point{
	g_t x, y;
	
	Point(){
		x = y = 0;
	}

	Point(g_t _x, g_t _y){
		x = _x;
		y = _y;
	}
    Point operator+(const Point &oth){
      return Point(x + oth.x, y + oth.y);
    }
    Point operator-(const Point &oth){
      return Point(x - oth.x, y - oth.y);
    }	
};

typedef pair<Point, Point> Line;

Point sum(Point a, Point b){
  Point ret;
  ret.x = a.x + b.x;
  ret.y = a.y + b.y;
  return ret;
}

Point neg(Point a){
  Point ret;
  
  ret.x = -a.x;
  ret.y = -a.y;
  return ret;
}

g_t dot(Point a, Point b){ // Scalar product: a*b = |a|*|b|*cos(ang(a_b))
  return a.x*b.x + a.y*b.y;
}
/*
if(dot > 0)
	ang < 90
if(dot == 0)
	ang = 90
if(dot < 0)
	ang > 90
*/


//The vector product gives us the area of the parallelogram with sides a and b
g_t cross(Point a, Point b){ // Vector product: axb = |a|*|b|*sin(ang(a_b))
  return a.x*b.y - a.y*b.x;
}
/*
if(cross < 0)
	ang < 180
if(dot == 0)
	ang = 180
if(dot > 0)
	ang > 180
*/

double dist(Point a, Point b){
  Point c = a - b;
  return sqrt(c.x*c.x + c.y*c.y);
}

double dist(Point a, Line b){
  double crs = cross(Point(a - b.first), Point(b.second - b.first));
  return abs(crs/dist(b.first, b.second));
}

double area(vector <Point> p){
  double ret = 0;
  
  for(int i = 2; i < int(p.size()); i++)
    ret += cross(p[i] - p[0], p[i - 1] - p[0])/2.0;
  
  return abs(ret);
}

//takes 3 numbers and returns if they form a convex or concave angle.
bool ccw(Point a, Point b, Point c){
  double ret = cross(b - a, c - b);
  return ret < 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Point a, b;

	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	
	cout << dot(a, b) << endl; 
	cout << cross(a, b) << endl; 
	cout << dist(a, b) << endl; 
		
	return 0;
}
