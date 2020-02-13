#include <iostream>
#include <algorithm>

using namespace std;
pair<int, int> vetor[1000002];

int main(){

	int n, m;	
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		vetor[i].first = 0;
		vetor[i].second = i;
		
		for(int j=1; j<=m; j++){
		   int x;
		   cin >> x;
		   vetor[i].first += x;	
		}
		
	}
	
	sort(vetor+1, vetor+n+1);
		
	cout << vetor[1].second << endl;
	cout << vetor[2].second << endl;
	cout << vetor[3].second << endl;
	
	return 0;
}