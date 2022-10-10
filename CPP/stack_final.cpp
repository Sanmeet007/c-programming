#include <stdlib.h>
#include <stack>
#include <iostream>
#include <string.h>
#define MAX_LENGTH 30

using namespace std;

struct node
{
    char data;
    struct node *next;

    node(char x)
    {
        data = x;
        next = NULL;
    }
};
struct StackStruct
{
    struct node *top;
    char x;

    StackStruct()
    {
        top = NULL;
    }

    bool empty()
    {
        if (top == NULL)
        {
            return (true);
        }
        else
        {
            return (false);
        }
    }

    void push(char x)
    {
        struct node *p = new node(x);
        p->next = top;
        top = p;
    }

    char pop()
    {
        if (!empty())
        {
            struct node *p = top;
            x = p->data;

            top = top->next;
            delete (p);

            return (x);
        }
        else
        {
            return ('\0');
        }
    }
};

int precedence(char);
void infix_to_prefix(char *, char *);
void infix_to_postfix(char *, char *);
int eval_infix(string);
void hold_and_clrscr();
int toInt(char x);
int apply_operation(int, int, char);

int main()
{
    char infix[MAX_LENGTH], prefix[MAX_LENGTH], postfix[MAX_LENGTH];
    int op;
    bool should_run = true;

    while (should_run)
    {
        cout << "\n\nMenu:: \n\n1) Infix to prefix with evaluation \n2) Infix to postfix with evaluation \n3) quit \n\nEnter your choice : ";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "\nEnter the infix expression::" << endl;
            fflush(stdin);
            cin.getline(infix, MAX_LENGTH);
            infix_to_prefix(infix, prefix);
            cout << "\nPrefix Expression is " << prefix << endl;
            cout << "\n\nEvaluation of prefix expression : " << eval_infix(infix);
            hold_and_clrscr();
            break;

        case 2:
            cout << "\nEnter the infix expression::" << endl;
            fflush(stdin);
            cin.getline(infix, MAX_LENGTH);
            infix_to_postfix(infix, postfix);
            cout << "\nPostfix Expression is " << postfix << endl;
            cout << "\n\nEvaluation of postfix expression  : " << eval_infix(infix);
            hold_and_clrscr();
            break;

        case 3:
            should_run = false;
            cout << endl
                 << "Bye";
            break;

        default:
            cout << "\nInvalid expression !";
            hold_and_clrscr();
            break;
        }
    }
    return 0;
}

void infix_to_postfix(char infix[], char postfix[])
{
    int i = 0;
    string s = infix;
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            *postfix++ = c;
        else if (c == '(')
            st.push('(');
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                *postfix++ = st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                *postfix++ = st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        *postfix++ = st.top();
        st.pop();
    }

    *postfix = '\0';
}

void infix_to_prefix(char infix[], char prefix[])
{
    int i, j;
    char temp, in1[30];

    for (i = strlen(infix) - 1, j = 0; i >= 0; i--, j++)
        in1[j] = infix[i];
    in1[j] = '\0';

    for (i = 0; in1[i] != '\0'; i++)
    {
        if (in1[i] == '(')
            in1[i] = '(';
    }

    infix_to_postfix(in1, prefix);
    for (i = 0, j = strlen(prefix) - 1; i < j; i++, j--)
    {
        temp = prefix[i];
        prefix[i] = prefix[j];
        prefix[j] = temp;
    }
}

int precedence(char x)
{
    if (x == '(')
        return 0;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/' || x == '%')
        return 2;

    return 3;
}

int apply_operation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '%':
        return a % b;
    }
}

int eval_infix(string infix)
{
    int i;

    stack<int> values;
    stack<char> ops;
    for (i = 0; i < infix.length(); i++)
    {
        if (isalpha(infix[i]))
        {
            string y;
            char x = infix[i];
            cout << "Enter the value for " << x << "  : ";
            fflush(stdin);
            cin >> y;
            infix.replace(i, i + 1, y);
        }
    }
    i = 0;

    for (i = 0; i < infix.length(); i++)
    {
        if (infix[i] == ' ')
            continue;
        else if (infix[i] == '(')
        {
            ops.push(infix[i]);
        }
        else if (isdigit(infix[i]))
        {
            int val = 0;
            while (i < infix.length() &&
                   isdigit(infix[i]))
            {
                val = (val * 10) + (infix[i] - '0');
                i++;
            }

            values.push(val);
            i--;
        }
        else if (infix[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(apply_operation(val1, val2, op));
            }
            if (!ops.empty())
                ops.pop();
        }
        else
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(infix[i]))
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(apply_operation(val1, val2, op));
            }
            ops.push(infix[i]);
        }
    }

    while (!ops.empty())
    {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(apply_operation(val1, val2, op));
    }

    return values.top();
}

void hold_and_clrscr()
{
    fflush(stdin);
    cout << "\n\nPress any key to continue...";
    getchar();
    system("clear");
}