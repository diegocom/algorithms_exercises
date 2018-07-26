/**
* fname: COMENCINI
* lname: DIEGO
* task:  longwalk
* score: 100.0
* date:  2018-07-25
*/
#include <cassert>
#include <cstdio>
#include <vector>
#include <fstream>

using namespace std;

const int MAXN = 1000000;

vector<int> list[MAXN+1]; // list[v] = lista dei nodi testa degli aschi uscenti da v

int count[MAXN+1]; // count[v] = massima lunghezza di un cammino che parte da v
int next_node[MAXN+1];  // memorizza il prossimo nodo nel cammino o nel ciclo

int open[MAXN+1], close[MAXN+1], t = 0;
vector<int> cycle;

int first_node = 0; // non ancora trovato il primo nodo di un qualche ciclo
int dfs(int node) {
  if(open[node] > 0)
    if(close[node] > 0)
      return count[node];
    else {
      first_node = node;
      cycle.push_back(node);
      return count[node] = MAXN+2;
    }
  open[node] = ++t;
  int max_children = 0;
  for(int v : list[node]) {
     int risp = dfs(v);
     if(risp > MAXN+1) {
       cycle.push_back(node);
       return count[node] = MAXN+2;
     }
     if(risp > max_children) {
       max_children = risp;
       next_node[node] = v;
     }
  }
  close[node] = ++t;
  return count[node] = 1 + max_children;
}


int main() {
  ifstream in("input.txt");
  assert( in );

	//-------------- Lettura da file ---------------
  int N, M;
  in >> N >> M;

  freopen("output.txt", "w", stdout);
  for(int i = 1; i <= N; i++) { // added sentinel node 0
    list[0].push_back(i);
  }

	for(int i = 0; i < M; i++) {
    int t, h;
		in >> t >> h;
		list[t].push_back(h);
	}

  dfs(0);

  if(count[0] <= N+1) {
    printf("%d\n", count[0] -1);
    int node = 0;
    for(int i = 0; i < count[0] -1; i++)
       printf("%d ", node=next_node[node]);
  }
  else {
    int v;
    do{
      v = cycle.back();
      cycle.pop_back();
    } while(v!= first_node);
    printf("-1 %d\n", cycle.size());
    while(!cycle.empty()) {
      int v = cycle.back();
      cycle.pop_back();
      printf("%d ",v);
    }
    printf("\n");
  }

  return 0;
}
