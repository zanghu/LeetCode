1.最长公共子序列
//====================================================================================
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int max_num(int a, int b) {
    return a > b? a: b;
}

int main() {
    const int MAXSIZE = 1001;
    char str1[MAXSIZE];
    char str2[MAXSIZE];
    while (scanf("%s%s", &str1, &str2) != EOF) {
        const int len1 = strlen(str1);
        const int len2 = strlen(str2);
        int** a = new int* [len1+1];
        for (int i = 0; i< len1+1; ++i) {
            a[i] = new int [len2+1];
        }
        for (int i = 0; i <= len1; ++i) a[i][0] = 0;
        for (int j = 0; j <= len2; ++j) a[0][j] = 0;
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (str1[i-1] == str2[j-1]) a[i][j] = a[i-1][j-1] + 1;
                else a[i][j] = max_num(a[i-1][j], max_num(a[i][j-1], a[i-1][j-1]));
            }
        }
        printf("%d\n", a[len1][len2]);
        for (int i = 0; i < len1+1; ++i) delete[] a[i];
        delete[] a;
    }
    return 0;
}


2.目前最好的最大连续子段和代码
//=====================================================
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

3.最长上升子序列
//可通过九度1533和poj2533
#include <stdio.h>
 
#define MAX 100000
#define VMAX 100001
#define MIN (-2147483647 - 1)
 
int BSearch (int MaxV[], int start, int end, int key){
    int mid;
 
    while (start <= end){
        mid = start + ((end - start) >> 1);
        if (MaxV[mid] < key){
            start = mid + 1;
        }
        else if (MaxV[mid] > key){
            end = mid - 1;
        }
        else
            return mid;
    }
    return start;
}
 
int LIS (int data[], int n){
    int MaxV[VMAX];
    MaxV[1] = data[0];
    MaxV[0] = MIN;
 
    int nMaxLIS = 1;
    int i, j;
    for (i=1; i<n; ++i){
        j = BSearch (MaxV, 0, nMaxLIS, data[i]);
        if (j > nMaxLIS){
            nMaxLIS = j;
            MaxV[j] = data[i];
        }
        else if (MaxV[j-1] < data[i] && data[i] < MaxV[j]){ //为什么这里不需要循环前方所有元素??`1
            MaxV[j] = data[i];
        }
    }
    return nMaxLIS;
}
 
int main(void){
    int data[MAX];
    int n;
    int i;
 
    while (scanf ("%d", &n) != EOF){
        for (i=0; i<n; ++i){
            scanf ("%d", &data[i]);
        }
        printf ("%d\n", LIS (data, n));
    }
 
    return 0;
}
    

    
