#include<cstdio>
#include<algorithm>

int N, M, T, X, Y, P[10], S[1024][10], W[1024][10], R[1024];
int main()
{
  scanf("%d%d%d%d%d", &N, &M, &T, &X, &Y);
  for(int i=0; i<M; ++i) scanf("%d", &P[i]);
  for(int i=0; i<Y; ++i) {
    int t, n, m;
    char s[16];
    scanf("%d%d%d%s", &t, &n, &m, s);
    n--; m--;
    if(s[0]=='o') S[n][m] = t;
    if(s[0]=='c') R[n] += std::max(P[m]-(t-S[n][m])-W[n][m]*120, X);
    if(s[0]=='i') W[n][m]++;
  }
  for(int i=0; i<N; ++i) printf("%d\n", R[i]);
  return 0;
}
