#include <iostream>
using namespace std;
#define LENGTH 5

// Stack created with array
class Stack
{
private:
  // our stack (where our values will get stored)
  int stack[LENGTH];
  int top = -1;

public:
  // returns true if stack is full (i.e)
  bool isFull()
  {
    if (top == LENGTH - 1)
      return true;
    return false;
  }

  // returns true if stack is empty
  bool isEmpty()
  {
    if (top == -1)
      return true;
    return false;
  }

  // returns top element in the stack
  int peek()
  {
    return stack[top];
  }

  // take an interger value and adds it to the stack
  void push(int val)
  {
    if (isFull())
    {
      cout << "Stack is full" << endl;
      return;
    }
    top++;
    stack[top] = val;
    cout << "Successfully " << val << " Added to stack" << endl;
  }

  // removes the top element from the stack and returns that element
  int pop()
  {
    if (isEmpty())
    {
      cout << "Stack is empty" << endl;
      return 0;
    }
    else
    {
      int topElement = stack[top];
      top--;
      return topElement;
    }
  }

  // displays stack
  void display()
  {
    if (isEmpty())
    {
      cout << "Stack is empty" << endl;
    }
    else
    {
      for (int i = top; i >= 0; i--)
      {
        cout << stack[i] << endl;
      }
    }
  }
};

int main()
{
  Stack stack = Stack();
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.display();
  return 0;
}