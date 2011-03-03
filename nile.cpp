#include<cstdio>
#include<algorithm>

int dp[400][3000][3], price[400][3000];
int main()
{
  int n, d;
  scanf("%d%d", &n, &d);
  for(int i=0; i<d; ++i)
    for(int j=0; j<n; ++j) scanf("%d", &price[i][j]);
  for(int i=0; i<n; ++i) dp[0][i][0]=price[0][i], dp[0][i][1]=dp[0][i][2]=1<<29;
  for(int i=1; i<=d; ++i) {
    int p = 1<<29;
    for(int j=0; j<n; ++j)
      for(int k=0; k<3; ++k) p=std::min(p, dp[i-1][j][k]);
    if(i==d) { printf("%d\n", p); break; }
    for(int j=0; j<n; ++j) {
      dp[i][j][0] = p + price[i][j];
      dp[i][j][1] = dp[i-1][j][0] + price[i][j] * 9/10;
      dp[i][j][2] = std::min(dp[i-1][j][1], dp[i-1][j][2]) + price[i][j] * 7/10;
    }
  }
  return 0;
}
