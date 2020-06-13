#include <iostream>
#include "LinkedListSharedPointer.h"

int
main()
{
  LinkedList<int> list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  std::cout<<list<<std::endl;
  return 0;
}
