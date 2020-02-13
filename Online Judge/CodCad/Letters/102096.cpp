#include <iostream>
#include <algorithm>
#define PB push_back

using namespace std;

int lis(string &v){
	
	vector<char> pilha;
	
	for(int i=0; i<(int)v.size(); i++){
		
		vector<char>::iterator it = upper_bound(pilha.begin(), pilha.end(), v[i]);
		
		if(it==pilha.end()) pilha.PB(v[i]);
		
		else *it = v[i];
	}
	
	return pilha.size();
}
int main(){
	string texto;
	cin >> texto;
	
	cout << lis(texto) << endl;
	
	return 0;
}
