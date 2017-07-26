// stack::push/pop/empty
#include <iostream>       // std::cout
#include <stack>          // std::stack

int main() {
  std::stack<int> mystack;
  int sum(0);

  for (int i=1;i<=10;i++) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';

  return 0;
}
