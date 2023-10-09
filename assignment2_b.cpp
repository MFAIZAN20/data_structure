#include <iostream>
#include <cstring>
using namespace std;

struct node
{
    int data;
    node *next;
    node *top;
    int length;

    node(int val)
    {
        data = val;
        next = NULL;
        top = NULL;
        length = 0;
    }
    
bool isEmpty()
    {
        if ( top == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
int peek()
    {
        if (top == NULL)
        {
            cout << "The Stack is empty" <<endl;
            return -1;
        }
        else
        {
            return top->data;
        }
    }

void push(int s)
    {
        node *n = new node(s);
        n->next = top;
        top = n;
        length++;
    }

int pop() 
    {
        if (!isEmpty()) 
        {
            node* temp = top;
            int poppedValue = top->data;
            top = top->next;
            cout << "The pop value is : " << poppedValue<< endl;
            delete temp;
            length--;
            return poppedValue;
        }
        else
        {
            std::cout << "The Stack is Empty " << std::endl;
            return 0;
        }
    }
bool isOparand(const int c)
{
    // + (Plus sign): ASCII value 43'
    // - (Minus sign): ASCII value 45
    // / (Forward slash): ASCII value 47
    // * (Asterisk or multiplication symbol): ASCII value 42

    if (c == 43 || c == 45 || c == 42 || c== 47)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int presedence(int pre)
{
    if (pre == 43 || pre == 45)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

void convertStringToIntArray(const string& str, int* intArray)
{
    for (int i = 0; i < str.length(); ++i)
    {
        intArray[i] = str[i] -'0';
    }
}

int evaluatePostfix(string exp)
{
    for (int i = 0; i < exp.size(); ++i) 
    {
        if (isOparand(exp[i]))
        {
            push(exp[i] - '0');
        }
        else 
        {
            int first_value = pop();
            int second_value = pop();
            switch (exp[i]) 
            {
            case '+':
                push(second_value + first_value);
                break;
            case '-':
                push(second_value - first_value);
                break;
            case '*':
                push(second_value * first_value);
                break;
            case '/':
                if (first_value == 0)
                {
                    cout << " Undefined Error " <<endl;
                }
                else
                {
                    push(second_value / first_value);
                }
                break;
            }
        }
    }
    int result;
    while (isEmpty())
    {
        int current = pop();
        result += current;
    }
    return result;
}
};

int main()
{
    string post;
    post = "542*+9-";
    node solution_object(0);
    int evaluated_expression = solution_object.evaluatePostfix(post);
    cout << "The postfix is : " << evaluated_expression <<endl;
    return 0;
}