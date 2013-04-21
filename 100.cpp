#include <cstdio>
#include <map>
using namespace std;

map<long,int> memo;

int collatz(long n) {
    if(memo.find(n) == memo.end())
        return memo[n] = 1 + collatz( n % 2 == 0 ? n / 2 : 3 * n + 1);
    return memo[n];
}

int main() {
    int a,b;
    memo[0] = 0;
    memo[1] = 1;
    while(scanf("%d %d", &a, &b)>0) {
        int mx = 0;
        for(int i = max(a,b), l = min(a,b); i >= l; i--){
            int n = collatz(i);
            if(n > mx)
                mx = n;
        }
        printf("%d %d %d\n",a,b,mx);
    }
}
