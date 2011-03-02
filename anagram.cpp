#include<cstdio>

typedef long long ll;

int main()
{
  char s[32];
  ll sol=1, fact[21];
  int n, f[32] = {0};
  fact[0]=1;
  for(int i=1; i<=20; ++i) fact[i]=fact[i-1]*i;
  scanf("%s", s);
  for(n=0; s[n]; ++n) f[s[n]-'A']++;
  for(int i=0; s[i+1]; ++i) {
    int g[32] = {0};
    for(int j=0; j<i; ++j) g[s[j]-'A']++;
    for(int j=0; j<s[i]-'A'; ++j) {
      if(f[j]-g[j] <= 0) continue;
      ll tmp = fact[n-i-1];
      for(int k=0; k<26; ++k)
        tmp /= fact[f[k]-g[k]-(j==k?1:0)];
      sol += tmp;
    }
  }
  printf("%lld\n", sol);
  return 0;
}
