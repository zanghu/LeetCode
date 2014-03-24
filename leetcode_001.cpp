#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        char temp;
        int l = s.size();
        int mid = l / 2;
        
        for (int i = 0; i <= mid; ++i)
        {
            temp = s[i];
            s[i] = s[l-1-i];
            s[l-1-i] = temp;
        }
        int start = 0;
        int end = -1;
        for (int i = 0; i < l; ++i)
        {
            if (s[i] == ' ')
            {
                end = s[i];
                mid = (start + end) / 2;
                for (int i = start; i <= mid; ++i)
                {
                    temp = s[i];
                    s[i] = s[end+start-i];
                    s[end+start-i] = temp;
                }
            }
            ++start;
        }
        
    }
};

int main()
{
    //freopen("d:\\1.txt", "r", stdin);
    //freopen("d:\\2.txt", "w", stdout);
    string s;
    vector<string> stack;
    while (cin>>s)
    {
        Solution sol;
        sol.reverseWords(s);
    }
    return 1;
}
