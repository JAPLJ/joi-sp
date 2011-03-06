#include<cstdio>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef deque<pair<int, ll> > num;

num read()
{
  num n;
  int m, a, l;
  scanf("%d", &m);
  while(m--) scanf("%d%d", &a, &l), n.push_back(make_pair(a, l));
  return n;
}

void getpos(vector<ll>& p, const num& n)
{
  ll d = 0;
  for(int i=n.size()-1; i>=0; --i)
    p.push_back(d+=n[i].second);
}

num cut(const vector<ll>& p, const num& n)
{
  ll d = 0;
  int cur = n.size()-1, pos = 0;
  num r;
  for(int i=0; i<(int)p.size(); ++i) {
    if(cur >= 0) {
      r.push_front(make_pair(n[cur].first, p[i] - d - pos));
      if(p[i]==d+n[cur].second) {
	d += n[cur].second; cur--; pos = 0;
      } else {
	pos = p[i] - d;
      }
    } else {
      r.push_front(make_pair(0, p[i]-d));
      d = p[i];
    }
  }
  return r;
}

num add(const num& a, const num& b)
{
  int n = a.size(), carry = 0;
  num r;
  for(int i=n-1; i>=0; --i) {
    int s = a[i].first + b[i].first;
    int over = s >= 10 || (s == 9 && carry);
    r.push_front(make_pair((s+carry)%10, 1));
    r.push_front(make_pair((s+over)%10, a[i].second-1));
    carry = over;
  }
  if(carry) r.push_front(make_pair(1, 1));
  return r;
}

num form(const num& n)
{
  num r;
  for(int i=0, j; i<(int)n.size(); i=j) {
    ll d = 0;
    for(j=i; j<(int)n.size() && n[i].first==n[j].first; ++j) d+=n[j].second;
    if(d > 0) r.push_back(make_pair(n[i].first, d));
  }
  return r;
}

int main()
{
  num a=read(), b=read();
  vector<ll> p;
  getpos(p, a); getpos(p, b);
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  a = cut(p, a); b = cut(p, b);
  a = form(form(add(a, b)));
  printf("%d\n", a.size());
  for(int i=0; i<(int)a.size(); ++i)
    printf("%d %lld\n", a[i].first, a[i].second);
  return 0;
}
