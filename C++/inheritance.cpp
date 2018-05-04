#include <iostream>

using namespace std;

class A{
public:
  virtual void print(){//w/o virtual keyword, shit line prints 'A'
    cout << "A" << endl;
  }
};

class B : public A{
public:
  void print(){
    cout << "B" << endl;
  }
};

int main(){
  A a;
  B b;
  A* p;

  a.print();
  b.print();

  p = &a;
  p->print();
  p=&b;//shit line
  p->print();

  B* q;
  q->print();
  return 0;
}
