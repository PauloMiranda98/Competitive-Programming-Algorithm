#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

struct point{
    double x, y;
    point(){}
    point(double _x, double _y){
      x = _x;
      y = _y;
    }
    point operator+(const point &oth){
      return point(x + oth.x, y + oth.y);
    }
    point operator-(const point &oth){
      return point(x - oth.x, y - oth.y);
    }
    
    bool operator==(const point &oth){
      return (x == oth.x) && (y == oth.y);
    }
    
};

point sum(point a, point b){
  point ret;
  ret.x = a.x + b.x;
  ret.y = a.y + b.y;
  return ret;
}

point neg(point a){
  point ret;
  ret.x = -a.x;
  ret.y = -a.y;
  return ret;
}

point medio(point a, point b){
  point ret;
  ret.x = (a.x + b.x)/2;
  ret.y = (a.y + b.y)/2;
  return ret;
}


double dot(point a, point b){
  return a.x*b.x + a.y*b.y;
}

double dist(point a, point b){
  point c = a - b;
  return sqrt(c.x*c.x + c.y*c.y);
}

double cross(point a, point b){
  return a.x*b.y - a.y*b.x;
}
point p[8];

int main() {
	
	
	for(int i=1; i<=7; i++){
		cin >> p[i].x >> p[i].y;			
	}

	//caso 1	
	point p2 = sum(p[2], neg(p[1]));
	point p3 = sum(p[3], neg(p[1]));
	
	double res = dot(p2, p3)/( sqrt(dot(p2,p2)) * sqrt(dot(p3,p3)) );
	
	double angulo = acos(res);
	
	if(angulo >= (M_PI_2)){
//		cout << "Caso 1" << endl;
	
		cout << "N" << endl;
		return 0;	
	}
	
	//Caso 2	
	if(dist(p[1],p[2]) != dist(p[1], p[3])){
		
//		cout << "Caso 2" << endl;
		cout << "N" << endl;
		return 0;	
	}
	
	//Caso 3
	res = cross(p[2], p[3]) + cross(p[3], p[4]) + cross(p[4], p[2]);
	if(res != 0.0){
//		cout << "Caso 3.1" << endl;
		cout << "N" << endl;
		return 0;	
	}
	
	res = cross(p[2], p[3]) + cross(p[3], p[5]) + cross(p[5], p[2]);
	if(res != 0.0){
//		cout << "Caso 3.2" << endl;
		cout << "N" << endl;
		return 0;	
	}
	
	//Caso 4
	
	if( !(medio(p[2],p[3]) == medio(p[4], p[5])) ){
//		cout << "Caso 4" << endl;
		cout << "N" << endl;
		return 0;	
		
	}

	//Caso 5	
	if( (dist(p[2],p[3]) <= dist(p[4], p[5])) ){
//		cout << "Caso 5" << endl;
		cout << "N" << endl;
		return 0;	
		
	}
	
	//caso 6
	
	point dp = p[3] - p[2];
	point dp2 = p[4] - p[6];
	point dp3 = p[5] - p[7];
	
	if(dp.x  == 0){ // 90 graus
		
		if( (dp2.x == 0) || (dp3.x == 0) ){
//			cout << "Caso 6.1" << endl;
			cout << "N" << endl;
			return 0;				
		}
		
		if( (dp2.y != 0) || (dp2.y != 0) ){
//			cout << "Caso 6.2" << endl;
			cout << "N" << endl;
			return 0;							
		}
		
	}else{
		
		if( (dp.y == 0)){
			if( ((dp2.x != 0) || (dp3.x != 0)) ){			
//				cout << "Caso 6.3" << endl;
				cout << "N" << endl;
				return 0;				
			}
		}else{
			if( ((dp2.x == 0) || (dp3.x == 0)) ){			
//				cout << "Caso 6.4" << endl;
				cout << "N" << endl;
				return 0;				
			}
			
			if( (((dp.y*dp2.y)/(dp.x*dp2.x)) != -1) || ( ((dp.y*dp3.y)/(dp.x*dp3.x)) != -1) ){
//				cout << "Caso 6.5" << endl;
				cout << "N" << endl;
				return 0;				
			}
			
		}
					
	}

	//Caso 7	
	if( (dist(p[4],p[6]) != dist(p[5], p[7])) ){
//		cout << "Caso 7" << endl;
		cout << "N" << endl;
		return 0;	
		
	}
	
	//Caso 8	
	if( dist(p[1], medio(p[6], p[7])) <= dist(p[1],medio(p[4], p[5])) ){
//		cout << "Caso 8" << endl;
		cout << "N" << endl;
		return 0;	
		
	}
	
	cout << "S" << endl;
	return 0;
	
}
