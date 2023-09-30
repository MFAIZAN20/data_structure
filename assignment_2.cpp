#include <iostream>
using namespace std;

class solution
{
    public:
    int data;
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

int* return_temperature_to_wait(int *arr[])
{

} 

bool 
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
    int temperatures = [73,74,75,71,69,72,76,73];
    return 0;
}