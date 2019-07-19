#include <bits/stdc++.h>

using namespace std;


const double PI = acos(-1);
const double EPS = 1e-9;

typedef vector<int> BigNum;
typedef long long ll;
const int base = 1000*1000*1000;

BigNum sum(BigNum &a, BigNum &b){
	BigNum c;
	int carry = 0, n = max(a.size(), b.size());
	c.resize(n);
	for(int i=0, ai, bi; i<n; i++){
		ai = i < (int)a.size() ? a[i] : 0;
		bi = i < (int)b.size() ? b[i] : 0;
		c[i] = carry + ai + bi;
		carry = c[i] / base;
		c[i] %= base;
	}
	
	if(carry > 0)
		c.push_back(carry);
	while( (c.size() > 1u) and (c.back() == 0) )
		c.pop_back();
	return c;
}

BigNum operator+(BigNum a, BigNum b){
	BigNum c;
	int carry = 0, n = max(a.size(), b.size());
	c.resize(n);
	for(int i=0, ai, bi; i<n; i++){
		ai = i < (int)a.size() ? a[i] : 0;
		bi = i < (int)b.size() ? b[i] : 0;
		c[i] = carry + ai + bi;
		carry = c[i] / base;
		c[i] %= base;
	}
	
	if(carry > 0)
		c.push_back(carry);
	while( (c.size() > 1u) and (c.back() == 0) )
		c.pop_back();
	return c;
}

string BigToStr(BigNum a){
	string s;
	char buffer[11]; 
	sprintf(buffer, "%d", a.empty()? 0: a.back());
	s +=buffer;
	for(int i=a.size()-2; i>=0; i--){
		sprintf(buffer, "%09d", a[i]);
		s +=buffer;
	}
	return s;
}

BigNum dp[30010*113];
BigNum b0;
BigNum b1;
int v[120];
//PI = 355/113
int main() {		
	b0.push_back(0);
	b1.push_back(1);

	for(int i=0; i<4*113; i++){
		dp[i] = b1;		
	}
	
	for(int i=4*113; i<=30000*113; i++){
		dp[i] = dp[i-113] + dp[i-355];		
	}


	while(true){
		int n;
		cin >> n;
		if(n < 0)
			break;
			
		string s = BigToStr(dp[n*113]); 
		int i=0;
		
		for(; (i+50) < (int)s.size(); i+= 50){
			cout << s.substr(i, 50) << endl;
		}
		cout << s.substr(i) << endl;
	
	}

	return 0;	
}
