#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int BLOCK_SIZE = 700;

vector<int> v;
int n;

map<int, int> s_freq;
set< pair<int, int> > s_max;

void remove(int idx){
	int value = v[idx];
	int freq = s_freq[value];
	
	s_max.erase(pii(freq, value));
	s_freq[value]--;
	s_max.insert(pii(freq-1, value));
}  

void add(int idx){
	int value = v[idx];
	int freq = s_freq[value];
	
	s_max.erase(pii(freq, value));
	s_freq[value]++;
	s_max.insert(pii(freq+1, value));
}     

pii get_answer(){
	return *s_max.rbegin();
}

struct Query {
    int l, r, idx;
    
    bool operator<(Query other) const{
		if (l / BLOCK_SIZE != other.l / BLOCK_SIZE)
			return l < other.l;
		return (l / BLOCK_SIZE & 1) ? (r < other.r) : (r > other.r);
    }
};

vector<pii> mo_s_algorithm(vector<Query> queries) {
    vector<pii> answers(queries.size());
    sort(queries.begin(), queries.end());

    //Initialize data structure
	s_freq.clear();
	s_max.clear();
	
    int cur_l = 0;
    int cur_r = -1;

    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

int main(){		
	cin >> n;
	v.resize(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	
	vector<Query> vq;	
	
	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		Query query;
		cin >> query.l >> query.r;
		query.idx = i;
		
		vq.push_back(query);
	}
	
	vector<pii> vans = mo_s_algorithm(vq);
	
	for(int i=0; i<q; i++){
		cout << "Max Freq: " << vans[i].first << ", Value: " << vans[i].second << endl;
	}	
	
	return 0;
}
