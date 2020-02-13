#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
long int memo[1010][1010];
long int vetor[1010];
long int soma[1010];

long int soma_max(int i, int j){
	if( (j - i + 1) == 1 )
		return vetor[i];
	if( (j - i + 1) == 2)
		return max(vetor[i], vetor[j]);		
	if( memo[i][j] != -1 )
		return memo[i][j];
		
	long int s = soma[j] - soma[i-1];
	return memo[i][j] = max(s-soma_max(i+1, j), s-soma_max(i, j-1));
} 
// 5 100 2 1
int main(){
	
	memset(memo,-1,sizeof(memo));
	
	int n;
	
	cin >> n;
	
	soma[0] = 0;
	for(int i=1; i<= n; i++){
		cin >> vetor[i];
		soma[i] = soma[i-1] + vetor[i];
	}
	
	long j1 = soma_max(1, n);
		
	cout << j1 << " " << (soma[n]-j1) << endl;
		
	return 0;
}
