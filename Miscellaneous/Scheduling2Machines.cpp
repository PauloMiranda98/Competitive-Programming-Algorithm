#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

struct Job {
    int a, b, idx;

    bool operator<(Job o) const {
        return min(a, b) < min(o.a, o.b);
    }
};

vector<Job> johnsons_rule(vector<Job> jobs) {
    sort(jobs.begin(), jobs.end());
    vector<Job> a, b;
    for (Job j : jobs) {
        if (j.a < j.b)
            a.push_back(j);
        else
            b.push_back(j);
    }
    a.insert(a.end(), b.rbegin(), b.rend());
    return a;
}

pll finish_times(vector<Job> const& jobs) {
    ll t1 = 0, t2 = 0;
    for (Job j : jobs) {
        t1 += j.a;
        t2 = max(t2, t1) + j.b;
    }
    return pll(t1, t2);
}

int main(){
	int n;
	cin >> n;
	
	vector<Job> jobs(n);
	for(int i=0; i<n; i++){
		cin >> jobs[i].a >> jobs[i].b;
		jobs[i].idx = i;
	}
	
	vector<Job> order = johnsons_rule(jobs);
	pll ft = finish_times(order);
	cout << "Time Machine 1: " << ft.first << ", Time Machine 2: "<< ft.second << endl;
	cout << "Order:";
	for(Job x: order)
		cout << " " << x.idx;
	cout << endl;
	return 0;
}

