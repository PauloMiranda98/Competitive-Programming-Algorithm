#include <bits/stdc++.h>

#define F first
#define S second
#define EB emplace_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define all(x) x.begin(),x.end()
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
int ans[1010];
int n;
/*
int a1[1010]={0, 2, 1, 4, 5, 3}, a2[1010]={0, 3, 4, 1, 2, 5};

char get(int i, int j){
	if(a1[i] < a2[j])
		return '<';
	else if(a1[i] > a2[j])
		return '>';
	else 
		return '=';
}
*/
char get(int i, int j){
	cout << "? " << i << " " << j << endl;
	char c;
	cin >> c;
	return c;
}
void solve(vector<int> v1, vector<int> v2){
	if(v1.empty())
		return;
	shuffle(all(v2), rng);
	vector<int> l1, r1;
	vector<int> l2, r2;
	int ig;
	for(int x: v1){
		char c = get(x, v2.back());
		if(c == '<')
			l1.push_back(x);
		else if(c == '>')
			r1.push_back(x);
		else
			ig = x;
	}
	ans[ig] = v2.back();
	v2.pop_back();
	for(int x: v2){
		char c = get(ig, x);
		if(c == '>')
			l2.push_back(x);
		else if(c == '<')
			r2.push_back(x);		
	}
	solve(l1, l2);
	solve(r1, r2);
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
 	for(int i=1; i<=n; i++)
		v[i-1] = i;
	solve(v, v);
	cout << "!";
	for(int i=1; i<=n; i++)
		cout << " " << ans[i];
	cout << endl;
	return 0;
}
