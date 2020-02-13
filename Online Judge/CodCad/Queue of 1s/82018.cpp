#include <iostream>
#include <algorithm>

using namespace std;


bool is_power_of_two(long long int x){
  if(x == 0)  return 0;
  return ((x&(x + 1)) == 0);
}

int main(){

	long long int n;	
	
	cin >> n;
	
	if(is_power_of_two(n))
		cout << "S" << endl;
	else
		cout << "N" << endl;
	
	return 0;
}