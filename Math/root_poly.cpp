#include <bits/stdc++.h>

using namespace std;

//Newton's method

int n;			   // Grau of the f(x)
vector<double> vf; // f (x)
vector<double> vdf;// f'(x)

double f(double x){	
	double ans = 0;
	double e = 1;
	for(int i=0; i<vf.size(); i++){
		ans += vf[i] *  e;
		e *= x;
	}
	return ans;
}

double df(double x){	
	double ans = 0;
	double e = 1;
		
	for(int i=0; i<vdf.size(); i++){
		ans += vdf[i] * e;
		e *= x;	
	}
	return ans;
}

double root(double x0){
	const double eps = 1E-10;
	double x = x0;

	for (;;) {
		double nx = x - (f(x)/df(x));
		
		if (abs(x - nx) < eps)
			break;
		x = nx;
	}
	return x;	
}

void div(double a){ //div f(x) by (x-a)
	
	vector<double> aux(n);
	
	for(int i=n; i>=1; i--){
		aux[i-1] = vf[i];
		vf[i-1] += a*aux[i-1];
	}	
	vf = aux;
	
	n = n-1;

	//update f'(x)	
	vdf.resize(n);	
	for(int i=n; i>0; i--)	
		vdf[i-1] = i * vf[i];		
}

int main(){	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int caso = 1;	
	while(cin >> n){
		if(n == 0)
			break;
			
		vf.resize(n+1);
		vdf.resize(n);	

		for(int i=n; i>0; i--){
			cin >> vf[i];
			
			vdf[i-1] = i * vf[i];
		}	
		
		cin >> vf[0];
	
		vector<double> ans;
		
		for(int i=0; i<n; i++){			
			double x = root(1);
			ans.push_back(x);
			
			div(x);
		}
				
		sort(ans.begin(), ans.end());
		
		cout << "Equation " << caso++ << ":";
		
		for(double x: ans)
			cout << setprecision(4) << fixed << " " << x;
		
		cout << endl;
	}
	
	return 0;	
	
}
