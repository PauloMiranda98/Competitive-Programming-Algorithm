#include <iostream>
#include <vector> 

#define INF 1000000000L
using namespace std;

long int merge_sort(vector<long int> &v){
	
	// declaro inv, o total de inversoes
	long int inv=0;
	
	// se o tamanho de v for 1, nao ha inversoes
	if(v.size()==1) return 0;
	
	// se nao
	
	// declaro os vetore u1 e u2
	vector<long int> u1, u2;
	
	// e faco cada um receber uma metade de v
	for(long int i=0;i<(long int)v.size()/2;i++){
		u1.push_back(v[i]);
	}
	for(long int i= (long int)v.size()/2;i<(long int)v.size();i++){
	 	u2.push_back(v[i]);
	}	
	// ordeno u1 e u2
	// e adiciono a inv as inversoes de cada metade do vetor
	inv+=merge_sort(u1);
	inv+=merge_sort(u2);
	
	// e adiciono INF ao final de cada um deles
	u1.push_back(INF);
	u2.push_back(INF);
	
	// declaro ini1 e ini2 com valore inicial zero
	long int ini1=0, ini2=0;
	
	// percorro cada posicao de v
	for(long int i=0;i<(long int)v.size();i++){
		
		// se o menor nao usado de u1 for menor o mesmo em u2
		if(u1[ini1]<=u2[ini2]){
			
			// entao o coloco em v
			v[i]=u1[ini1];
			
			// e incremento o valor de ini1
			ini1++;
		}
		
		// caso contrario, faco o analogo com u2 e ini2
		else{
			
			v[i]=u2[ini2];
			ini2++;
			
			// nao se esquecendo de adicionar o numero de elementos em u1
			// ao total deinversoes em v
			inv+=u1.size()-ini1-1;
		}
	}
	
	// por fim, retorno a quantidade de inversoes
	return inv;
}

int main(){
	long int n;
	
	while(cin >> n && n!=0){
		vector<long int> v;
		v.resize(n);
		for(long i=0; i<n; i++)
			cin >> v[i];
		if(merge_sort(v)%2 == 0)
			cout << "Carlos" << endl;
		else
			cout << "Marcelo" << endl;
	}
	
	return 0;
	
}
  
