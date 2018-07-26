/**
* fname: COMENCINI
* lname: DIEGO
* task:  count_poldo
* score: 70.0
* date:  2018-07-25
*/
#include <cassert>
#include <cstdio>

#define MAXN 1000000

int N;

int X[MAXN];
int T[MAXN];

int main() {
#ifdef EVAL
  assert( freopen("input.txt", "r", stdin) );
  assert( freopen("output.txt", "w", stdout) );
#endif

  scanf("%d", &N);
    int count = 0;
    for(int i = 0; i < N; i++){
        scanf("%d",&X[i]);
        T[i] = 1;
        for(int k = i - 1; k >= 0; k--){
            if(X[k] == X[i]){
                T[i] = (T[i] + T[k] - 1) % 1024;
                break;
            }
            else if(X[k] < X[i]){
                T[i] = (T[i] + T[k]) % 1024;
            }
        }
        count  = (count + T[i]) % 1024;
    }

    printf("%d\n", count);

  return 0;
}
