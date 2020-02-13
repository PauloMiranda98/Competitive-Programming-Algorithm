#include <iostream>
#include <algorithm>

using namespace std;

struct t_aresta{
    int dis;
    int x, y;
};

bool comp(t_aresta a, t_aresta b){ return a.dis < b.dis; }

//--------------------
#define MAXN 501
#define MAXM 200200

int n, f, r; // numero de vertices e arestas
t_aresta aresta[MAXM];

// para o union find
int pai[MAXN];
int peso[MAXN];

// a arvore
t_aresta mst[MAXM];
//--------------------

// funcoes do union find
int find(int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b){
    
    a = find(a);
    b = find(b);
    
    if(peso[a] < peso[b]) pai[a] = b;
    else if(peso[b] < peso[a]) pai[b] = a;
    else{
        pai[a] = b;
        peso[b]++;
    }
    
}


int main(){
    
    long int cont = 0;
    
    // ler a entrada
    cin >> n >> f >> r;
    
    for(int i = 1;i <= f;i++)
        cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;
    
    sort(aresta+1, aresta+f+1, comp);
    
    for(int i = f+1;i <= r+f;i++)
        cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;

    sort(aresta+f+1, aresta+f+r+1, comp);

    
    // inicializar os pais para o union-find
    for(int i = 1;i <= n;i++) pai[i] = i;
        
    int size = 0;
    for(int i = 1;i <= r+f;i++){
        
        if( find(aresta[i].x) != find(aresta[i].y) ){ // se estiverem em componentes distintas
            join(aresta[i].x, aresta[i].y);
            
            cont += aresta[i].dis;
        }
        
    }
    
    cout << cont << endl;
    
    return 0;
}