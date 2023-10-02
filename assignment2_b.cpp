#include <iostream>
#include <cstring>
using namespace std;

struct node
{
    char data;
    node *next;
    node *top = NULL;
    int length;

    node(int val)
    {
        next = NULL;
        top = NULL;
        length = 1;
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
        node *n = new node(s);
        n->next = top;
        top = n;
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
            node *temp = top;
            top = top->next;
            char to_return =temp->data; 
            delete temp;
            temp = nullptr;
            return to_return;
        }
    }
bool isOparand(const char c)
{
    if (c == '+' || c == '-' || c == '*' || c== '/')
    {
        return false;
    }
    else
        return true;
}

int presedence(char pre)
{
    if (pre == '-' || pre == '+')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

string convert_infinx_to_postfix(const string infix_string)
{
    string postfix;
    node note(0);

    for (char character : infix_string)
    {   
        if (!isOparand(character))
        {
            char check = note.data;
            if (presedence(character) > presedence(check))
            {
                char x = note.pop();
                note.push(character);
                postfix += x;
            }
            else
            {
                note.push(character);
            }
        }
        else
        {
            postfix = postfix + character;
        }
    }
    while (!isEmpty())
    {
        char pop_value =  note.pop();
        postfix += pop_value;
    }
    
    return postfix;
}
};

int main()
{
    string infix;
    cout << "Please Enter The Number In The infix Form " <<endl;
    // getline(cin,infix);
    infix = "Abd-ds+dd/";
    node solution_object(0);

    string return_string = solution_object.convert_infinx_to_postfix(infix);
    cout << "The postfix is : " << return_string <<endl;
    return 0;
}