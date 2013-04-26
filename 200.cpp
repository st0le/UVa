//200 - Rare Order
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 26;

bool registered[N];
int indegree[N];
bool adj[N][N];

void topological_sort() {

    queue<int> q;
    for(int i = 0 ; i < N; i++)
        if(registered[i] && indegree[i] == 0)
            q.push(i);

    while(!q.empty()) {
        int u = q.front();q.pop();
        printf("%c",u + 'A');
        for(int v = N - 1; v >= 0; v--){
            if(adj[u][v] && indegree[v] > 0){
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }
    }
    printf("\n");
}

int main() {

    char word[2][30];
    int x = 0,c = 0;
    while(true) {
        scanf("%s",word[x]);
        if(word[x][0] == '#') break;
        if(c > 0) {
            for(int i = 0; word[x][i] && word[!x][i]; i++)
                if(word[x][i] != word[!x][i]) {
                    if(!adj[word[!x][i] - 'A'][word[x][i] - 'A']) {
                        adj[word[!x][i] - 'A'][word[x][i] - 'A'] = true;
                        indegree[word[x][i] - 'A']++;
                        registered[word[x][i] - 'A'] = registered[word[!x][i] - 'A'] = true;
                    }
                    break;
                }
        }
        c++;
        x = !x;
    }
    topological_sort();
    return 0;
}
