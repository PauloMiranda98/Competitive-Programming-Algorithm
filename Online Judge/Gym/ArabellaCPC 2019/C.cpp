#include <bits/stdc++.h>

#define F first
#define S second
#define EB emplace_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define all(x) x.begin(),x.end()
#define endl '\n'
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
int n, m;

string s1, s2;

char getChar(char c, bool upper){
	if(upper)
		return 'A'+(c-'a');
	else
		return c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	cin.ignore();
	getline(cin, s1);
	cin >> m;
	bool upper = false;
	for(int i=0; i<m; i++){
		string line;
		cin >> line;
		if(line == "Space")
			s2 += ' ';
		else if(line == "CapsLock")
			upper = !upper;
		else if(line == "Backspace"){
			if(s2.size()>0)
				s2.pop_back();
		}else
			s2 += getChar(line[0], upper);		
	}
//	cout << s1 << endl;
//	cout << s2 << endl;
	if(s1 == s2)
		cout << "Correct" << endl;
	else
		cout << "Incorrect" << endl;
		
	return 0;
}
