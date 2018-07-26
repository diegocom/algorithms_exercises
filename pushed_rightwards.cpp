/**
* fname: COMENCINI
* lname: DIEGO
* task:  pushed_rightwards
* score: 100
* date:  2018-06-18
*/


#include <cassert>
#include <cstdio>
#include <algorithm>

#define MAXN 1000000

int N;
int g[MAXN]; // g[i] = numero celle in cella i-esima.
int t[MAXN]; // t[i] = troll treathening in cella i-esima.

int max_sum_g[MAXN];

int main() {
#ifdef EVAL
    assert( freopen("input.txt", "r", stdin) );
    assert( freopen("output.txt", "w", stdout) );
#endif
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
       scanf("%d", &g[i]);
    for(int i = 0; i < N; i++)
       scanf("%d", &t[i]);

    int max = 0;
    for(int i = N - 1; i >= 0; i--){
        if((i+t[i]+1) > N)
            max_sum_g[i] = g[i];
        else
            if(max > g[i] + max_sum_g[i+t[i]+1]){
                max_sum_g[i] = max;
            }
            else{
                max_sum_g[i] = g[i] + max_sum_g[i+t[i]+1];
                max =  g[i] + max_sum_g[i+t[i]+1];
            }

    }
    printf("%d\n", max_sum_g[0]);

    return 0;
}
