/**
* fname: COMENCINI
* lname: DIEGO
* task:  triangolo
* score: 100.0
* date:  2018-07-25
*/
#include <stdio.h>

int main(int argc, char const *argv[]) {

  freopen("input.txt","r",stdin);
  freopen("output.txt","w", stdout);

  int N;
  scanf("%d",&N);
  int triangolo[N][N];


  for(int i = 0; i < N; i++){
    for(int j = 0; j <= i; j++){
      scanf("%d", &triangolo[i][j]);
    }
  }

  for(int i = N-1; i > 0; i--){
    for(int j = i; j > 0; j--){
      if(triangolo[i][j] > triangolo[i][j-1]){
        triangolo[i-1][j-1] += triangolo[i][j];
      }
      else{
        triangolo[i-1][j-1] += triangolo[i][j-1];
      }
    }
  }
  printf("%d",triangolo[0][0]);
  return 0;
}
