#include <bits/stdc++.h>
#define MAXN 100100

using namespace std;

typedef long long int lli;
lli seq[MAXN];
int n, c, l;

bool test(lli tempo){
	
	lli acc = 0;
	lli rest = c;
	lli limite = tempo * l;
	
	for(int i = 1; i <= n; i++){
		if(seq[i] > limite) return false;
		if(rest == 0) return false;
		
		if(i == n and rest == 1){
			if(acc + seq[i] > limite) return false;
		}
		if(acc + seq[i] <= limite){
			acc += seq[i];
		}else{
			acc = seq[i];
			rest--;
		}
		
	}
	
	return true;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> c >> l;
	
	for(int i = 1; i <= n; i++){
		cin >> seq[i];
	}
	
	lli i = 1;
	lli j = 1000000010;
	lli meio;
	lli res = -1;
	
	while(i <= j){
		meio = (i+j)/2;
		
		if(test(meio) == true){
			res = meio;
			j = meio-1;
		}else{
			i = meio+1;
		}
	}
	
	cout << res << endl;
	
	return 0;
}





/*

5 3 4
5 8 3 10 7




*/




