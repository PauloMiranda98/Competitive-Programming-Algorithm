#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int numbersBanks,numbersDebentures,i=0,j=0,monetaryReserve[1000];
	
	int debtorBank,creditorBank,valorDebenture;
	
	bool centralBank = false;
	
	while (true){
		
		cin >> numbersBanks >> numbersDebentures;
		
		if ( (numbersBanks==0) && (numbersDebentures==0) )
			break;
		
		for(i=0;i<numbersBanks;i++){
			cin >> monetaryReserve[i];
		}
		
		for(j=0;j<numbersDebentures;j++){
				
			cin >> debtorBank >> creditorBank >>valorDebenture;
				
			monetaryReserve[creditorBank-1] +=valorDebenture;
			monetaryReserve[debtorBank-1] -= valorDebenture;
				
		}
		for(j=0;j<numbersBanks;j++){
			if(monetaryReserve[j]<0)
				centralBank = true;
		}
		if(centralBank){
			cout << "N\n";
			centralBank = false;
		}else{
			cout << "S\n";
			centralBank = false;
		}
	}
	return 0;
}
