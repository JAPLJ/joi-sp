#include<cstdio>
#include<algorithm>

struct edge { int v; edge *p; } *adj[100050], pool[200050];
struct BIT {
  int N, *S;
  BIT(int n=0) : N(n) { S = new int[n+2]; for(int i=0; i<=n; ++i) S[i]=0; }
  int sum(int x) { int s=0; for(; x>0; x-=x&-x) s+=S[x]; return s; }
  void update(int x, int v) { for(; x<=N; x+=x&-x) S[x]+=v; }
  void add(int l, int r, int v) { update(l, v); update(r, -v); }
} up, dw;
int N, M, E, P[100050], Q[100050], S[100050], T[100050];
int height[100050], id_new[100050], id_old[100050], R[100050];

void dfs_id(int u, int& id, int h=0, int p=-1)
{
  id_old[id_new[u] = id++] = u;
  height[id_new[u]] = h;
  for(edge *e=adj[u]; e; e=e->p) {
    if(e->v!=p) dfs_id(e->v, id, h+1, u);
    e->v=id_new[e->v];
  }
  R[id_new[u]] = id;
}

void update_info(int r, int s, int t)
{
  if(height[Q[r]] > height[P[r]]) {
    up.add(Q[r], R[Q[r]], -T[r]); up.add(Q[r], R[Q[r]], T[r]=t);
    dw.add(Q[r], R[Q[r]], -S[r]); dw.add(Q[r], R[Q[r]], S[r]=s);
  } else {
    up.add(P[r], R[P[r]], -S[r]); up.add(P[r], R[P[r]], S[r]=s);
    dw.add(P[r], R[P[r]], -T[r]); dw.add(P[r], R[P[r]], T[r]=t);
  }
}

struct lca { int u, v, w; lca *p; } *queries[100050], pool_q[100050];
struct UF {
  int N, *U;
  UF(int n=0) : N(n) { U=new int[n+2]; for(int i=1; i<=n; ++i) U[i]=i; }
  int find(int x) { if(U[x]!=x) U[x]=find(U[x]); return U[x]; }
  void uni(int x, int y) { U[find(x)]=find(y); }
} U;
int visited[100050], ancestor[100050], F;
void dfs_lca(int u, int p=-1)
{
  ancestor[U.find(u)] = u;
  for(edge *e=adj[id_old[u]]; e; e=e->p) {
    if(e->v==p) continue;
    dfs_lca(e->v, u);
    U.uni(u, e->v);
    ancestor[U.find(u)] = u;
  }
  visited[u] = 1;
  for(lca *q=queries[u]; q; q=q->p)
    q->w = ancestor[U.find(q->u)];
}

struct query { int type, r, s, t; lca *q; } X[100050];
int main()
{
  scanf("%d%d", &N, &M);
  for(int i=1; i<=N-1; ++i) {
    scanf("%d%d", &P[i], &Q[i]);
    edge *x = &pool[E++];
    x->v=Q[i]; x->p=adj[P[i]]; adj[P[i]]=x;
    edge *y = &pool[E++];
    y->v=P[i]; y->p=adj[Q[i]]; adj[Q[i]]=y;
  }
  int id = 1;
  dfs_id(1, id);
  up = BIT(N); dw = BIT(N);
  for(int i=1; i<=N-1; ++i) {
    P[i] = id_new[P[i]];
    Q[i] = id_new[Q[i]];
    update_info(i, 1, 1);
  }
  for(int i=0; i<M; ++i) {
    char s[2];
    scanf("%s", s);
    if(s[0]=='I') {
      X[i].type = 0;
      scanf("%d%d%d", &X[i].r, &X[i].s, &X[i].t);
    } else {
      X[i].type = 1;
      lca *q = &pool_q[F++];
      scanf("%d%d", &q->u, &q->v);
      q->u = id_new[q->u]; q->v = id_new[q->v];
      X[i].s = q->u; X[i].t = q->v;
      if(q->u > q->v) std::swap(q->u, q->v);
      q->p=queries[q->v]; queries[q->v]=q;
      X[i].q = q;
    }
  }
  U = UF(N);
  dfs_lca(1);
  for(int i=0; i<M; ++i) {
    if(X[i].type == 0) {
      update_info(X[i].r, X[i].s, X[i].t);
    } else {
      int u = X[i].s, v = X[i].t, w = X[i].q->w;
      printf("%d\n", up.sum(u)-up.sum(w)+dw.sum(v)-dw.sum(w));
    }
  }
  return 0;
}
