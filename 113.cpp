//113 - Power of Cryptography
#include <cstdio>
#include <cmath>
using namespace std;


int main() {
    int n;
    double p;
    while(scanf("%d",&n) > 0) {
        scanf("%lf",&p);
        printf("%.0f\n",exp(log(p)/n));
    }
    return 0;
}
