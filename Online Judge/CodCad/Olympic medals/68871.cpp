#include <iostream> 

using namespace std;

int main(){
  
  int a, b, c;
  int a2, b2, c2;
  
  cin >> a  >> b  >> c;
  cin >> a2 >> b2 >> c2;

  if(a == a2){

	  if(b == b2){
		if(c > c2)
			cout << "A" << endl;
		else
			cout << "B" << endl;

	  }else{
		if(b > b2)
 			cout << "A" << endl;
		else
			cout << "B" << endl;
	  }
	  	  
  }else{
	  if(a > a2)
	  	cout << "A" << endl;
	  else
	  	cout << "B" << endl;
  }  
  
  return 0;
}
