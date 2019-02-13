#include <bits/stdc++.h>

using namespace std;

struct MedianDinamic{
	priority_queue<int> men; //smallest numbers
	priority_queue<int, vector<int>, greater<int> > mai; //largest numbers

	// median() --> O(1)
	int median(){
		if(men.size() > mai.size())
			return men.top();
		else
			return (men.top() + mai.top())/2;
	}

	// push_median(x) --> O(1)
	void pushMedian(int x){
		if(men.size() <= mai.size())
			men.push(x);
		else
			mai.push(x);
			
		if((!mai.empty()) and (!men.empty())){
			while(men.top() > mai.top()){
				int a = mai.top(); mai.pop();
				int b = men.top(); men.pop();
				
				mai.push(b);
				men.push(a);
			}
		}	
	}

};

MedianDinamic md;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x;
	
	while(cin >> x){
		md.pushMedian(x);
		cout << md.median() << endl;	
	}
				
	return 0;
	
}
