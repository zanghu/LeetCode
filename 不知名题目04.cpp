#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    //freopen("d:\\1.txt", "r", stdin);
    //freopen("d:\\2.txt", "w", stdout);
    int T;
    int N;
    int a;
    int start, end;
    int low;
    int sum; 
    int max;
    int cnt = 0;
    while( scanf("%d", &T)!=EOF) {
        while (T > 0) {
            scanf("%d", &N);
            ++cnt;
            //初始值需要注意 
            max = -100000000;
            sum = 0;
            low = 1;
            start = end = 1;
            for (int i = 1; i <= N; ++i) {
                scanf("%d", &a);
                sum += a;
                if (sum > max) {
                    start = low;
                    end = i;
                    max = sum;
                }
                
                if (sum < 0) { //每一次都检查sum是否是负数 
                    sum = 0;
                    low = i+1;
                }
            }
            printf("Case %d:\n%d %d %d\n", cnt, max, start, end);
            --T;
            if (T > 0) printf("\n");
        }
    }
    return 0;
}
    
