#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

typedef long long llm_t;
const llm_t MOD = 1000000007LL;

struct LLM{
	llm_t value;
	LLM(){
		value = 0;
	}
	LLM(llm_t x){
		value = x%MOD;
	}
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
		 
	llm_t modInv(llm_t a, llm_t m) {
		llm_t x, y;
		extGcd(a, m, x, y);
		return (x % m + m) % m;
	}	

	llm_t modDiv(llm_t a, llm_t b, llm_t m) {
		return ((a % m) * modInv(b, m)) % m;
	}
	
	llm_t modMul(llm_t a, llm_t b, llm_t m) {
		/*llm_t x = 0, y = a % m;
		while (b > 0) {
			if (b % 2 == 1) x = (x + y) % m;
			y = (y * 2) % m; b /= 2;
		}
		return x % m;*/
		return (a*b)%m;
	}
	llm_t modPow(llm_t a, llm_t b, llm_t m) {
		if(b == 0)
			return 1LL;
		if(b == 1)
			return a;
		llm_t x = modPow(a, b/2, m);
		x = modMul(x, x, m);		
		if(b&1)
			x = modMul(x, a, m);
		return x % m;
	}	
	LLM operator^(const LLM& other){
		LLM _ans;
		_ans.value = modPow(value, other.value, MOD);
		return _ans;
	} 
	LLM operator^(const llm_t& other){
		LLM _ans;
		_ans.value = modPow(value, other, MOD);
		return _ans;
	} 
	LLM operator*(const LLM& other){
		LLM _ans;
		_ans.value = modMul(value, other.value, MOD);
		return _ans;
	} 
	LLM operator*(const llm_t& other){
		LLM _ans;
		_ans.value = modMul(value, other, MOD);
		return _ans;
	} 
	LLM operator/(const LLM& other){
		LLM _ans;
		_ans.value = modDiv(value, other.value, MOD);
		return _ans;
	} 
	LLM operator/(const llm_t& other){
		LLM _ans;
		_ans.value = modDiv(value, other, MOD);
		return _ans;
	} 
	LLM operator+(const LLM& other){
		LLM _ans;
		_ans.value = (value + other.value);
		if(_ans.value >= MOD)
			_ans.value -= MOD;
		return _ans;
	} 
	LLM operator+(const llm_t& other){
		LLM _ans;
		_ans.value = (value + other);
		if(_ans.value >= MOD)
			_ans.value -= MOD;
		return _ans;
	} 
	LLM operator-(const LLM& other){
		LLM _ans;
		_ans.value = ((value - other.value)%MOD + MOD)%MOD;
		return _ans;
	} 
	LLM operator-(const llm_t& other){
		LLM _ans;
		_ans.value = ((value - other)%MOD + MOD)%MOD;
		return _ans;
	} 	
	void operator=(const LLM& other){
		value = other.value;
	} 
	void operator=(const llm_t& other){
		value = (other)%MOD;
	} 	
};


ll extGcd(ll a, ll b, ll& x, ll& y) {
	if(b == 0){
		x = 1; y = 0; return a;
	}else{
		ll g = extGcd(b, a % b, y, x);
		y -= (a / b) * x; 
		return g;
	}
}
	 
ll modInv(ll a, ll m) {
	ll x, y;
	extGcd(a, m, x, y);

	x = x%m;
	if(x < 0)
		x += m;
	
	return x;
}	

//const ll MOD = 1000000007LL;

ll fmod(ll b, ll exp = MOD-2LL){
    ll ans = 1LL;
    while(exp){
		if(exp & 1LL)
			ans = (ans*b)%MOD;
		b = (b*b)%MOD;
		exp /= 2ll;
    }
    return ans;
}

inline ll modInvPow(ll a) {
	return fmod(a, MOD-2LL);
}	

inline ll modDiv(ll a, ll b) {
	return (a * modInvPow(b)) % MOD;
}

inline ll modMul(ll a, ll b) {
	return (a * b) % MOD;
}

inline ll modSum(ll a, ll b) {
	ll x = a+b;

	if(x >= MOD)
		return x-MOD;
	else
		return x;
}

inline ll modSub(ll a, ll b) {
	ll x = a-b;

	if(x < 0) 
		return x+MOD;
	else
		return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	LLM a, b, c;
	cin >> a.value >> b.value >> c.value;
	
	LLM r;
	r = (((a^2) + (b^2) + (c^2))*5 + 3)/2; 
	cout << r.value << endl;
		
	return 0;
}
