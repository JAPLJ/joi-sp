#include<cstdio>
#include<algorithm>

int main()
{
  int n, a[1024], dp[1024];
  scanf("%d", &n);
  for(int i=0; i<n; ++i) scanf("%d", &a[i]);
  for(int i=0; i<n; ++i) {
    dp[i] = 1;
    for(int j=0; j<i; ++j)
      if(a[i]>a[j] && dp[i]<=dp[j]) dp[i]=dp[j]+1;
  }
  printf("%d\n", *std::max_element(dp, dp+n));
  return 0;
}
