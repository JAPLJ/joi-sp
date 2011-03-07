#include<cstdio>
#include<algorithm>

struct weapon {
  int a, x, y, i;
  weapon() :  x(-1), y(-1) { }
  static bool cmp_a(const weapon& a, const weapon& b) { return a.a<b.a; }
  static bool cmp_i(const weapon& a, const weapon& b) { return a.i<b.i; }
} A[50000];
struct wall {
  int x, y, w;
} W[50000];
bool operator <(const wall& a, const wall& b) { return a.y!=b.y ? a.y<b.y : a.x<b.x; }
struct segtree {
  int N;
  struct seg { int max, add; } *S;
  segtree(int n) : N(n), S(new seg[4*n+50]) { init(1, 1, n+1); }
  void init(int x, int l, int r) {
    S[x].max = S[x].add = 0;
    if(r-l==1) return;
    init(2*x, l, (l+r)/2);
    init(2*x+1, (l+r)/2, r);
  }
  void add(int l, int r) { add(l, r, 1, 1, N+1); }
  void add(int l, int r, int x, int L, int R) {
    if(L==l && R==r) {
      S[x].add++; S[x].max++;
      return;
    }
    int mid = (L+R)/2;
    if(l<mid) add(l, std::min(r, mid), 2*x, L, mid);
    if(r>mid) add(std::max(l, mid), r, 2*x+1, mid, R);
    S[x].max = S[x].add + std::max(S[2*x].max, S[2*x+1].max);
  }
  int maxpos() {
    int x=1, l=1, r=N+1;
    while(r-l>1) {
      if(S[2*x].max == S[x].max-S[x].add) { x*=2; r=(l+r)/2; }
      else { x=x*2+1; l=(l+r)/2;}
    }
    return l;
  }
} S(100000);

int main()
{
  int N, M;
  scanf("%d%d", &N, &M);
  for(int i=0; i<N; ++i) scanf("%d%d%d", &W[i].x, &W[i].y, &W[i].w);
  for(int i=0; i<M; ++i) scanf("%d", &A[i].a), A[i].i=i;
  std::sort(W, W+N); std::sort(A, A+M, weapon::cmp_a);
  for(int w=0, a=0; w<N && a<M; ++w) {
    S.add(W[w].x, W[w].x+W[w].w);
    while(a<M && S.S[1].max>A[a].a) {
      A[a].x = S.maxpos();
      A[a++].y = W[w].y;
    }
  }
  std::sort(A, A+M, weapon::cmp_i);
  for(int i=0; i<M; ++i) printf("%d %d\n", A[i].x, A[i].y);
  return 0;
}
