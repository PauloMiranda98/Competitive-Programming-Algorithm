#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

typedef int f_type;

struct Node{
    f_type value;
    Node *l, *r;
    Node(f_type x = 0){
		value = x;
		l = nullptr;
		r = nullptr;		
	}
};

inline bool heapMin(f_type a, f_type b){
	return a > b;
}
inline bool heapMax(f_type a, f_type b){
	return a < b; 
}

struct RandomizedHeap{
	Node *root;
	RandomizedHeap(){
		srand(time(NULL));
		root = nullptr;
	}
	Node* merge(Node *t1, Node *t2) {
		if(!t1 || !t2)
			return t1 ? t1 : t2;
		if(heapMin(t1->value, t2->value))
			swap(t1, t2);
		if(rand() & 1)
			swap(t1->l, t1->r);
		t1->l = merge(t1->l, t2);
		return t1;
	}	
	int top(){				
		return (root != nullptr) ? root->value : 0;
	}
	void pop(){
		if(root == nullptr)
			return;
		Node *l = root->l;
		Node *r = root->r;
		delete root;
		
		root = merge(l, r);
	}	
	void push(int x){
		Node *nw = new Node(x);
		root = merge(root, nw);
	}
};

int main() {	
	RandomizedHeap rd;
	
	int q;
	cin >> q;
	while(q--){
		char op;
		cin >> op;
		if(op == 'i'){
			int x;
			cin >> x;
			rd.push(x);
		}else if(op == 'e'){
			rd.pop();
		}else{
			cout << rd.top() << endl;			
		}

	}
    
	return 0;
}

