#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int A[100000];
vector<int> adj[100000];
int dfs(int u)
{
  for(int i=0; i<(int)adj[u].size(); ++i)
    A[u] += max(0, dfs(adj[u][i]));
  return A[u];
}

int main()
{
  int n, s;
  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    scanf("%d%d", &s, &A[i]);
    if(s) adj[s-1].push_back(i);
  }
  dfs(0);
  printf("%d\n", *max_element(A, A+n));
  return 0;
}
