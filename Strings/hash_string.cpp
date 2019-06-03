#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

const int hash_p = 31;
//const int hash_p = 53;
const int hash_mod = 1e9 + 9;


ll compute_hash(string s) {
    ll hash_value = 0;
    ll p_pow = 1LL;
    
    for(char c : s){
        hash_value = (hash_value + ll(c - 'a' + 1LL) * p_pow) % hash_mod;
        p_pow = (p_pow * (ll)hash_p) % hash_mod;
    }
    
    return hash_value;
}

int main() {
	string s;
	cin >> s;
	
	cout << compute_hash(s) << endl;

	return 0;
}
