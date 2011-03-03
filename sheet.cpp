#include<cstdio>
#include<algorithm>

using namespace std;

int N, V, pict[100][100], adj[1000][1000], mx[2][1000], my[2][1000], vis[1000];
void dfs(int u)
{
  if(vis[u]) return; vis[u]=1;
  for(int i=0; i<N; ++i) if(adj[u][i]) dfs(i);
  printf("%d%c", u+1, ++V==N?'\n':' ');
}

int main()
{
  int W, H, c;
  scanf("%d%d%d", &N, &W, &H);
  for(int i=0; i<H; ++i)
    for(int j=0; j<W; ++j) scanf("%d", &pict[i][j]);
  for(int i=0; i<N; ++i)
    mx[0][i] = my[0][i] = 100;
  for(int i=0; i<H; ++i) {
    for(int j=0; j<W; ++j) {
      if((c=pict[i][j]-1) >= 0) {
	mx[0][c] = min(mx[0][c], j); mx[1][c] = max(mx[1][c], j);
	my[0][c] = min(my[0][c], i); my[1][c] = max(my[1][c], i);
      }
    }
  }
  for(int i=0; i<N; ++i)
    for(int y=my[0][i]; y<=my[1][i]; ++y)
      for(int x=mx[0][i]; x<=mx[1][i]; ++x)
	if((c=pict[y][x]-1) >= 0 && c!=i) adj[c][i]=1;
  for(int i=0; i<N; ++i) dfs(i);
  return 0;
}
