#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

long long solve(int L, vector<int> up, vector<int> dw)
{
  sort(up.begin(), up.end()); sort(dw.begin(), dw.end());
  up.erase(unique(up.begin(), up.end()), up.end());
  dw.erase(unique(dw.begin(), dw.end()), dw.end());
  const int n = up.size(), m = dw.size();
  long long ret = 0;
  for(int i=0; i<n; ++i) ret += L - abs(up[i]-L+1);
  for(int i=0; i<m; ++i) ret += L - abs(dw[i]);
  for(int i=0; i<n; ++i) {
    int hi = up[i]<L ? up[i] : 2*L-1-up[i], lo = up[i]<L ? -up[i] : up[i]-2*(L-1);
    ret -= upper_bound(dw.begin(), dw.end(), hi) - lower_bound(dw.begin(), dw.end(), lo);
  }
  return ret;
}

int main()
{
  int l, n;
  vector<int> up[2], down[2];
  scanf("%d%d", &l, &n);
  for(int i=0; i<n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    up[(x+y)&1].push_back(y+x);
    down[(x+y)&1].push_back(y-x);
  }
  printf("%lld\n", solve(l, up[0], down[0])+solve(l, up[1], down[1]));
  return 0;
}
