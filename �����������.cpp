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
    
