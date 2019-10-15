#include <bits/stdc++.h>

const int MAXN = 500010;
const int MAXK = 18;

using namespace std;
typedef pair<int, int> pii;

//int memoC[MAXK][MAXN];

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;

	vector<int> p(n), c(n), cnt(max(alphabet, n), 0);

    for(int i = 0; i < n; i++)
        cnt[s[i]]++;
    for(int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for(int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
//	memoC[0][p[0]] = 0;
    int classes = 1;
    for(int i = 1; i < n; i++) {
        if(s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
//        memoC[0][p[i]] = classes - 1;
    }

	vector<int> pn(n), cn(n);
    for(int h = 0; (1 << h) < n; ++h) {
        for(int i = 0; i < n; i++){ //Ordenando pelo second no RadixSort
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for(int i = 0; i < n; i++)
            cnt[c[p[i]]]++;
        for(int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for(int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
//        memoC[h+1][p[0]] = 0;
        classes = 1;
        for(int i = 1; i < n; i++) {
            pii cur = pii(c[p[i]], c[(p[i] + (1 << h)) % n]);
            pii prev = pii(c[p[i-1]], c[(p[i-1] + (1 << h)) % n]);
            if(cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
//			memoC[h+1][p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());

    return sorted_shifts;
}

vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for(int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for(int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

//Comparar duas substring
/*int compare(int i, int j, int l, int k, int n) {
    pii a = pii(memoC[k][i], memoC[k][(i+l-(1 << k))%n]);
    pii b = pii(memoC[k][j], memoC[k][(j+l-(1 << k))%n]);
    return a == b ? 0 : a < b ? -1 : 1;
}*/

int main() {
	string s;
	cin >> s;

	vector<int> suff = suffix_array_construction(s);
	vector<int> lcp = lcp_construction(s, suff);
	
	for(int i=0; i<(int)s.size(); i++){
		cout << s.substr(suff[i]) << endl;
		
		if(i < (int)lcp.size())
			cout << lcp[i] << endl;
	}
	
	return 0;	
}
