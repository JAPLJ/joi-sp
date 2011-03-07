#include<cstdio>
#include<algorithm>

struct edge { int a, b, c; } E[100000];
bool operator <(const edge& e, const edge& f) { return e.c<f.c; }

int U[100001];
int find(int x) { if(U[x]!=x) U[x]=find(U[x]); return U[x]; }

int main()
{
  int N, M, K, sol=0;
  scanf("%d%d%d", &N, &M, &K);
  for(int i=1; i<=N; ++i) U[i]=i;
  for(int i=0; i<M; ++i) scanf("%d%d%d", &E[i].a, &E[i].b, &E[i].c);
  std::sort(E, E+M);
  for(int i=0, c=N; i<M&&c>K; ++i) {
    if(find(E[i].a)!=find(E[i].b)) {
      sol += E[i].c; c--;
      U[find(E[i].a)] = find(E[i].b);
    }
  }
  printf("%d\n", sol);
  return 0;
}
