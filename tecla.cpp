/**
* fname: COMENCINI
* lname: DIEGO
* task:  tecla
* score: 100.0
* date:  2018-07-25
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cassert>
#include <cstdio>

#define MAXN 1000000

using namespace std;


vector <int> adiacenza[MAXN];


int visto[MAXN];
int s[MAXN];
int ciclo[MAXN];

int pos = 0;

int N,M,L;

int passeggiata(int node, int mio_s){
    if(visto[node]){
        if(s[node] != mio_s){
            ciclo[pos++] = node;
            L = pos;
            return 1;
        }
        else
            return 0;

    }
    visto[node] = 1;
    s[node] = mio_s;
    ciclo[pos++] = node;

    //scorro la lista di adiacenza
    vector<int>::iterator i;
    for(i = adiacenza[node].begin(); i < adiacenza[node].end(); i++){
         if(passeggiata(*i, 1-mio_s))
                    return 1;
    }
    pos--;
    return 0;
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        int a;
        int b;
        scanf("%d", &a);
        scanf("%d", &b);
        adiacenza[a].push_back(b);
        adiacenza[b].push_back(a);
    }
    passeggiata(0,0);
    int doppia = ciclo[ L - 1];

    int ripeti = 0;
    for(int i=L-2; i>=0; i--){
        if(ripeti)
            ciclo[L++] = ciclo[i];
        if(ciclo[i] == doppia)
            ripeti = 1;

    }

    printf("%d\n",L-1);
    for(int i = 0; i<L; i++)
        printf("%d ",ciclo[i]);
    printf("\n");

    return 0;


}
