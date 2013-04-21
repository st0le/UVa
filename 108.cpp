#include <cstdio>
#include <iostream>
using namespace std;


const int N = 101;

int main() {

    int arr[N][N],sum[N][N];

    int i , j , k , n;

    scanf("%d", &n);
    for(i = 0 ; i < n; i++)
        for(j = 0; j < n ; j++)
            scanf("%d",&arr[i][j]);

    //calculate column wise rolling sum
    for(i = 0; i < n ; i++) {
        if(i == 0)
            sum[i][j] = arr[i][j];
        else
            for(j = 0 ; j < n ; j++)
                sum[i][j] = arr[i][j] + sum[i-1][j];
    }

    int mx = -10000000, s = 0, local_max = 0, term;
    for(i = 0; i < n ; i++)
        for(j = i + 1; j < n; j++) {
            s = 0;
            local_max = sum[j][0] - sum[i][0];
            for( k = 0; k < n; k++) {
                term = sum[j][k] - sum[i][k];
                s = max(s + term, 0);
                if(s > mx)
                    mx = s;
                if(local_max < term)
                    local_max = term;
            }
            if(local_max > mx)
                mx = local_max;
        }
    printf("%d\n",mx);
    return 0;
}
