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

    void push(int s)
    {
        solution *n = new solution(s);
        n->next = top;
        top = n;;
        capacity++;
    }

    void pop()
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
            delete temp;
            temp = nullptr;
            capacity--;
        }
    }

void return_temperature_to_wait(int arr[],int size)
{
    for (int i = 0; i < size ; i++)
    {
        int count = 0;
        bool find_weather = false;
        for (int j = i+1; j < size; j++)
        {
            count++;
            if (arr[j] > arr[i]) 
            {
                find_weather = true;
                break;
            }
        }
        if (find_weather == true)
        {
            push(count);
        }
        else
        {
            push(0);
        }
        count = 0;
    }
}
void printStack()
{
    if (top == nullptr)
    {
        cout << "The Stack is empty "<<endl;
        return;
    }
    
        solution *currentNode = top;
        while (currentNode != nullptr) 
        {
            std::cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }

        std::cout << std::endl;
    }
};


int main()
{
    int temperatures[] = {73,74,75,71,69,72,76,73};
    solution sol(0);
    sol.return_temperature_to_wait(temperatures,8);

    sol.printStack();
    return 0;
}
