#include<cstdio>

using namespace std;

#define MAXN 1000
#define MAXC 10000

int v[MAXN], w[MAXN], x[MAXN];
int d[MAXN][MAXC];

int main() {
  freopen("data.in", "r", stdin);//重定向输入流
  freopen("data.out", "w", stdout);//重定向输出流
  int n, c;
  while(scanf("%d %d", &n, &c) != EOF) {
    for(int i = 0; i < n; ++i){
      scanf("%d %d", &v[i], &w[i]);
      x[i] = 0;
    }
    for (int i = 0; i <=n; i++) {
      for (int j = 0; j<=c; j++) {
        d[i][j] = i==0 ? 0 : d[i-1][j];
        if (i > 0 && j>=v[i-1]) {
          if (d[i][j] < d[i-1][j-v[i-1]] + w[i-1])
            d[i][j] = d[i-1][j-v[i-1]] + w[i-1];
        }
      }
    }

    int j = c;
    for (int i = n; i > 0; i--) {
      if (d[i][j] > d[i-1][j]) {
        x[i-1] = 1;
        j = j - v[i-1];
      }
    }
    for (int i = 0; i < n ; i++) printf("%d ", x[i]);

    printf("%d\n", d[n][c]);
  }
  printf("Hello world");
  fclose(stdin);
  fclose(stdout);
  return 0;
}
