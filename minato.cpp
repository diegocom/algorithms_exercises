/**
* fname: COMENCINI
* lname: DIEGO
* task:  minato
* score: 100.0
* date:  2018-07-25
*/
#include <stdio.h>
#include <stdbool.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>

int N,M;
int main(int argc, char const *argv[]) {

    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);

    scanf("%d%d", &N, &M);
    int possible_path[N][M];
    int map[N][M];
    getchar();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char a = getchar();

            if(a == '*'){
                map[i][j] = 1;
            }
            else if(a == '+'){
                map[i][j] = 0;
            }
            else{
                printf("Errore in lettura: letto (%c)\n", a);
                return 0;
            }
        }
        getchar();


    possible_path[0][0] = map[0][0];

    for(int i = 1; i < N; i++){
        int j = 0;
        possible_path[i][j] = map[i][j]*(possible_path[i-1][j]);
    }

    for(int j = 1; j < M; j++){
        int i = 0;
        possible_path[i][j]  = map[i][j]*(possible_path[i][j-1]);
    }


    for(int i = 1; i < N; i++){
        for(int j = 1; j < M; j++){
            possible_path[i][j] = map[i][j]*(possible_path[i-1][j] + possible_path[i][j-1]);
        }
    }

    printf("%d\n",possible_path[N-1][M-1]);
    return 0;
}
