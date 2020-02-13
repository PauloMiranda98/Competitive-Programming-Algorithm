#include <iostream> 

using namespace std;

int main(){
  
  double a, b, altura;
  cin >> a >> b;
  
  altura = (a+b)/2; 
  
  if(altura >= 7 ){
    cout<<"Aprovado\n";
  }
  else{
    if(altura >= 4){
      cout<<"Recuperacao\n"; // A pessoa e considerada Normal
    }
    else{
      cout<<"Reprovado\n"; // A pessoa e considerada Baixa
    }
  }
  
  return 0;
}
