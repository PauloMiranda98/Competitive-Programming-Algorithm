#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	pair<int, int> vetor[3];
	
	cin >> vetor[0].first >> vetor[1].first >> vetor[2].first;

	vetor[0].second = 1;
	vetor[1].second = 2;
	vetor[2].second = 3;

	sort(vetor, vetor+3);	

	cout << vetor[0].second << endl;
	cout << vetor[1].second << endl;
	cout << vetor[2].second << endl;
		
	return 0;
		
}