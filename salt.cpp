#include<cstdio>
#include"saltc.h"

struct edge { int v; edge *p; } *adj[1024], pool[4096];

int count(int u, int *vis, int *num, int p)
{
  vis[u] = num[u] = 1;
  for(edge *e=adj[u]; e; e=e->p)
    if(e->v!=p) num[u]+=count(e->v, vis, num, u);
  return num[u];
}

int get_grundy(int n)
{
  if(n == 0) return 0;
  else return 2 - n % 2;
}

void search(int u, int *vis, int *num, int n, int p, int g, int& su, int& sv)
{
  vis[u] = 1;
  int tmp_g = get_grundy(n-num[u]);
  for(edge *e=adj[u]; e; e=e->p)
    if(e->v!=p) tmp_g ^= get_grundy(num[e->v]);
  if((tmp_g ^ g) == 0) {
    su = sv = u;
    return;
  }
  for(edge *e=adj[u]; e; e=e->p) {
    if(e->v==p) continue;
    tmp_g = get_grundy(n-num[e->v]) ^ get_grundy(num[e->v]);
    if((tmp_g ^ g) == 0) {
      su = u; sv = e->v;
      return;
    }
    search(e->v, vis, num, n, u, g, su, sv);
    if(su >= 0) return;
  }
}

void destroy(int n, int u, int v)
{
  if(u==v) {
    for(int i=0; i<n; ++i) {
      for(edge *e=adj[i]; e&&e->p; e=e->p)
        if(e->p->v==u) e->p=e->p->p;
      edge *e=adj[i];
      if(e && e->v==u) adj[i] = e->p;
    }
  } else {
    for(edge *e=adj[u]; e&&e->p; e=e->p)
      if(e->p->v==v) e->p=e->p->p;
    for(edge *e=adj[v]; e&&e->p; e=e->p)
      if(e->p->v==u) e->p=e->p->p;
    edge *e=adj[u];
    if(e && e->v==v) adj[u] = e->p;
    edge *f=adj[v];
    if(f && f->v==u) adj[v] = f->p;
  }
}

int main()
{
  int n, e=0;
  scanf("%d", &n);
  for(int i=0; i<n; ++i)
    adj[i] = NULL;
  for(int i=0; i<n-1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    edge *x = &pool[e++];
    x->v=b; x->p=adj[a]; adj[a]=x;
    edge *y = &pool[e++];
    y->v=a; y->p=adj[b]; adj[b]=y;
  }
  int removed[1024] = {0}, n_rem = n;
  while(n_rem > 0) {
    int grundy[1024] = {0}, visited[1024] = {0}, num[1024];
    for(int i=0; i<n; ++i) {
      if(removed[i] || visited[i]) continue;
      grundy[i] = get_grundy(count(i, visited, num, -1));
    }
    int g = 0;
    for(int i=0; i<n; ++i) g ^= grundy[i], visited[i] = 0;
    int u=-1, v;
    for(int i=0; i<n; ++i) {
      if(removed[i] || visited[i]) continue;
      search(i, visited, num, num[i], -1, g ^ grundy[i], u, v);
      if(u>=0) break;
    }
    if(u>v) { int t=u; u=v; v=t; }
    if(u==v) n_rem--, removed[u] = 1;
    destroy(n, u, v);
    int ru, rv;
    turn(u+1, v+1, &ru, &rv);
    if(ru==rv) removed[ru-1] = 1;
    if(ru==0 && rv==0) break;
    destroy(n, ru-1, rv-1);
  }
  return 0;
}
