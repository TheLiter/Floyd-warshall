#include <cstdio>

int n, m, adj[110][110], INF = 1e8;

int min(int a, int b) { return a<b?a:b; }

int main()
{
  scanf("%d%d", &n, &m);

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(i == j) adj[i][j] = 0;
      else adj[i][j] = INF;
    }
  }

  while(m--) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    adj[x-1][y-1] = min(adj[x-1][y-1], w);
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      for(int k=0; k<n; k++) {
        if(adj[j][k] > adj[j][i] + adj[i][k]) {
          adj[j][k] = adj[j][i] + adj[i][k];
        }
      }
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(adj[i][j] == INF) adj[i][j] = 0;
      printf("%d ", adj[i][j]);
    }
    puts("");
  }

  return 0;
}
