//193 - Graph Coloring
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 101
#define GREY 0
#define BLACK 1
#define WHITE 2

int color[MAX];
vector<int> black,solution;
vector< vector<int> > graph;
int n,k;

void dfs(int u) {

    if(u > n) {
        if(black.size() > solution.size()) {
            solution.clear();
            solution.insert(solution.end(),black.begin(),black.end());
        }
        return;
    }

    int black_count = 0;
    for(int i = 0, l = graph[u].size(); i < l; i++) {
        int v = graph[u][i];
        if(color[v] == BLACK) {
            black_count++;
        }
    }
//    printf("\nBlack Neighbours of %d : %d",u,black_count);
    if(black_count == 0) {
        color[u] = BLACK;
        black.push_back(u);
        dfs(u + 1);
        black.pop_back();
        color[u] = GREY;
    }

    color[u] = WHITE;
    dfs(u + 1);
    color[u] = GREY;
}


int main() {
    int t;
    int x,y;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&k);
        memset(color,GREY,sizeof(int) * MAX);
        graph.clear();
        solution.clear();
        for(int u = 0; u <= n; u++) {
            graph.push_back(vector<int>());
        }
        for(int i = 0; i < k; i++) {
            scanf("%d %d",&x,&y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        dfs(1);
        printf("%d\n",solution.size());
        for(int i = 0,sz = solution.size() ; i < sz; i++){
            if(i > 0)
                printf(" ");
            printf("%d",solution[i]);
        }
        printf("\n");

    }
    return 0;
}
