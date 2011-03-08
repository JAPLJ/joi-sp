#include<cstdio>

int no[3050][3050], x[3050], s[3050];
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; ++i) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    no[a][c]++; no[b+1][c]--; no[a][d+1]--; no[b+1][d+1]++;
  }
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j)
      x[i] += !(no[i][j] += no[i-1][j]+no[i][j-1]-no[i-1][j-1]);
  for(int i=1; i<=n; ++i) {
    int p = -1, q = -1;
    for(int j=1; p<0&&j<=n; ++j)
      if(x[j]==1) p=j;
    for(int j=1; q<0&&j<=n; ++j)
      if(no[p][j]==0) q=j;
    s[p] = q;
    for(int j=1; j<=n; ++j)
      if(no[j][q]==0) x[j]--, no[j][q]=1;
  }
  for(int i=1; i<=n; ++i) printf("%d\n", s[i]);
  return 0;
}
