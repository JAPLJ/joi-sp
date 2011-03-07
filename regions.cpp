#include<cstdio>
#include<vector>
#include<algorithm>

struct edge { int v, c; edge *p; } *adj[1<<15], pool[1<<16];
int dfs(int u, int d, int& m, int p=-1)
{
  int n=2, ret=0;
  std::vector<int> tmp(2, 0);
  for(edge *e=adj[u]; e; e=e->p)
    if(e->v!=p) tmp.push_back(dfs(e->v, d, m, u)+e->c), n++;
  std::sort(tmp.begin(), tmp.end());
  for(ret=tmp[--n]; ret+tmp[n-1]>d; ++m) ret=tmp[--n];
  return ret;
}

int main()
{
  int N, M, E=0;
  scanf("%d%d", &N, &M);
  for(int i=0; i<N-1; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); a--; b--;
    edge *x = &pool[E++];
    x->v=b; x->c=c; x->p=adj[a]; adj[a]=x;
    edge *y = &pool[E++];
    y->v=a; y->c=c; y->p=adj[b]; adj[b]=y;
  }
  int lo=-1, hi=100*N, m;
  while(hi-lo>1) {
    m = 1; dfs(0, (hi+lo)/2, m);
    (m <= M ? hi : lo) = (hi+lo)/2;
  }
  printf("%d\n", hi);
  return 0;
}
