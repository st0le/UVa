//160 - Factors and Factorials
#include <cstdio>
using namespace std;

int primePower(int n,int prime) {
    int c = 0;
    while(n > 0)
        c += (n/=prime);
    return c;
}

int main() {
    int n;
    int primes[] {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    while(true) {
        scanf("%d",&n);
        if(n == 0) break;
        printf("%3d! =",n);
        //no need to handle for n = 1
        for(int i  = 0 ; i < 25 && primes[i] <= n; i++) {
            if(i > 0 && i % 15 == 0){
                printf("\n      ");
            }
            printf("%3d",primePower(n,primes[i]));
        }
        printf("\n");
    }
    return 0;
}
