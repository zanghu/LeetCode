#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
    //ʵ���ַ���op�������������Ч��
    int operation(int n1, int n2, const string& op) {  
        switch ((op.c_str())[0]) {
            case '+': return n1 + n2;
            case '-': return n1 - n2;
            case '*': return n1 * n2;
            case '/': return n1 / n2;
        }
    }
public:
    //�ǳ����ɵĵݹ飬����˼�������ú������������������� 
    int evalRPN(vector<string>& tokens) {
        //ÿһ�εݹ������ǴӸ��ڵ㿪ʼ����һ��������ʽ������tokens���Ǻ������У���˸��ڵ�λ����ĩ�� 
        string str = tokens.back(); //��ȡ���ڵ�ֵ 
        //ժ�¸��ڵ㣬�������ڵݹ�ʱ��ֻ��Ԥ�����������ڵ��λ�ã��޷�Ԥ�����������ڵ�λ�ã�
        //��˱��벻��ժ�����Ľڵ㣬ֱ���������������Ϊֹ 
        vec.pop_back(); 
        //������ڵ�����������ȼ���������ֵ���ټ���������ֵ������ø��ڵ���������������㣬����
        //������ڵ������֣���˵������Ҷ�ӽڵ㣬ֱ�ӿ����������ʽ������ 
        if (str == "+" || str=="-" || str=="*" || str=="/") {  
            int r_num = evalRPN(tokens);
            int l_num = evalRPN(tokens);
            return operation(l_num, r_num, str);
        }
        else return atoi(str.c_str());
    }
};

int main() {
    //��������1 
    vector<string> va;
    va.push_back("2");
    va.push_back("1");
    va.push_back("+");
    va.push_back("3");
    va.push_back("*");
    //��������2 
    vector<string> vb;
    vb.push_back("4");
    vb.push_back("13");
    vb.push_back("5");
    vb.push_back("/");
    vb.push_back("+");
    Solution sol;
    cout << sol.evalRPN(va) << endl;
    cout << sol.evalRPN(vb) << endl;
    system("pause");
    return 0;
}
