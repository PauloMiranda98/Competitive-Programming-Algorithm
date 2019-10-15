#include <bits/stdc++.h>

using namespace std;

const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1, sz, match=-1;
    char pch;
    int suff_link = -1;
    int end_link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$', int _sz=0) : p(p), pch(ch){
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
        sz = _sz;
    }
};

vector<Vertex> trie(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back(v, ch, trie[v].sz+1);
        }
        v = trie[v].next[c];
    }
    trie[v].leaf = true;
}

int go(int v, char ch);

int get_suff_link(int v) {
    if (trie[v].suff_link == -1) {
        if (v == 0 || trie[v].p == 0)
            trie[v].suff_link = 0;
        else
            trie[v].suff_link = go(get_suff_link(trie[v].p), trie[v].pch);
    }
    return trie[v].suff_link;
}

int get_end_link(int v) {
    if (trie[v].end_link == -1) {
        if (v == 0 || trie[v].p == 0){
            trie[v].end_link = 0;        
        }else{
			int suff_link = get_suff_link(v);
			if(trie[suff_link].leaf)
				trie[v].end_link = suff_link;
			else
				trie[v].end_link = get_end_link(suff_link);			
		}
    }
    return trie[v].end_link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (trie[v].go[c] == -1) {
        if (trie[v].next[c] != -1)
            trie[v].go[c] = trie[v].next[c];
        else
            trie[v].go[c] = v == 0 ? 0 : go(get_suff_link(v), ch);
    }
    return trie[v].go[c];
} 

void printMatch(int v, int i){
	if(v == 0)
		return;
	cout << i - trie[v].sz + 1 << " " << i << endl;
	printMatch(get_end_link(v), i);
}

void whatMatch(string t){
	int state = 0;
	int i=0;
	for(char c : t){
		state = go(state, c);
		if(trie[state].leaf)
			printMatch(state, i);
		else
			printMatch(get_end_link(state), i);
		i++;
	}
}

int countMatch(int v){    
    if(trie[v].match == -1) {
        if (v == 0 || trie[v].p == 0){
			if(trie[v].leaf)
				trie[v].match = 1;        
			else
				trie[v].match = 0;        
        }else{
			if(trie[v].leaf)
				trie[v].match = 1 + countMatch(get_end_link(v));
			else
				trie[v].match = countMatch(get_end_link(v));			
		}
    }
    return trie[v].match;	
}

long long matchAmount(string t){
	int state = 0;
	long long ans = 0;
	for(char c : t){
		state = go(state, c);
		ans += countMatch(state);
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		add_string(s);
	}
	string t;
	cin >> t;
	whatMatch(t);
	cout << "Qtd: " << matchAmount(t) << endl;
	return 0;
}
