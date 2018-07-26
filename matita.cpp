/**
* fname: COMENCINI
* lname: DIEGO
* task:  matita
* score: 45.0
* date:  2018-07-25
*/
#include <stdio.h>
#include <stdbool.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdio>
#include <cassert>

struct Arco{
  int s;
  int e;
  bool burn;
};

int N,M,A,B,T;

void dfs(struct Arco problema[],int nodo, int prof, int sol[]);


int main(int argc, char const *argv[]) {


  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);

  scanf("%d%d%d%d", &N, &M, &A, &B);



  struct Arco archi[M];
  for(int i = 0; i < M; i++){
      int s,e;
      scanf("%d%d",&s,&e);
      archi[i].s = s;
      archi[i].e = e;
      archi[i].burn = false;
  }

  T = M + 1;
  int sol[T];
  for(int i = 0; i < T; i++){
    sol[i] = -1;
  }

  dfs(archi, A, M, sol);


  for(int i = 0; i < T-1; i++){
    printf("%d %d\n",sol[i], sol[i+1]);
  }


  return 0;
}



void dfs(struct Arco problema[], int nodo, int prof, int sol[]){

  if(nodo == B && prof == 0){

    sol[T-prof-1] = nodo;

    return;
  }
  else{

    for(int i = 0; i < M; i++){

      if(problema[i].burn == false){

        if(problema[i].s == nodo){
          problema[i].burn = true;
          dfs(problema, problema[i].e, prof-1, sol);

          if(sol[T-prof] != -1){

            sol[T-prof-1] = nodo;
            return;
          }
          else{
          	problema[i].burn = false;
		  }
        }

        else if(problema[i].e == nodo){
          problema[i].burn = true;
          dfs(problema, problema[i].s, prof-1, sol);

          if(sol[T-prof] != -1){

            sol[T-prof-1] = nodo;
            return;
          }
          else{
          	problema[i].burn = false;
		  }
        }


      }
    }


  }

}
