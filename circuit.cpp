#include<cstdio>

int gcd(int m, int n) {
  return n ? gcd(n, m%n) : m;
}

int main()
{
  int n, k, a[10001], target[10001], d[10001], s[10001], v[10001] = {0};
  scanf("%d%d", &n, &k);
  for(int i=1; i<=n; ++i) scanf("%d", &a[i]), target[a[i]]=i;
  for(int i=1; i<=n; ++i) {
    if(v[i]) continue;
    int m = 0, p = i, tmp[10001];
    do {
      d[m++] = p;
      p = target[p];
    } while(p != i);
    if(gcd(m, k) != 1) { puts("0"); return 0; }
    for(int j=0; j<m; ++j) tmp[(j*k)%m] = d[j];
    for(int j=0; j<m; ++j) s[tmp[(j+1)%m]] = tmp[j];
  }
  for(int i=1; i<=n; ++i) printf("%d\n", s[i]);
  return 0;
}
