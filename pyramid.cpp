#include<cstdio>
#include<algorithm>

int F[3050][3050];
int main()
{
  int W, H, N;
  scanf("%d%d%d", &W, &H, &N);
  for(int i=0; i<N; ++i) {
    int x, y, h;
    scanf("%d%d%d", &x, &y, &h);
    x++; y++;
    for(int j=0; j<h; ++j) {
      if(x+j<=W) F[y][x+j]=std::max(F[y][x+j], h-j);
      if(x-j>=1) F[y][x-j]=std::max(F[y][x-j], h-j);
      if(y+j<=H) F[y+j][x]=std::max(F[y+j][x], h-j);
      if(y-j>=1) F[y-j][x]=std::max(F[y-j][x], h-j);
    }
  }
  for(int i=0; i<2; ++i) {
    for(int y=1; y<=H; ++y)
      for(int x=1; x<=W; ++x)
	F[y][x] = std::max(F[y][x], F[y-1][x-1]-1);
    for(int y=1; y<=H; ++y)
      for(int x=W; x>=1; --x)
	F[y][x] = std::max(F[y][x], F[y-1][x+1]-1);
    for(int y=H; y>=1; --y)
      for(int x=1; x<=W; ++x)
	F[y][x] = std::max(F[y][x], F[y+1][x-1]-1);
    for(int y=H; y>=1; --y)
      for(int x=W; x>=1; --x)
	F[y][x] = std::max(F[y][x], F[y+1][x+1]-1);
  }
  long long s = 0;
  for(int y=1; y<=H; ++y)
    for(int x=1; x<=W; ++x)
      s += F[y][x];
  printf("%lld\n", s);
  return 0;
}
