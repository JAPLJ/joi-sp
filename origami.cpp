#include<cstdio>
#include<map>

using namespace std;

int main()
{
  int n, a, b, p, q, r, s, M=0, C=0;
  map<pair<int, int>, int> m;
  scanf("%d%d%d", &n, &a, &b);
  for(int i=0; i<n; ++i) {
    scanf("%d%d%d%d", &p, &q, &r, &s);
    for(int x=p; x<=r; ++x)
      for(int y=q; y<=s; ++y)
	m[make_pair(x, y)]++;
  }
  for(map<pair<int, int>, int>::iterator it=m.begin(); it!=m.end(); ++it)
    if(it->second>M) M=it->second, C=1; else if(it->second==M) C++;
  printf("%d\n%d\n", M, C);
  return 0;
}
