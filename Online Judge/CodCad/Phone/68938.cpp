#include <iostream> 

using namespace std;

char conv(char c){
	switch(c){
		case '1':
			return '1';
		case '2': case 'A':	case 'B': case 'C':	
			return '2';
		case '3': case 'D':	case 'E': case 'F':	
			return '3';
		case '4': case 'G':	case 'H': case 'I':	
			return '4';
		case '5': case 'J':	case 'K': case 'L':	
			return '5';
		case '6': case 'M':	case 'N': case 'O':	
			return '6';
		case '7': case 'P':	case 'Q': case 'R': case 'S':	
			return '7';
		case '8': case 'T':	case 'U': case 'V':	
			return '8';
		case '9': case 'W':	case 'X': case 'Y': case 'Z':	
			return '9';
		case '0': 	
			return '0';
		case '-': 	
			return '-';
			
	}
	
	return '0';
}

int main(){

	int t, cont=0;
	string a;

	cin >> a;
	
	for(int i=0; i < a.size(); i++)
		a[i] = conv(a[i]); 
			
	cout << a << endl;
		
	return 0;  
}
