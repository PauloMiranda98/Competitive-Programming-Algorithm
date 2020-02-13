#include <iostream>
#include <vector>
#define MAX 1001

int dp[MAX];

using namespace std;

int main() {
	int n, m;
	
	vector<int> vetor;
	
	cin >> n >> m;
	
	vetor.reserve(n);
	
	for(int i=0; i<n; i++){
		cin >> vetor[i];
	}
	
	dp[0] = 1;
		
	for(int i=1; i <=m; i++){
		dp[i] = 0;	
		
		for(int j=0;j < n;j++){
			if( (i-vetor[j]) >= 0){
				if(dp[i-vetor[j]]){
					dp[i] = 1;
				}
			}
		}
		
	}
	
	
	if(dp[m]){
		cout << "S" << endl;
	}else{
		cout << "N" << endl;		
	}
	
	return 0;
	
}
