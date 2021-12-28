# Floyd-warshall algorithm

플로이드 와샬은 반복문을 3번 돌려서 최단경로를 얻을 수 있는 알고리즘입니다.

<pre>
<code>
void Floyd()
{
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      for(int k=1; k<=n; k++) {
        if(G[j][k] > G[j][i] + G[i][k]) {
          G[j][k] > G[j][i] + G[i][k];
        }
      }
    }
  }
}
</code>
</pre>

원리는 간단합니다. j -> k로 가는 경로보다 j -> i -> k로 가는 경로의 비용이 더 작으면 값을 갱신해 줍니다.

최종적으로 배열에 저장되는 것은 제일 첫번째 인덱스. 즉, G[n][1]번째에 정점1부터 정점n까지의 최단경로가 저장되게 됩니다.


참고자료 :
<https://koosaga.com/2>,
<https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm>
