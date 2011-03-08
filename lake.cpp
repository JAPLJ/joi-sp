#include<cstdio>
#include<algorithm>

int n, s[2000], t[2000], st[4000], link[4050], dp[4050][4050];

int main()
{
  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    scanf("%d%d", &s[i], &t[i]);
    st[2*i]=s[i]; st[2*i+1]=t[i];
  }
  std::sort(st, st+2*n);
  for(int i=0; i<n; ++i) {
    s[i] = std::lower_bound(st, st+2*n, s[i])-st+1;
    t[i] = std::lower_bound(st, st+2*n, t[i])-st+1;
    link[link[s[i]] = t[i]] = s[i];
  }
  for(int d=1; d<2*n; ++d) {
    for(int x=1; x+d<=2*n; ++x) {
      dp[x][x+d] = std::max(dp[x+1][x+d], dp[x][x+d-1]);
      if(x<=link[x]&&link[x]<=x+d) dp[x][x+d] = std::max(dp[x][x+d], 1+dp[x+1][link[x]-1]+dp[link[x]+1][x+d]);
      if(x<=link[x+d]&&link[x+d]<=x+d) dp[x][x+d] = std::max(dp[x][x+d], 1+dp[x][link[x+d]-1]+dp[link[x+d]+1][x+d]);
    }
  }
  printf("%d\n", dp[1][2*n]);
  return 0;
}
