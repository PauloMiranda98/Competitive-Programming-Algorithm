#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

typedef long long llm_t;

llm_t extGcd(llm_t a, llm_t b, llm_t& x, llm_t& y) {
	if(b == 0){
		x = 1; y = 0; return a;
	}
	else{
		llm_t g = extGcd(b, a % b, y, x);
		y -= (a / b) * x; 
		return g;
	}
}

llm_t extGcdPositive(llm_t a, llm_t b, llm_t& x, llm_t& y, llm_t ans){
	llm_t g = extGcd(a, b, x, y);
	
	if(ans%g != 0)
		return g;	
	x *= ans/g;
	y *= ans/g;

	if(x > 0){ //Quando quero menor x positivo possivel
		llm_t k = ((x)*g + b-1)/b; 

		x -= k*(b/g);
		y -= (-k)*(a/g);
	}
	 
	if(x < 0){
		llm_t k = ((-x)*g + b-1)/b; 

		x += k*(b/g);
		y += (-k)*(a/g);
	}
	
	if(y < 0){
		llm_t k = ((-y)*g + a-1)/a; 

		x += (-k)*(b/g);
		y += k*(a/g);
	}
	
	return g;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll a, b, c, x, y;
	
	cin >> a >> b >> c;
	
	ll g = extGcd(a, b, x, y);
	cout << "(" << a << ")*(" << x << ") + " << "(" << b << ")*(" << y << ") = " << g << endl;

	g = extGcdPositive(a, b, x, y, c);	
	cout << "(" << a << ")*(" << x << ") + " << "(" << b << ")*(" << y << ") = " << c << endl;
		
	return 0;
}
