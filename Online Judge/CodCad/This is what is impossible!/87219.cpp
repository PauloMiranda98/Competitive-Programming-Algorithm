#include <iostream>
#include <vector>
#define MAX 1001

int dp[MAX];

using namespace std;

int main() {
	int n, m, cont = 0;
	
	vector<int> vetor;
	
	cin >> n >> m;
	
	vetor.reserve(n);
	
	for(int i=0; i<n; i++){
		cin >> vetor[i];
	}
	
	dp[0] = 0;
		
	for(int i=1; i <m; i++){
		dp[i] = -1;	
		
		for(int j=0;j < n;j++){
			if( (i-vetor[j]) >= 0){
				if(dp[i-vetor[j]] >= 0){
					if(dp[i] == -1)
						dp[i] = (dp[i-vetor[j]] + 1);
					else
						dp[i] = min(dp[i], dp[i-vetor[j]] + 1);
				}
			}
		}
		
		if(dp[i] == -1)
			cont++;
	}
	
	cout << cont << endl;
	
	return 0;
	
}
