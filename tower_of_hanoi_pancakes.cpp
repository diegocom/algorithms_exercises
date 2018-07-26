/**
* fname: COMENCINI
* lname: DIEGO
* task:  tower_of_hanoi_pancakes
* score: 50.0
* date:  2018-07-25
*/


#include <cassert>
#include <cstdio>

#define MAXN 100

int N;
int flip[MAXN +1]; // flip[i] = 1 se nello spostamento della torre la frittalla i deve ritrovarsi flippata, flip[i] = 0 altrimenti.

void spostaDisco(int n, int from, int to) {
  printf("Muovi il disco %d dal piolo %d al piolo %d\n", n, from, to);
}

unsigned long long int num_mosse(int N){
    //ritorno numero di mosse per spostare una torre di N dischi
    assert(N >= 0);
    if(N==0) return 0;
    return 1 + 2 * num_mosse(N-1);
}


void spostaTorre(int N, int from, int to, int piolo_di_appoggio) {

    assert(N >= 0);
    if(N == 0) return;
    assert(N>=1);

    spostaTorre(N-1, from, piolo_di_appoggio, to);
    spostaDisco(N, from, to);
    spostaTorre(N-1, piolo_di_appoggio, to, from);


}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
       scanf("%d", &flip[i]);
    }


    // soluzione corretta per N=1 quando nessuna frittella debba ritrovarsi infine flippata:
    unsigned long long int mosse = num_mosse(N);

    printf("%llu\n", mosse*2);

    spostaTorre(N, 1, 2, 3);
    spostaTorre(N, 2, 3, 1);

    return 0;
}
