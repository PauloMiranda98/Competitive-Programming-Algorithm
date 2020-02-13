#include <iostream>

using namespace std;

int main ()
{
    // a variAvel 'n' serve para determinar a  quantidade de nAomeros sorteados
    // a vriAvel 'i' serve para percorrer o vetor e fazer a comparaAAo entre os nAomeros digitados
    //'r' serve para imprimir o resultado em pontos que o usuArio obteve
    //'sm' serve para mudar a posiAAo do vetor 's' sempre que o resultado da comparaAAo feita no for que tem 'i' como parametro for falsa
    //o vetor 's' serve para armazenar a soma de nAomeros repetentes e consecutivos
    //r irA armazenar o maior valor de 's' (no caso, a pontuaAAo do jogador)
    //'v' serve para armazenar os nAomeros do sorteio
    // qualquer coisa pergunta aA no zap kkk
    // e desculpa pelo incA modo kkk :)
    
    int n, i, sm = 0, r = 0;
    std::cin >> n;
    i = n ;
    
    int s[10000];
    long double v[10000];

	n = n - 1;
	
    for ( ; n >= 0 ; n--)
    {
        std::cin >> v[n];
        s[n] = 1 ;
    }

	i = i - 1;
	
    for (; i - 1 >= 0 ; i--)
    {
        if (i != 0){
            if (v[i] == v[i - 1]){
                s[sm] += 1;
            }
            else
            {
                sm += 1;
            }

        }

        if (i != 0){
            if (s[sm] > r)
            {
                r = s[sm];
            }
        }

    }

    std::cout << r << std::endl;

    return 0;
}
