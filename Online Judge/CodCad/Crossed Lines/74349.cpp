#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000

int merge_sort(vector<int> &v){
	
	int inv=0;
	
	if(v.size()==1) return 0;	
	
	vector<int> u1, u2;
	
	for(int i=0;i<v.size()/2;i++){
		u1.push_back(v[i]);
	}
	for(int i=v.size()/2;i<v.size();i++){
	 	u2.push_back(v[i]);
	}	
	
	inv+=merge_sort(u1);
	inv+=merge_sort(u2);
	
	u1.push_back(INF);
	u2.push_back(INF);
	
	int ini1=0, ini2=0;
	
	for(int i=0;i<v.size();i++){
		
		if(u1[ini1]<=u2[ini2]){
			
			v[i]=u1[ini1];
			
			ini1++;
		}
		
		else{
			
			v[i]=u2[ini2];
			ini2++;
			
			inv+=u1.size()-ini1-1;
		}
	}
	
	return inv;
}

int main(){
	vector<int> vetor;
	
	long int n;	
	cin >> n;
	vetor.resize(n);
	
	for(int i=0; i < n; i++){
		cin >> vetor[i];
	}
	
	cout << merge_sort(vetor) << endl;
	
	return 0;
}