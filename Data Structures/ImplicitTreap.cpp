#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

//const int INF = (1 << 30);

typedef int ftype;
const ftype neutral = 0;
inline ftype join(ftype a, ftype b, ftype c){
	return a + b + c;
}

struct node{
	int y, size;
	ftype v, op_value;
	bool rev;
	node *l, *r;
	node(ftype _v){
		v = op_value = _v;
		y = rand();
		size = 1;
		l = r = NULL;
		rev = false;
	}	
};

class ImplicitTreap {
private:
	node* root;
	int size(node* t) { return t ? t->size : 0; }
	ftype op_value(node* t) { return t ? t->op_value : neutral; }
	node* refresh(node* t) {
		if (t == NULL) return t;
		t->size = 1 + size(t->l) + size(t->r);
		t->op_value = join(t->v, op_value(t->l), op_value(t->r));
		if (t->l != NULL) t->l->rev ^= t->rev;
		if (t->r != NULL) t->r->rev ^= t->rev;
		if (t->rev) {
			swap(t->l, t->r);
			t->rev = false;
		}
		return t;
	}
	void split(node* &t, int k, node* &a, node* &b) {
		refresh(t);
		node * aux;
		if (!t) a = b = NULL;
		else if (size(t->l) < k) {
			split(t->r, k-size(t->l)-1, aux, b);
			t->r = aux;
			a = refresh(t);
		}
		else {
			split(t->l, k, a, aux);
			t->l = aux;
			b = refresh(t);
		}
	}
	node* merge(node* a, node* b) {
		refresh(a); refresh(b);
		if (!a || !b) return a ? a : b;
		if (a->y < b->y) {
			a->r = merge(a->r, b);
			return refresh(a);
		}
		else {
			b->l = merge(a, b->l);
			return refresh(b);
		}
	}
	node* at(node* t, int n) {
		if (!t) return t;
		refresh(t);
		if (n < size(t->l)) return at(t->l, n);
		else if (n == size(t->l)) return t;
		else return at(t->r, n-size(t->l)-1);
	}
	void del(node* &t) {
		if (!t) return;
		if (t->l) del(t->l);
		if (t->r) del(t->r);
		delete t;
		t = NULL;
	}
public:
	ImplicitTreap() : root(NULL) {
		srand(time(NULL));
	}
	~ImplicitTreap() { clear(); }
	void clear() { del(root); }
	int size() { return size(root); }
	bool insertAt(int n, int v) {
		node *a, *b;
		split(root, n, a, b);
		root = merge(merge(a, new node(v)), b);
		return true;
	}
	bool erase(int n) {
		node *a, *b, *c, *d;
		split(root, n, a, b);
		split(b, 1, c, d);
		root = merge(a, d);
		if (c == NULL) return false;
		delete c;
		return true;
	}
	ftype at(int n) {
		node* ans = at(root, n);
		return ans ? ans->v : -1;
	}
	ftype query(int l, int r) {
		if (l > r) swap(l, r);
		node *a, *b, *c, *d;
		split(root, l, a, d);
		split(d, r-l+1, b, c);
		ftype ans = op_value(b);
		root = merge(a, merge(b, c));
		return ans;
	}
	void reverse(int l, int r) {
		if (l>r) swap(l, r);
		node *a, *b, *c, *d;
		split(root, l, a, d);
		split(d, r-l+1, b, c);
		if (b != NULL) b->rev ^= 1;
		root = merge(a, merge(b, c));
	}
};


int n;

int main() {			
	ImplicitTreap treap;
	
	int q;
	cin >> q;
	
	for(int i=0; i<q; i++){
		char op;
		
		cin >> op;
		if(op == 'q'){
			int a, b;
			cin >> a >> b;
			cout << treap.query(a, b) << endl;
		}else if(op == 'r'){
			int a, b;
			cin >> a >> b;
			treap.reverse(a, b);
		}else{
			int index, value;
			cin >> index >> value;
			treap.insertAt(index, value);	
		}
	}
		
	return 0;
	
}

