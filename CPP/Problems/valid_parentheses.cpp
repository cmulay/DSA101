/*
  Question:
  valid parentheses: you will be provided with a string of parenthesis (eg: "(())") check
  whether it is a valid set of parenthesis or not

  valid: a valid parenthesis would look like eg: "((()))", "()(())"

  invalid: an invalid set will look like eg: "())", "((()(())"

  solution:
    This problem can be solved using stack, because when we see a ')' (closing parenthese) then the most
    recent '(' (open parenthese) will its pair.

    we will loop through the given string and push the opening parenthese "(" to the stack and peek the
    stack when we encounter ")" closing parentheses, if the top element in stack is "(" it will be the most 
    recent opend parenthese and we will pop the element from stack else we will push ")" to stack and iterate till
    the end

    if stack is empty we return true (all paranthese have their pair)
    else return false

  testcases:
    (((())))  -> true
    ()())(()) -> false
    (((()))   -> false
    ()()()()  -> true
*/
#include <iostream>
using namespace std;
bool isValid(string);

class Stack
{
private:
  char stack[10];
  int top = -1;

public:
  bool isEmpty()
  {
    if (top == -1)
      return true;
    return false;
  }

  char peek()
  {
    return stack[top];
  }

  void push(int val)
  {
    top++;
    stack[top] = val;
  }

  char pop()
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
};

int main()
{
  bool result;
  result = isValid("(((()))");
  cout << (result ? "true" : "false");
  return 0;
}

bool isValid(string parenthese)
{
  if (parenthese.length() % 2 != 0)
    return 0;
  Stack stack = Stack();
  for (int i = 0; i < parenthese.length(); i++)
  {
    if (parenthese[i] == '(')
    {
      stack.push(parenthese[i]);
    }
    else if (stack.peek() == '(')
    {
      stack.pop();
    }
    else
    {
      stack.push(parenthese[i]);
    }
  }
  return stack.isEmpty();
}