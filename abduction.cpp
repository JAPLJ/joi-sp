#include<cstdio>

int main()
{
  char S[10050];
  int d, W, H, N, X[1024] = {0}, Y[1024] = {0}, M = 10000000;
  scanf("%d%d%d%s", &W, &H, &N, S);
  X[0] = Y[0] = 1;
  d = S[0]=='L' ? 0 : 1;
  for(int i=0; i<=N; ++i) {
    int s = 0, t;
    if(d==0)
      for(int x=0; x<=W; ++x, s=(s+t)%M)
	t = X[x], X[x] = s;
    else if(d==1)
      for(int y=0; y<=H; ++y, s=(s+t)%M)
	t = Y[y], Y[y] = s;
    else if(d==2)
      for(int x=W; x>=0; --x, s=(s+t)%M)
	t = X[x], X[x] = s;
    else
      for(int y=H; y>=0; --y, s=(s+t)%M)
	t = Y[y], Y[y] = s;
    if(i==N) break;
    d = (d + (S[i]=='L' ? 1 : 3)) % 4;
  }
  printf("%d\n", 1ll*X[W]*Y[H]%M);
  return 0;
}
