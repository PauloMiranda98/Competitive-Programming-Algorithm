#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char matriz[1002][1002];

int main(){
	
	cin.sync_with_stdio(0);
	cin.tie(0);

	
	int n, m, cont=0;
	
	cin >> n >> m;
	
	vector< pair<int,int> > lista;
	
	for(int i=0; i <= (n+1); i++){
		matriz[0][i] = '.';
		matriz[m+1][i] = '.';
	}
	
	for(int i=0; i <= (m+1); i++){
		matriz[i][0] = '.';
		matriz[i][n+1] = '.';
	}
	
	for(int i=1; i <= n; i++){
		for(int j=1; j <= m; j++){
			cin >> matriz[i][j];
			if(matriz[i][j] == '#')
				lista.push_back(make_pair(i, j));
		}
	}
	
	for(int x=1; x <= (int)lista.size(); x++){
		int i,j;
		i = lista[x].first;
		j = lista[x].second;
		
		if( (matriz[i+1][j]=='.') || (matriz[i-1][j]=='.') || (matriz[i][j+1]=='.') || (matriz[i][j-1]=='.'))
			cont++;
	}	
	cout << (cont) << endl;	    			 	
													 			   				
	return 0;
	
}   
   
