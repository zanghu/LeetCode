#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
    //实现字符串op的四则运算算符效果
    int operation(int n1, int n2, const string& op) {  
        switch ((op.c_str())[0]) {
            case '+': return n1 + n2;
            case '-': return n1 - n2;
            case '*': return n1 * n2;
            case '/': return n1 / n2;
        }
    }
public:
    //非常精巧的递归，基本思想是利用后续遍历计算树的性质 
    int evalRPN(vector<string>& tokens) {
        //每一次递归视作是从根节点开始计算一个树形算式，由于tokens中是后序序列，因此根节点位于最末端 
        string str = tokens.back(); //读取根节点值 
        //摘下根节点，这是由于递归时，只能预测有字数根节点的位置，无法预测左子树根节点位置，
        //因此必须不断摘掉树的节点，直到该字数计算完毕为止 
        vec.pop_back(); 
        //如果根节点是算符，则先计算左子树值，再计算右子树值，最后用根节点算符对两个数运算，返回
        //如果根节点是数字，则说明到达叶子节点，直接看做常量表达式，返回 
        if (str == "+" || str=="-" || str=="*" || str=="/") {  
            int r_num = evalRPN(tokens);
            int l_num = evalRPN(tokens);
            return operation(l_num, r_num, str);
        }
        else return atoi(str.c_str());
    }
};

int main() {
    //测试用例1 
    vector<string> va;
    va.push_back("2");
    va.push_back("1");
    va.push_back("+");
    va.push_back("3");
    va.push_back("*");
    //测试用例2 
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
