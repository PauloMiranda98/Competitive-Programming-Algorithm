#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100010;

int histogram(vector<int> v){
	int n = v.size();
	v.push_back(0);
	int ans = 0;
	stack<int> st;
	for(int i = 0; i<=n; ++i){
		while(st.size() && v[st.top()] >= v[i]){
			int idx = st.top(); st.pop();
			int L = st.size() ? st.top() : 0;
			ans = max(ans, (i - L -1) * v[idx]);
		}
		st.push(i);
	}
	return ans;
}

int main() {	
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];

	cout << histogram(v) << endl;

	return 0;
}
