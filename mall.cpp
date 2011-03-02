#include<cstdio>
#include<algorithm>

int c[1024][1024], d[1024][1024];

int main()
{
  int m, n, a, b, s=1<<30;
  scanf("%d%d%d%d", &m, &n, &a, &b);
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
      scanf("%d", &c[i][j]), d[i][j]=c[i][j]<0;
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
      c[i][j] = c[i-1][j]+c[i][j-1]-c[i-1][j-1]+c[i][j],
      d[i][j] = d[i-1][j]+d[i][j-1]-d[i-1][j-1]+d[i][j];
  for(int i=b; i<=n; ++i)
    for(int j=a; j<=m; ++j)
      if(d[i][j]-d[i-b][j]-d[i][j-a]+d[i-b][j-a]==0)
        s = std::min(s, c[i][j]-c[i-b][j]-c[i][j-a]+c[i-b][j-a]);
  printf("%d\n", s);
  return 0;
}
