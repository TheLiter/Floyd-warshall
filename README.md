# Floyd-warshall algorithm

#### 플로이드 와샬 알고리즘

플로이드 와샬은 반복문을 3번 돌려서 최단경로를 얻을 수 있는 알고리즘입니다.

연산량은 O(|V|^3)이라는 연산량을 가지고, 컴퓨터가 1초에 처리하는 연산량이 1억 정도라 할 때,

정점의 수가 1000개 이상이라면? 즉, n = 1000이라면 1초 이상의 연산 시간이 걸릴 수 있습니다.

네비게이션에서 목적지까지의 최소비용을 출력하려하는데, 1초 이후에 값이 나오면 빠른 한국인의 특성상 뭔가 불편할 것입니다.

각설하고! 플로이드 와샬 알고리즘을 구현한 코드는 다음과 같습니다.

```c
#include <cstdio>    
    
int adj[20][20], INF = 1e4;    
    
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
    for(int j=1; j<=n; j++)    
      adj[i][j] = adj[i][j]?adj[i][j]:INF;    
    
  for(int i=1; i<=n; i++) {    
    for(int j=1; j<=n; j++) {    
      for(int k=1; k<=n; k++) {    
        if(adj[j][k] > adj[j][i] + adj[i][k]) {    
          adj[j][k] = adj[j][i] + adj[i][k];    
        }    
      }    
    }    
  }    
    
  printf(adj[1][n] != INF ? "%d" : "-1", adj[1][n]);    
    
  return 0;    
}  
```


원리는 간단합니다. j -> k로 가는 경로보다 j -> i -> k로 가는 경로의 비용이 더 작으면 값을 갱신해 줍니다.

최종적으로 배열에 저장되는 것은 제일 첫번째 인덱스. 즉, G[n][1]번째에 정점1부터 정점n까지의 최단경로가 저장되게 됩니다.

참고자료 :
<https://koosaga.com/2>,
<https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm>
