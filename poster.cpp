#include<cstdio>

int main()
{
  int n, k, i;
  scanf("%d%d", &n, &k); k--;
  for(i=n-1; i>=0; k-=1<<(i--)) {
    if(k<1<<i) {
      for(int j=0; j<1<<i; ++j) putchar('J');
      for(int j=0; j<1<<i; ++j) putchar('O');
      break;
    }
    for(int j=0; j<1<<i; ++j) putchar('I');
  }
  puts(i<0 ? "J" : "");
  return 0;
}
