#include <iostream>
#include <stack>
#include <string>

using namespace std;

string postFix(string &inFix);
int precedence(char op);

char opr[]{'+', '-', '*', '/'};

int main()
{
    string expr = "a+b-c*d/e";
    cout << postFix(expr) << endl;
    return 0;
}

string postFix(string &inFix)
{
    stack<char> stk;
    if(inFix.size() < 2)
    {
        return inFix;
    }
    for(char elem : inFix)
    {
        if(elem == '+' || elem == '-')

    }
}


int isOp(char elem)
{
    
}
int precedence(char op)
{

}
