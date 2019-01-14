#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 200010

struct Node{
	int vPre; //Melhor Prefixo
	int ePre; //Elemento do prefixo
	int vSuf; //Melhor Sufixo
	int eSuf; //Elemento do sufixo
	int ans;  //Resposta
	
	Node(){
		vPre = 0;
		ePre = 0;
		vSuf = 0;
		eSuf = 0;
		ans = 0;
	}
};

int n, v[MAXN];
Node tree[4*MAXN];
int neutral = 0;

//Build: O(4*n) -> O(n); call -> build(1, 1, n)
void build(int node, int i, int j){
	if(i == j){
		tree[node].ans = 1;
		tree[node].vPre = 1;
		tree[node].ePre = v[i];
		tree[node].vSuf = 1;
		tree[node].eSuf = v[i];
		
		return;
	}
	
	int m = (i+j)/2;
	
	int l = (node<<1);
	int r = l + 1;
	
	build(l, i, m);
	build(r, m+1, j);
	
	tree[node].ans = max(tree[l].ans, tree[r].ans);

	if(tree[l].eSuf == tree[r].ePre)
		tree[node].ans = max(tree[node].ans, tree[l].vSuf + tree[r].vPre);
	
	tree[node].ePre = tree[l].ePre;
	tree[node].vPre = ((tree[l].ePre == tree[r].ePre)? (tree[l].vPre+tree[r].vPre) :tree[l].vPre);
	tree[node].eSuf = tree[r].eSuf;
	tree[node].vSuf = ((tree[r].eSuf == tree[l].eSuf)? (tree[l].vSuf + tree[r].vSuf) :tree[r].vSuf);
	
}

//Query: O(log(n)); call -> query(1, 1, n, a, b)
Node query(int node, int i, int j, int a, int b){
	if( (i>b) or (j<a) )
		return Node();
	if( (a<=i) and (j<=b) )
		return tree[node];
		
	int m = (i+j)/2;
	
	int l = (node<<1);
	int r = l + 1;
	Node nodeL = query(l, i, m, a, b);
	Node nodeR = query(r, m+1, j, a, b);
	
	if(nodeL.ans == 0)
		return nodeR;
	
	if(nodeR.ans == 0)
		return nodeL;

	Node aux;
	
	aux.ans = max(nodeL.ans, nodeR.ans);
	
	if(nodeL.eSuf == nodeR.ePre)
		aux.ans = max(aux.ans, nodeL.vSuf + nodeR.vPre);

	aux.ePre = nodeL.ePre;
	aux.vPre = ((nodeL.ePre == nodeR.ePre) ? (nodeL.vPre + nodeR.vPre) : nodeL.vPre);
	aux.eSuf = nodeR.eSuf;
	aux.vSuf = ((nodeL.eSuf == nodeR.eSuf) ? (nodeL.vSuf + nodeR.vSuf) : nodeR.vSuf);		
	
	return aux;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	while(cin >> n, n){
		int q;
		cin >> q;
		
		for(int i=1; i<=n; i++){
			cin >> v[i];
		}
				
		build(1, 1, n);
		
		for(int i=0; i<q; i++){
			int a, b;
			cin >> a >> b;
			cout << query(1, 1, n, a, b).ans << endl;
		}
	}
	
	return 0;
	
}
