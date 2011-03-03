#include<cstdio>
#include<algorithm>

int n, m, x[100000], y[100000];
int cnt(int *p, int d)
{
  int cur=p[0], ret=1;
  for(int i=1; i<m; ++i) if(p[i]-cur>d) ret++, cur=p[i];
  return ret;
}

int main()
{
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; ++i) scanf("%d%d", &x[i], &y[i]);
  std::sort(x, x+m); std::sort(y, y+m);
  int lo=-1, hi=1000000000;
  while(hi-lo>1) (cnt(x, (hi+lo)/2)+cnt(y, (hi+lo)/2)<=n ? hi : lo) = (hi+lo)/2;
  printf("%d\n", hi);
  return 0;
}
