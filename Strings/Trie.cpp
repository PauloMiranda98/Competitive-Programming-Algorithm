#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int K = 26;

inline int getId(char c){
	return c - 'a';
}

struct Vertex {
	int next[K];
	int leaf;
	int count;

	Vertex() {
		fill(begin(next), end(next), -1);
		leaf = 0;
		count = 0;
	}
};

struct Trie{
	vector<Vertex> trie;
	
	Trie(){
		trie.emplace_back();
	}

	void add(string const& s) {
		int v = 0;
		trie[v].count++;
		
		for(char ch : s) {
			int c = getId(ch);
			if (trie[v].next[c] == -1) {
				trie[v].next[c] = trie.size();
				trie.emplace_back();
			}
			v = trie[v].next[c];
			trie[v].count++;
		}
		trie[v].leaf++;
	}	

	int countStr(string const& s) {
		int v = 0;
		for (char ch : s) {
			int c = getId(ch);
			if (trie[v].next[c] == -1)
				return 0;
			
			v = trie[v].next[c];
		}
		return trie[v].leaf;
	}	

	int countPre(string const& s) {
		int v = 0;
		for (char ch : s) {
			int c = getId(ch);
			if (trie[v].next[c] == -1)
				return 0;
			
			v = trie[v].next[c];
		}
		return trie[v].count;
	}	

	
};

int main() {
	Trie t;	
	int q;
	cin >> q;
	while(q--){
		int op; //1 - insert string, 2 - count string, 3 - count prefix
		string s;
		
		cin >> op >> s;
		if(op == 1)
			t.add(s);
		else if(op == 2)
			cout << t.countStr(s) << endl;
		else
			cout << t.countPre(s) << endl;					
	}
		
	return 0;	
}
