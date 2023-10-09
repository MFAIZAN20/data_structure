#include <iostream>
#include <string>

using namespace std;

class solution
{
    public:
    char letter;
    solution *top;
    solution *next;
    int capacity;

    solution(char c)
    {
        next = NULL;
        top = NULL;
        letter = c;
        capacity = 0;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(char s)
    {
        solution *n = new solution(s);
        n->next = top;
        top = n;;
        capacity++;
    }

    char pop()
    {
        if (isEmpty())
        {
            std::cout << "The Stack is empty" << std::endl;
            return -1;
        }
        else
        {
            solution* temp = top;
            top = top->next;
            char to_return = temp->letter;
            delete temp;
            temp = nullptr;
            capacity--;
            return to_return;
        }
    }

    bool check_the_parenthesis(string s)
    {
        int length = 0;
        while (length < s.length())
        {
            if (s[length] == '(' || '{' || '[')
            {   
                push(s[length]);
            }
            else if (s[length] == ')' || '}' || ']')
            {
                char check = pop();   
                if (check != s[length])
                {
                    return false;
                }
            }
            length++;
        }
        
        if (isEmpty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    string paranthesis;
    cout << "Please Enter Some Parenthesis " <<endl;
    getline(cin,paranthesis);

    solution sol(0);
    bool check = sol.check_the_parenthesis(paranthesis);

    if (check == true)
    {
        cout << "The paranethesis is balanceed "<<endl;
    }
    else
    {
        cout << "The parenthesis is not equal" <<endl;
    }
    
    return 0;
}