#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
 
#include <bits/stdc++.h>
 
using namespace std;
  
const int BS_N = 5001;
const int BS_BASE = 32;
const int BS_POW2 = 5;
 
struct BitSet{
	int n_bs;
    vector<uint32_t> a;
    BitSet(){
		n_bs = (BS_N + BS_BASE - 1) / BS_BASE;
        a.resize(n_bs, 0);			
	}
    void set(int i) {
        int j = i >> BS_POW2;
        a[j] |= 1 << (i - (j << BS_POW2));
    }
};
 
int count(const BitSet &a, const BitSet &b) {
    int ans = 0;
    for (int i = 0; i < a.n_bs; i++)
        ans += __builtin_popcount(a.a[i] & b.a[i]);
    return ans;
} 

int main(){
	return 0;
}
