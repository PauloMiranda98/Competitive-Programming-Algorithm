#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

struct complex_t {
	double a {0.0}, b {0.0};
	complex_t(){
	}
	complex_t(double na) : a{na}{}
	
	complex_t(double na, double nb) : a{na}, b{nb} {}
	
	const complex_t operator+(const complex_t &c) const {
		return complex_t(a + c.a, b + c.b);
	}
	const complex_t operator-(const complex_t &c) const {
		return complex_t(a - c.a, b - c.b);
	}
	const complex_t operator*(const complex_t &c) const {
		return complex_t(a*c.a - b*c.b, a*c.b + b*c.a);
	}
	const complex_t operator/(const int &c) const {
		return complex_t(a/c, b/c);
	}
};

//using cd = complex<double>;
using cd = complex_t;

const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w = w * wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a){
            x = x / n;
        }
    }
}

vector<ll> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
   
    int n = 1;
    while(n < int(a.size() + b.size()) ) 
        n <<= 1;
    
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
  
    for (int i = 0; i < n; i++)
        fa[i] = fa[i]*fb[i];
  
    fft(fa, true);

    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].a);
        
    return result;
}

vector<ll> scalarProdut(vector<int> a, vector<int> b) {
	int na = a.size();
	int nb = b.size();
	reverse(a.begin(), a.end());
	a.resize(2*na, 0);

    b.resize(2*nb, 0);
	for(int i=0; i < nb; i++)
		b[nb + i] = b[i];
	
	vector<ll> ans = multiply(a, b);
	for(int i=0; i<nb; i++)
		ans[i] = ans[nb-1+i];

	ans.resize(nb);

    return ans;
}


int getID(char c){
	if( (c>='a') and (c<='z') )
		return c - 'a';

	return c-'A'+26;
}

vector<int> stringMatching(string t, string p){
	int nt = t.size();
	int np = p.size();
	
    vector<cd> fa(nt), fb(np);
	
    for(int i=0; i<nt; i++){
		double apha = (2*PI*getID(t[i]))/26; //(2*PI*getID(t[i]))/52;
		fa[i] = cd(cos(apha), sin(apha));
	}
	reverse(p.begin(), p.end());
    for(int i=0; i<np; i++){
		double apha = (2*PI*getID(p[i]))/26; //(2*PI*getID(p[np-1-i]))/52;
		fb[i] = cd(cos(apha), -sin(apha));
	}
   
    int n = 1;
    while(n < int(nt + np) ) 
        n <<= 1;
    
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
  
    for (int i = 0; i < n; i++)
        fa[i] = fa[i]*fb[i];
  
    fft(fa, true);

    vector<int> result(nt - np+1);
    for (int i = 0; i < (nt - np+1); i++){
        result[i] = int(fa[np-1+i].a + 1e-6);
	}
    return result;
}

vector<int> stringMatchingWithWildCards(string t, string p){
	int nt = t.size();
	int np = p.size();
	
    vector<cd> fa(nt), fb(np);
	
    for(int i=0; i<nt; i++){
		double apha = (2*PI*getID(t[i]))/26; //(2*PI*getID(t[i]))/52;
		fa[i] = cd(cos(apha), sin(apha));
	}
	reverse(p.begin(), p.end());
    for(int i=0; i<np; i++){
		if(p[i] == '*'){
			fb[i] = cd(0, 0);
		}else{
			double apha = (2*PI*getID(p[i]))/26; //(2*PI*getID(p[np-1-i]))/52;
			fb[i] = cd(cos(apha), -sin(apha));
		}
	}
   
    int n = 1;
    while(n < int(nt + np) ) 
        n <<= 1;
    
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
  
    for(int i = 0; i < n; i++)
        fa[i] = fa[i]*fb[i];
  
    fft(fa, true);

    vector<int> result(nt - np + 1);
    for (int i = 0; i < (nt - np + 1); i++){
        result[i] = int(fa[np-1+i].a + 1e-6);
    }
        
    return result;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	vector<int> a;
	vector<int> b;
		
	int na, nb;
	cin >> na >> nb;
	a.resize(na);
	b.resize(nb);
	
	for(int i=0; i<na; i++)
		cin >> a[i];
	for(int i=0; i<na; i++)
		cin >> b[i];
	
	vector<ll> ans = multiply(a, b);
	
	cout << ans[0];
	for(int i=1; i < (int)ans.size(); i++)
		cout << " " << ans[i];
	cout << endl;	
	
}
