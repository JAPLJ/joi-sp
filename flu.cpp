#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int x[100000], y[100000], dist[100000];
vector<int> bucket[1000][1000], adj[100000];
int main()
{
  int n, m, d, k, s=0;
  scanf("%d%d%d%d", &n, &m, &d, &k);
  for(int i=0; i<n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    int by = y[i]/d, bx = x[i]/d;
    for(int j=by-1; j<=by+1; ++j) {
      for(int k=bx-1; k<=bx+1; ++k) {
	if(j<0||j>=1000||k<0||k>=1000) continue;
	for(int a=0; a<(int)bucket[j][k].size(); ++a) {
	  int b = bucket[j][k][a];
	  if((x[i]-x[b])*(x[i]-x[b])+(y[i]-y[b])*(y[i]-y[b]) <= d*d)
	    adj[i].push_back(b), adj[b].push_back(i);
	}
      }
    }
    bucket[by][bx].push_back(i);
  }
  for(int i=1; i<n; ++i) dist[i] = n;
  queue<int> q;
  for(q.push(0); !q.empty(); ) {
    int u = q.front(); q.pop();
    for(int i=0; i<(int)adj[u].size(); ++i)
      if(dist[adj[u][i]]==n) q.push(adj[u][i]), dist[adj[u][i]]=dist[u]+1;
  }
  for(int i=0; i<n; ++i)
    s += dist[i]<=k && k<dist[i]+m;
  printf("%d\n", s);
  return 0;
}
