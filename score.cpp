#include<cstdio>

int main()
{
  int n, s[100000], f[102]={0};
  scanf("%d", &n);
  for(int i=0; i<n; ++i) scanf("%d", &s[i]), f[s[i]]++;
  for(int i=100; i>=0; --i) f[i]+=f[i+1];
  for(int i=0; i<n; ++i) printf("%d\n", f[s[i]+1]+1);
  return 0;
}
