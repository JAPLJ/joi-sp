#include<cstdio>
#include<algorithm>

int N, P, h[500000], dp[500000], sum[500000], M = 1234567;
int main()
{
  scanf("%d%d", &N, &P);
  for(int i=1; i<=N; ++i) scanf("%d", &h[i]), h[i]+=h[i-1];
  dp[0] = sum[0] = 1;
  for(int i=1, from=0; i<=N; ++i) {
    while(h[i]-h[from] > P) from++;
    dp[i] = (sum[i-1]-(from>0?sum[from-1]:0)+M) % M;
    sum[i] = (sum[i-1]+dp[i]) % M;
  }
  printf("%d\n", dp[N]);
  return 0;
}
