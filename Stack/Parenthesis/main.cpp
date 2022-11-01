#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string name = "(a+b)(())*(c-d)";
    stack<char> stk;
    for(char alpha : name)
    {
        // Look for () brackets
        if(alpha == '(')
        {
            stk.push(alpha);
        }
        else if(alpha == ')')
        {
            if(!stk.empty())
            {
                stk.pop();
            }
            else
            {
                cout << "Not Matching parenthesis" << endl;
                return 1;
            }
        }
    }
    if(stk.empty())
    {
        cout << "Matching Parenthesis" << endl;
    }
    else
    {
        cout << "Not Matching parenthesis" << endl;
        return 1;
    }
    return 0;
}
