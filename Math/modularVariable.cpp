#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

//Author: Codeforces -> neal
const int MOD = 1e9 + 7;

struct mod_int {
    int val;
 
    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
 
        if (v >= MOD)
            v %= MOD;
 
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    mod_int& operator*=(const mod_int &other) {
        val = (uint64_t) val * other.val % MOD;
        return *this;
    }
 
    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }
 
    friend mod_int operator+(const mod_int &a, const mod_int &b) {
        return mod_int(a) += b;
    }
 
    friend mod_int operator-(const mod_int &a, const mod_int &b) {
        return mod_int(a) -= b;
    }
 
    friend mod_int operator*(const mod_int &a, const mod_int &b) {
        return mod_int(a) *= b;
    }
 
    friend mod_int operator/(const mod_int &a, const mod_int &b) {
        return mod_int(a) /= b;
    }
 
    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    mod_int operator++(int) {
        mod_int before = *this;
        ++*this;
        return before;
    }
 
    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    mod_int operator--(int) {
        mod_int before = *this;
        --*this;
        return before;
    }
 
    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const mod_int &other) const {
        return val == other.val;
    }
 
    bool operator!=(const mod_int &other) const {
        return val != other.val;
    }
 
    mod_int inv() const {
        return mod_inv(val);
    }
 
    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	mod_int a, b, c;
	cin >> a.val >> b.val >> c.val;
	
	mod_int r;
	r = (((a.pow(2)) + (b.pow(2)) + (c.pow(2)))*5 + 3)/2; 

	cout << (int)r << endl;
		
	return 0;
}
