#include<cstdio>

int U[10001];
int find(int x) { if(U[x]!=x) U[x]=find(U[x]); return U[x]; }

int main()
{
  int n, m, s=-1;
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; ++i) U[i]=i;
  for(int i=0; i<m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    U[find(a)] = find(b);
  }
  for(int i=1; i<=n; ++i) s+=find(i)==i;
  printf("%d\n", s);
  return 0;
}
