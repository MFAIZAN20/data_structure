#include <iostream>
#include <cstring>
using namespace std;

class solution
{
    public:
    char data;
    solution *top;
    solution *next;
    int capacity;

    solution(int val)
    {
        next = NULL;
        top = NULL;
        data = val;
        capacity = 0;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
    
    char peek()
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
            return ;
        }
        else
        {
            solution* temp = top;
            top = top->next;
            char to_return =temp->data; 
            delete temp;
            temp = nullptr;
            capacity--;
            return to_return;
        }
    }
string cinverting_into_postfin(const string infix_string)
{
    string postfix;
    int i = 0;

    while (infix_string[i] != '\0')
    {
        char check = peek();
        
        if (infix_string[i] == '+' || '-')
        {
            if (check == '*' || '/' )
            {
                char x = pop();
                push(infix_string[i]);
                postfix = postfix + x;
            }
        }
        

        i++;

    }

    return postfix;
    
}
};

int main()
{
    string infix;
    cout << "Please Enter The Number In The infix Form " <<endl;
    getline(cin,infix);
    
    solution sol(0);
    return 0;
}