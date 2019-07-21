#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

struct Job {
    int t, c, idx;
};

//Penalty functions fi(t) = c[i]*t
bool cmp1(Job a, Job b){
	return a.c*(ll)b.t > b.c*(ll)a.t;
}
//Penalty functions fi(t) = c[i]*e^(alfa*t)
/*
bool cmp2(Job a, Job b){
	return (1 - pow(euler, alfa*a.t))/a.c > (1 - pow(euler, alfa*b.t))/b.c;
}
*/

int main(){
	int n;
	cin >> n;
	
	vector<Job> jobs(n);
	for(int i=0; i<n; i++){
		cin >> jobs[i].t >> jobs[i].c;
		jobs[i].idx = i;
	}
	sort(jobs.begin(), jobs.end(), cmp1);
	cout << "Order:";
	for(Job x: jobs)
		cout << " " << x.idx;
	cout << endl;
	return 0;
}

