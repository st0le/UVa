//136 - Ugly Numbers
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;


int main() {
    const int N = 1500;
    int ugly[N];
    int i2, i3, i5;
    i2 = i3 = i5 = 0;
    for(int i = 0; i < N ; i++)
        ugly[i] = 1;
    int m2 = ugly[i2] * 2, m3 = ugly[i3] * 3, m5 = ugly[i5] * 5;
    for(int i = 1; i < N; i++) {
        int mn = min(m2,min(m3,m5));
        ugly[i] = mn;
        if(mn == m2) {
            m2 = ugly[++i2] * 2;
        }
        if(mn == m3) {
            m3 = ugly[++i3] * 3;
        }
        if (mn == m5) {
            m5 = ugly[++i5] * 5;
        }
    }
    printf("The 1500'th ugly number is %d.\n",ugly[N-1]);
    return 0;
}
