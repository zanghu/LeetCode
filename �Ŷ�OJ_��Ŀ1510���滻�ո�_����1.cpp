#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int MAXSIZE = 100000;

int max_num(int x, int y)
{
    return x>y? x: y;
}

int main()
{
    char s1[MAXSIZE];
    char s2[MAXSIZE];
    int a[MAXSIZE][MAXSIZE];
    while (scanf("%s%s", &s1, &s2)
    {
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        int mark = -1;
        //初始化 
        for (int i = 0; i <= l1; ++i) a[i][0] = 0;
        for (int i = 0; i <= l2; ++i) a[0][i] = 0;
        //主计算部分
        for (int i = 1; i <= l1; ++i)
        {
            for (int j = 1; j <= l2; ++j)
            {
                if (s1[i-1] == s2[j-1]) a[i][j] = a[i-1][j-1] + 1;
                else a[i][j] = max_num(a[i-1, j], a[i, j-1]);
            }
        }        
        printf("%d\n", a[l1][l2]);   
    }
    return 1;
}
    
