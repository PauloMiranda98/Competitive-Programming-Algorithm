#include <iostream>
#include <cstring>
#include <algorithm>

#define MAXN 1010

using namespace std;


long int s1[MAXN], s2[MAXN], tab[MAXN][MAXN];

long int lcs(long int a, long int b){ // declaro a funcao da DP, de nome lcs
	
	if(tab[a][b]>=0) return tab[a][b]; // retornamos o valor salvo para ele
	
	if(a==0 or b==0) return tab[a][b]=0;
	
	if(s1[a]==s2[b]) return 1+lcs(a-1, b-1); // e adicionamos ele a lcs das subsequancias restantes
	
	return tab[a][b]=max(lcs(a-1, b), lcs(a, b-1));
}

int main(){
	long int n;
	
	memset(tab, -1, sizeof(tab));
	
	cin >> n;
	
	for(long int i = 1; i <= n; i++){

		cin >> s1[i];
		s2[i] = s1[i];
		
	}
	
	sort(s2+1, s2+n+1);
	
	cout << lcs(n,n) << endl;
	
	return 0;
}
