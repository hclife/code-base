// constructing queues
#include <deque>          // std::deque
#include <list>           // std::list
#include <queue>          // std::queue
#include <iostream>       // std::cout
using namespace std;

int main() {
  std::deque<int> mydeck(3,100);   // deque with 3 elements
  std::list<int> mylist(2,200);    // list with 2 elements

  std::queue<int> firstq;          // first empty queue
  std::queue<int> secondq(mydeck); // second queue initialized copy deque
  // third empty queue with list as underlying container
  std::queue<int,std::list<int> > thirdq;
  std::queue<int,std::list<int> > fourthq(mylist);

  std::cout << "size of firstq: " << firstq.size() << '\n';
  std::cout << "size of secondq: " << secondq.size() << '\n';
  std::cout << "size of thirdq: " << thirdq.size() << '\n';
  std::cout << "size of fourthq: " << fourthq.size() << '\n';

  return 0;
}
