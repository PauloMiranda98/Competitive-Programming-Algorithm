#include <iostream> 
#include <string.h> 

using namespace std;

int main(){

	bool vetor[52];
	memset(vetor, 0, sizeof(vetor));
	
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++)
		cin >> vetor[i];
	
	for(int i=1; i<=n; i++)
		cout << (vetor[i-1] + vetor[i] + vetor[i+1]) << endl;

	return 0;  
}
