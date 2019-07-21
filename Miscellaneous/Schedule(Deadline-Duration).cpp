#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

struct Job {
    int deadline, duration, idx;

    bool operator<(Job o) const {
        return deadline < o.deadline;
    }
};

vector<Job> jobs;

vector<int> compute_schedule() {
    sort(jobs.begin(), jobs.end());

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<int> schedule;
    for (int i = jobs.size()-1; i >= 0; i--) {
        int t = jobs[i].deadline - (i ? jobs[i-1].deadline : 0);
        pq.push(pii(jobs[i].duration, jobs[i].idx));
        while (t && !pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if (it.first <= t) {
                t -= it.first;
                schedule.push_back(it.second);
            } else {
                pq.push(pii(it.first - t, it.second));
                t = 0;
            }
        }
    }
    sort(jobs.begin(), jobs.end(), [](Job a, Job b){return a.idx < b.idx;});
    sort(schedule.begin(), schedule.end(), [](int a, int b){return jobs[a] < jobs[b];});
    
    return schedule;
}

int main(){
	int n;
	cin >> n;
	
	jobs.resize(n);
	for(int i=0; i<n; i++){
		cin >> jobs[i].duration >> jobs[i].deadline;
		jobs[i].idx = i;
	}
	
	vector<int> ans = compute_schedule();
	cout << "Tasks performed: " << ans.size() << endl;
	for(int x: ans)
		cout << x << endl;
	return 0;
}

