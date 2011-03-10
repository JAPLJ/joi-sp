#include<cstdio>

struct edge { int v; edge *p; } *adj[100000], *rev[100000], pool[200050];
int N, M, V, S, scc[100000], ord[100000], ind[100000];

void dfs(int u, edge *g[], int *o, int *v, int k)
{
  if(v[u]>=0) return;
  v[u]=k;
  for(edge *e=g[u]; e; e=e->p)
    dfs(e->v, g, o, v, k);
  o[V++] = u;
}

int main()
{
  scanf("%d%d", &N, &M);
  for(int i=0; i<M; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    edge *x = &pool[2*i];
    x->v=b; x->p=adj[a]; adj[a]=x;
    edge *y = &pool[2*i+1];
    y->v=a; y->p=rev[b]; rev[b]=y;
  }
  for(int i=0; i<N; ++i) scc[i] = -1;
  for(int i=0; i<N; ++i) dfs(i, adj, ord, scc, i);
  for(int i=0; i<N; ++i) scc[i] = -1;
  V = 0;
  for(int i=N-1; i>=0; --i)
    if(scc[ord[i]]<0) dfs(ord[i], rev, ind, scc, S++);
  for(int i=0; i<S; ++i) ind[i] = 0;
  for(int i=0; i<N; ++i)
    for(edge *e=adj[i]; e; e=e->p)
      if(scc[i]!=scc[e->v]) ind[scc[e->v]] = 1;
  int sol = 0;
  for(int i=0; i<S; ++i) sol += !ind[i];
  printf("%d\n", sol);
  return 0;
}
