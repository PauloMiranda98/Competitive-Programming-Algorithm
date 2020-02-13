#include <bits/stdc++.h>
#define MAX 99999999

using namespace std;


long int distancia[110][110];

int main() {

	long int n, m;
	long int x, y, z;
	
	cin >> n >> m;

	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			distancia[i][j] = MAX;	

	for(int i = 0;i < n;i++)
		distancia[i][i] = 0;	
	
	for(int i=0; i < m; i++){
		cin >> x >> y >> z;
		
		distancia[x][y] = z;
		distancia[y][x] = z;		
	}	

	for(int k = 0;k < n;k++)
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				distancia[i][j] = min(distancia[i][j], distancia[i][k] + distancia[k][j]);	
	
	long int res = MAX;
	
	for(int i = 0;i < n;i++){
		long int aux = 0;
		
		for(int j = 0;j < n;j++){
			aux = max(aux, distancia[i][j]);			
		}		
		
		res = min(res, aux);
	}
	
	cout << res << endl;
	
	return 0;
	
}
