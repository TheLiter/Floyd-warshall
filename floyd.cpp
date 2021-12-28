#include <cstdio>
#include <vector>

using namespace std;

int adj[20][20], path[20][20], INF = 1e4;

vector<int> SP;

void fp(int from, int to) {
  int prev = path[from][to];
  if(from == prev) {
    SP.push_back(from);
    return;
  }

  fp(from, prev);
  fp(prev, to);
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    adj[a][b] = adj[b][a] = w;
  }

  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++) {
      adj[i][j] = adj[i][j]?adj[i][j]:INF;
      path[i][j] = i;
    }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      for(int k=1; k<=n; k++) {
        if(adj[j][k] > adj[j][i] + adj[i][k]) {
          adj[j][k] = adj[j][i] + adj[i][k];
          path[j][k] = i;
        }
      }
    }
  }

  if(adj[1][n] != INF) {
    printf("%d\n", adj[1][n]);
  } else {
    printf("-1\n");
    return 0;
  }

  fp(1, n);
  SP.push_back(n);
  for(int i=0; i<SP.size(); i++) {
    printf("%d ", SP[i]);
  }

  return 0;
}
