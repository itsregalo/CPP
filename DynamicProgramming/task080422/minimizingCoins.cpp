#include <iostream>

using namespace std;
const int maximumX = 1e6;
const int INF = 0x3f3f3f3f;

int N, X, c, dp[maximumX+1];

int main(){
    scanf("%d %d", &N, &X);
    fill(dp+1, dp+X+1, INF);
    for(int i = 0; i < N; i++){
        scanf("%d", &c);
        for(int z = 0; z <= X-c; z++)
            if(dp[z] != INF)
                dp[z+c] = min(dp[z+c], dp[z]+1);
    }
    printf("%d\n", dp[X] == INF ? -1 : dp[X]);
    return 0;
}