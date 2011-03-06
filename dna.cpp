#include<cstdio>
#include<algorithm>

struct trie {
  trie *next[4];
  bool leaf;
  trie() {
    for(int i=0; i<4; ++i) next[i]=NULL;
    leaf = false;
  }
} *root = new trie();

int conv(char c)
{
  if(c=='A') return 0;
  if(c=='T') return 1;
  if(c=='G') return 2;
  return 3;
}

int dp[150050], dna[150050];
char target[150050], s[32];
int main()
{
  int N, M;
  scanf("%d%s", &N, target);
  for(M=0; target[M]; ++M) dna[M]=conv(target[M]);
  for(int i=0; i<N; ++i) {
    trie *p = root;
    scanf("%s", s);
    for(char *q=s; *q; q++) {
      int c = conv(*q);
      if(!p->next[c]) p->next[c] = new trie();
      p = p->next[c];
    }
    p->leaf = true;
  }
  for(int i=0; i<M; ++i) dp[i] = -1;
  trie *p = root;
  for(int i=0; i<M; ++i) {
    if(!p->next[dna[i]]) break;
    p = p->next[dna[i]];
    if(p->leaf) dp[i] = 1;
  }
  for(int i=0; i<M-1; ++i) {
    if(dp[i] < 0) continue;
    for(int j=i; j>=0 && i-j+1<20; --j) {
      p = root;
      for(int k=j; k<M; ++k) {
	if(!p->next[dna[k]]) break;
	p = p->next[dna[k]];
	if(p->leaf) dp[k] = std::min(dp[k]<0 ? 1<<29 : dp[k], dp[i]+1);
      }
    }
  }
  printf("%d\n", dp[M-1]);
  return 0;
}
