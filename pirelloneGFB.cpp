/**
* fname: COMENCINI
* lname: DIEGO
* task:  pirelloneGFB
* score: 84.0
* date:  2018-06-18
*/
#include <cassert>
#include <cstdio>
#include <cstdlib>


int M;
int N;
int B;
int pirellone[600][600];
int bntHorizontal[600];
int bntVertical[600];


int main(int argc, char *argv[]){
#ifdef EVAL
    assert( freopen("input.txt", "r", stdin) );
    assert( freopen("output.txt", "w", stdout) );
#endif
    scanf("%d",&M);
    scanf("%d",&N);
    scanf("%d",&B);
    int p_flag = 1;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            scanf("%d",&pirellone[i][j]);
            if(pirellone[i][j]>0)
                p_flag = 0;
        }
    }

    if(!p_flag){
        for (int i = 0; i < M; i++){
            if(pirellone[i][0] >= 1){
                bntVertical[i]  += 1;
                for(int j = 0; j < N; j++){
                    pirellone[i][j] = (pirellone[i][j]+1)%B;
                }
                if(pirellone[i][0] >=1)
                    i--;
            }
        }
        for(int i = 0; i < N; i++){
            if(pirellone[0][i]>=1){

                bntHorizontal[i]+=1;
                for(int j = 0; j < M; j++){
                    pirellone[j][i] = (pirellone[j][i]+1)%B;
                }
                if(pirellone[0][i] >= 1)
                    i--;
            }
        }
        int count = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                count = count + pirellone[i][j];
            }
        }
        if(count == 0){
            for(int i = 0; i < M; i++){
                printf("%d ",bntVertical[i]);
            }
            printf("\n");
            for(int i = 0; i < N; i++){
                 printf("%d ",bntHorizontal[i]);
            }
            printf("\n");
            return 0;
        }

    }

    for(int i = 0; i < M;i++){
             printf("0 ");
        }

    printf("\n");
    for(int i = 0; i < N; i++){
        printf("0 ");
    }

    printf("\n");

    return 0;
}
