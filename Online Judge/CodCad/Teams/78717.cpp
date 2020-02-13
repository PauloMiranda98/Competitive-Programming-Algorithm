#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool comparar(pair<int, string>  a, pair<int, string>  b){
	return (a.first > b.first);
}

int main(void) {
	
	pair<int, string> vetor[10001];
	set<string> time[1001];
	
	int n, t;

	cin >> n >> t;
	
	for(int i=0; i < n; i++)
		cin >> vetor[i].second >> vetor[i].first;
	
	sort(vetor, vetor + n, comparar);
	
	for(int i=0; i < n; i++){
		time[i%t].insert(vetor[i].second);
	}

	set<string>::iterator it;
	
	for(int i=0; i < t; i++){
		cout << "Time " << (i+1) << endl;
		
		for(it = time[i].begin(); it != time[i].end(); it++){
			cout << *it << endl;
		}
		cout << endl;
	}
	
	
    return 0;
}