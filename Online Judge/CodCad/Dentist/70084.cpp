#include <iostream>
#include <utility>  
#include <algorithm>

using namespace std;


struct Par{
	int first;
	int second;
};

bool compara(const Par& a, const Par& b){
	return a.second < b.second;
}

Par vetor[1000001];

int main(){
	int n;
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for(int i=0; i < n; i++)
		cin >> vetor[i].first >> vetor[i].second;

	sort(vetor, vetor + n, compara);

	int ultimo = 0;
	int cont = 0;
	
	for(int i=0; i < n; i++){
		if(vetor[i].first >= ultimo){
			cont++;
			ultimo = vetor[i].second;
		}
	}
	cout << cont << endl;
	
    return 0;
}
