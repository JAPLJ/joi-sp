#include<cstdio>
#include<algorithm>
#include<functional>

int N, C, P[3050][2];
int Tp[3050], T, Op[3050], O, Z, Rp[6050], R;
bool can(int lim)
{
  int cp=P[C][0], up=0, oi=0, zi=0, ri=0;
  for(int i=P[C][1]; i<2; ++i) cp+=Rp[ri++];
  for(int i=0; i<T && cp<Tp[i]; ++i) up++;
  if(up > lim) return false;
  while(up++<lim) {
    if(oi<O && (zi>=Z || Op[oi]>Rp[ri+1])) oi++, ri++;
    else zi++, ri+=2;
  }
  int R2[6050], used[6050] = {0}, r=ri, nr=0;
  for(int o=O-1; o>=oi; --o) {
    while(r<R && Op[o]+Rp[r]>cp) r++;
    if(r==R) return false;
    used[r++] = 1;
  }
  for(int i=ri; i<R; ++i)
    if(!used[i]) R2[nr++] = Rp[i];
  for(int i=0; i<nr/2; ++i)
    if(R2[i]+R2[nr-i-1]>cp) return false;
  return true;
}

int main()
{
  scanf("%d%d", &N, &C);
  for(int i=0; i<2*N; ++i) {
    int s, a;
    scanf("%d%d", &s, &a);
    P[a][0] += s; P[a][1]++;
    if(a == 0) Rp[R++] = s;
  }
  for(int i=1; i<=N; ++i) {
    if(i == C) continue;
    if(P[i][1] == 2) Tp[T++] = P[i][0];
    if(P[i][1] == 1) Op[O++] = P[i][0];
    if(P[i][1] == 0) Z++;
  }
  std::sort(Tp, Tp+T, std::greater<int>());
  std::sort(Op, Op+O, std::greater<int>());
  std::sort(Rp, Rp+R, std::greater<int>());
  int lo = -1, hi = N-1;
  while(hi-lo>1) (can((hi+lo)/2) ? hi : lo) = (hi+lo)/2;
  printf("%d\n", hi+1);
  return 0;
}
