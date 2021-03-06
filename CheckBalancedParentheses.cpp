#include <iostream>
using namespace std;
#include <stack>
#include <string>

bool areParanthesisBalanced(char expr[])
{
    stack<char> s;
    char a, b, c;

    // Traversing the Expression
    for (int i = 0; i < sizeof(expr); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            // Push the element in the stack
            s.push(expr[i]);
        }
        else
        {
            switch (expr[i])
            {
            case ')':

                // Store the top element in a
                a = s.top();
                s.pop();
                if (a == '{' || a == '[')
                    cout << "Not Balancedn";
                break;
            case '}':

                // Store the top element in b
                b = s.top();
                s.pop();
                if (b == '(' || b == '[')
                    cout << "Not Balancedn";
                break;
            case ']':

                // Store the top element in c
                c = s.top();
                s.pop();
                if (c == '(' || c == '{')
                    cout << "Not Balancedn";
                break;
            }
        }
    }

    // Check Empty Stack
    if (s.empty())
        return true;
    else
        return false;
}

int main()
{
    char expr[] = "{()}[]";

    if (areParanthesisBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
