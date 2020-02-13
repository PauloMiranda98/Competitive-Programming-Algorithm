#include <iostream> 

using namespace std;

bool isVogal(char x){
	switch(x){
		case 'a':
			return true;
		case 'e':
			return true;
		case 'i':
			return true;
		case 'o':
			return true;
		case 'u':
			return true;
	}
	
	return false;	
}

int main(){

	string a;
	cin >> a;
	
	int i=0, j=a.size()-1;
	
	bool r = true;
	
	while(i<=j){
		while( !isVogal(a[i]) )
			i++;
		
		while( !isVogal(a[j]) )
			j--;
		
		if(a[i] != a[j]){
			r = false;
			break;
		}
		i++;
		j--;
	}
	
	if(r)
		cout << "S" << endl;
	else	
		cout << "N" << endl;
		
	return 0;  
}
