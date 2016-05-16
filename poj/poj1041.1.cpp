#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NN 46
#define MM 1998

int map[NN][MM];// map[u][e] = v，表示点u通过边e连接到v 
int adj[NN][MM]; // adj[u][i] = e，表示u的第i条临边是e 
int num[NN]; // 记录每个点的临边条数 
int mark[MM];
int stk[MM]; // 记录欧拉路径 
int idx, S, top;

int Min(int x, int y){
    return x < y ? x : y;
}

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

void dfs(int u){
     int i, v, e;
     for (i = 1; i <= num[u]; i++){
         e = adj[u][i];
         if (!mark[e]){
//         	printf("aa :%d:%d\n",top,e);
            v = map[u][e];
            mark[e] = 1;
            dfs(v);
            stk[++top] = e;
//            printf("bb :%d:%d\n",top,e);
         }
     }
}
int main()
{
    int x, y, z, i, maxN;
    while(scanf("%d%d", &x, &y) != EOF){
       if (x == 0 && y == 0) break;
       memset(num, 0, sizeof(num));
       scanf("%d", &z);
       S = Min(x, y);
       adj[x][++num[x]] = z;
       adj[y][++num[y]] = z;
       map[x][z] = y;
       map[y][z] = x;
       while(scanf("%d%d", &x, &y) != EOF){
          if (x == 0 && y == 0) break;
          scanf("%d", &z);
          adj[x][++num[x]] = z;
          adj[y][++num[y]] = z;
          map[x][z] = y;
          map[y][z] = x;
       }
       for (i = 1;; i++){
           if(num[i] == 0) break;
           if (num[i] & 1) break;
       }
       if (num[i] != 0){
          puts("Round trip does not exist.");
          continue;
       }
       maxN = i - 1;
       for (i = 1; i <= maxN; i++){ // 对点i的临边排序 
           qsort(adj[i] + 1, num[i], sizeof(int), cmp);
       }
       memset(mark, 0, sizeof(mark));
       top = 0;
       dfs(S);
       for (i = top; i > 1; i--){
           printf("%d ", stk[i]);
       }
       printf("%d\n", stk[i]);
    }
    return 0;
}
