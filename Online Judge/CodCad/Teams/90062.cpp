#include <bits/stdc++.h>
using namespace std;

vector<string> times[1010];
vector< pair<int, string> > valores;

int main(){
	
	long int n, t;
	
	cin >> n >> t;
	
	for(long int i=0; i<n; i++){
		string nome;
		int hab;
		
		cin >> nome >> hab;
		valores.push_back( make_pair(hab, nome) );		
	}
	
	sort(valores.begin(), valores.end());
	
	int time = 0;
	
	for(long int i=n-1; i >=0; i--){
		times[time].push_back(valores[i].second);
		time = (time + 1) % t;		
	}
	
	for(long int i=0; i < t; i++){
		cout << "Time "<< (i+1) << endl;
		
		sort(times[i].begin(), times[i].end());
		
		for(long int j=0; j< (long int) times[i].size(); j++){
			cout << times[i][j] <<endl;
		}
		
		cout << endl;
	}
	
	
	return 0;
}
