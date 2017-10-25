#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isNumberDigit(char C)
{
    if (C >= '0' && C <= '9')
    {
        return true;
    }
    return false;
}

bool isOperator(char ope)
{
    if (ope == '+' || ope == '-' || ope == '*' || ope == '/')
    {
        return true;
    }
    return false;
}

int performOperation(char operationOperator, int operant1, int operant2)
{
    if (operationOperator == '+')
    {
        return operant1 + operant2;
    }
    else if (operationOperator == '-')
    {
        return operant1 - operant2;
    }
    else if (operationOperator == '*')
    {
        return operant1 * operant2;
    }
    else if (operationOperator == '/')
    {
        return operant1 / operant2;
    }
    else
    {
        cout << "Unexpected Symbol" << endl;
    }
    return -1;
}

int postfixEvaluation(string exp)
{
    stack<int> S;
    for (int i = 0; i < sizeof(exp); i++)
    {
        if (exp[i] == ' ' || exp[i] == ',')
        {
            continue;
        }
        else if (isOperator(exp[i]))
        {
            int op2 = S.top();
            S.pop();
            int op1 = S.top();
            S.pop();
            int result = performOperation(exp[i], op1, op2);
            S.push(result);
        }
        else if (isNumberDigit(exp[i]))
        {
            int operand = 0;
            while (i < sizeof(exp) && isNumberDigit(exp[i]))
            {
                operand = (operand * 10) + (exp[i] - '0');
                i++;
            }
            i--;
            S.push(operand);
        }
    }
    return S.top();
}

int main()
{
    string expression;
    cout << "Enter Postfix Expression \n";
    getline(cin, expression);
    int result = postfixEvaluation(expression);
    cout << "Output = " << result << "\n";
}