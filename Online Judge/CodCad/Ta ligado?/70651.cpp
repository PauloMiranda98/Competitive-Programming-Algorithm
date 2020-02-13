#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int> matriz[100001];

int main(){
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	
	cin >> n >> m;
		
	for(int i=0; i < m; i++){			
		int op, x, y;
		
		cin >> op >> x >> y;
		
		if(op){
			matriz[max(x,y)].insert(min(x,y));
		}else{
			cout << (matriz[max(x,y)].find(min(x,y)) != matriz[max(x,y)].end()) << endl;
		}
	}
														 			   				
	return 0;
	
}   
   
