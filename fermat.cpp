#include<cstdio>

int main()
{
  int p, m=0, n, v[10000], f[10000]={0};
  scanf("%d%d", &p, &n);
  for(int i=0; i<p; ++i) {
    int x=i, y=1;
    for(int e=n; e; x=x*x%p, e>>=1) if(e&1) y=y*x%p;
    v[i]=y; f[y]++;
  }
  for(int i=0; i<p; ++i) m+=f[v[i]]+f[(v[i]+1)%p]*(p-1);
  printf("%d\n", m);
  return 0;
}
