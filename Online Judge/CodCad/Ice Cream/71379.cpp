#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(void) {
	 
	pair<int, int> vetor[5001];
	
	int n, t;

	cin >> n >> t;
	
	for(int i=0; i < t; i++)
		cin >> vetor[i].first >> vetor[i].second;
	
	sort(vetor, vetor + t);
	
	int ultimo = 0;
	
	cout << vetor[0].first;
	ultimo = vetor[0].second;
			
	for(int i=0; i < t; i++){		
		
		if(vetor[i].first <= ultimo){
			if(vetor[i].second > ultimo)
				ultimo = vetor[i].second;			
		}else{
			cout << " " << ultimo << endl;
			cout << vetor[i].first;	
			ultimo = vetor[i].second;				
		}				  		
		
	}
	
	cout << " " << ultimo << endl;
	
    return 0;
}