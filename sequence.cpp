#include<cstdio>

typedef long long ll;
bool vis[50+1<<24];
char cycle[50+1<<24];
int sum(int p)
{
  int ret = 0;
  for(int i=0; i<p; ++i) ret+=cycle[i];
  return ret;
}

int main()
{
  int a, m, b = 0;
  ll p, q;
  scanf("%d%lld%lld", &m, &p, &q);
  for(int i=0; i<m; ++i) {
    scanf("%d", &a);
    b = (b<<1) | (cycle[i] = a&1);
  }
  int cnt=0, len=0;
  do {
    vis[b] = true;
    b = ((b<<1) & ((1<<m)-1)) | (!!(b & (1<<(m-1))) ^ (b & 1));
    cnt += (cycle[len+++m] = b&1);
  } while(!vis[b]);
  p--;
  printf("%lld\n", q/len*cnt+sum(q%len) - p/len*cnt-sum(p%len));
  return 0;
}
