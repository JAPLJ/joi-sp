#include<cstdio>
#include<cstdlib>

int M, k;
void farey(int a, int b, int c, int d)
{
  if(b+d>M) return;
  farey(a, b, a+c, b+d);
  if(--k==0) { printf("%d %d\n", a+c, b+d); exit(0); }
  farey(a+c, b+d, c, d);
}

int main()
{
  scanf("%d%d", &M, &k);
  farey(0, 1, 1, 1);
  puts("-1");
  return 0;
}
