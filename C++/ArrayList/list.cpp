#include <iostream>
#include "ArrayList.h"

using namespace std;

int main(){
  ArrayList<int> list;
  list.add(42);
  list.add(26);
  list.add(90);
  list.add(-54);

  for(int i=0;i<list.getSize();i++)
    cout << list.get(i) << " ";
  
  cout << "\nList at location 2: " << list.get(2) << endl;

  list.remove(2);

  for(int i=0;i<list.getSize();i++)
    cout << list.get(i) << " ";
  cout << endl;
  return 0;
}
