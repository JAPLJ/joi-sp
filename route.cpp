#include<cstdio>

bool ok[100][100][100];
int adj[100][100], d[10000], used[10000];
int main()
{
  int n, m, x[100], y[100];
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; ++i) scanf("%d%d", &x[i], &y[i]);
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) d[i*n+j] = adj[i][j] = 1<<29;
  for(int i=0; i<m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); a--; b--;
    adj[a][b] = adj[b][a] = c;
  }
  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      for(int k=0; k<n; ++k)
        ok[i][j][k] = 1ll*(x[j]-x[i])*(x[k]-x[j])+1ll*(y[j]-y[i])*(y[k]-y[j])>=0;
  d[0] = 0;
  for(int i=0; i<n*n; ++i) {
    int u = -1;
    for(int j=0; j<n*n; ++j)
      if(!used[j] && (u<0 || d[j]<d[u])) u=j;
    if(u/n == 1) break;
    used[u] = 1;
    for(int j=0; j<n; ++j) {
      if(adj[u/n][j] < 1<<29 && ok[u%n][u/n][j]) {
        int cost = d[u] + adj[u/n][j], v = j*n+u/n;
        if(d[v] > cost) d[v] = cost;
      }
    }
  }
  int sol = 1<<29;
  for(int i=0; i<n; ++i) if(sol>d[n+i]) sol = d[n+i];
  printf("%d\n", sol<1<<29 ? sol : -1);
  return 0;
}
