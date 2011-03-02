#include<cstdio>

int main()
{
  int n, m=1;
  scanf("%d", &n);
  for(int i=2; i*i<=n; ++i) {
    int e=0;
    while(n%i==0) e++, n/=i;
    for(int p=i; e>0; m=m<p?p:m, p+=i)
      for(int q=p; q%i==0; q/=i) e--;
  }
  printf("%d\n", n<m?m:n);
  return 0;
}
