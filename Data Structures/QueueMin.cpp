#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

struct QueueMin{
	#define cmp(a, b) std::min((a), (b))
	typedef int t_queue;
	stack<pair<t_queue, t_queue> > s1, s2;

	void push(t_queue x){
		t_queue minimum = s1.empty() ? x : cmp(x, s1.top().second);
		s1.push({x, minimum});	
	}
	void pop(){
		if (s2.empty()) {
			while (!s1.empty()) {
				t_queue element = s1.top().first;
				s1.pop();
				t_queue minimum = s2.empty() ? element : cmp(element, s2.top().second);
				s2.push({element, minimum});
			}
		}
		s2.pop();	
	}
	t_queue top(){
		return s2.top().first;
	}
	t_queue min(){
		if (s1.empty() || s2.empty()) 
			return s1.empty() ? s2.top().second : s1.top().second;
		else
			return cmp(s1.top().second, s2.top().second);
	}	
	t_queue size(){
		return s1.size() + s2.size();
	}	
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	QueueMin qm;
	
	int q;
	cin >> q;
	while(q--){
		char op;
		cin >> op;
		if(op == 'i'){
			int x;
			cin >> x;
			qm.push(x);
		}else if(op == 'e'){
			qm.pop();
		}else{
			cout << qm.min() << endl;			
		}

	}
    
	return 0;
}

