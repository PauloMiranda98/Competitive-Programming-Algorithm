#include <iostream>
#include <set>

using namespace std;

int main(){
	set<long int> conteiner;
	long int n;			
	cin >> n;

	for(long int i=0; i < n; i++){
		long int x;
		cin >> x;
		conteiner.insert(x);
	}
	
	cout << conteiner.size() << endl;
		
	return 0;
}