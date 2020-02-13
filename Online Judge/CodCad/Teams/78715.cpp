#include <bits/stdc++.h>

using namespace std;

class Jogador{
public:
    pair<string, int> P;
    Jogador(string nome, int habilidade){
        P.first = nome;
        P.second = habilidade;
    }

    struct LessThanByAge{
        bool operator()(const Jogador& lhs, const Jogador& rhs) const{
            return lhs.P.second > rhs.P.second;
        }
    };
};


int main(){

    int N, T, habilidade;
    string nome;
    vector<Jogador> vetor;

    cin >> N >> T;
    int aux = 0;

    while(aux < N){
        cin >> nome;
        cin >> habilidade;
        vetor.push_back(Jogador(nome, habilidade));
        aux++;
    }

    sort(vetor.begin(), vetor.end(), Jogador::LessThanByAge());

    vector<string> vetor_resultador [T];

    for (int i = 0; i < N; i++) {
        vetor_resultador[i % T].push_back(vetor[i].P.first);
    }

    aux = 0;
    while(aux < T){
        sort(vetor_resultador[aux].begin(), vetor_resultador[aux].end());
        cout << "Time " << aux + 1 << endl;
        for (int i = 0; i < vetor_resultador[aux].size(); i++)
            cout << vetor_resultador[aux][i] << endl;
        aux++;
        cout << endl;
    }

    return 0;
}

