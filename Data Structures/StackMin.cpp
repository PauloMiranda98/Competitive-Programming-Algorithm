#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

struct StackMin{
	typedef int t_stack;
	stack<pair<t_stack, t_stack> > st;
	
	void push(t_stack x){
		t_stack new_min = st.empty() ? x : std::min(x, st.top().second);
		st.push({x, new_min});	
	}
	void pop(){
		st.pop();
	}
	t_stack top(){
		return st.top().first;
	}
	t_stack min(){
		return st.top().second;
	}
	t_stack size(){
		return st.size();
	}	
	
};

int main() {	
	StackMin sm;
	
	int q;
	cin >> q;
	while(q--){
		char op;
		cin >> op;
		if(op == 'i'){
			int x;
			cin >> x;
			sm.push(x);
		}else if(op == 'e'){
			sm.pop();
		}else{
			cout << sm.min() << endl;			
		}

	}
    
	return 0;
}

