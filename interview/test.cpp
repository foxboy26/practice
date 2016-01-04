#include <iostream>
using namespace std;

struct A {
  int val;
  char data[10];
};

struct B {
  int val;
};

int main() {
  A a1;
  a1.val = 1;
  for (int i = 0; i < 9; i++)
    a1.data[i] = 'a';
  a1.data[9] = '\0';

  A a2 = a1;
  cout << "before: " << a1.val << " " << a1.data << endl;
  cout << "before: " << a2.val << " " << a2.data << endl;
  a2.val = 2;
  a2.data[0] = 'b';

  cout << "after: " << a1.val << " " << a1.data << endl;
  cout << "after: " << a2.val << " " << a2.data << endl;
  
  B b;
  b.val = 2;

  char* data = new char[10];
  cout << "sizeof(data) " << sizeof(data) << endl;
  memset(data, 0, sizeof(char) * 10);
  B* ptr = reinterpret_cast<B*> (data);
  ptr->val = 2;

  for (int i = 0; i < 10; i++) {
    cout << (int) data[i] << " ";
  }
  cout << endl;

  return 0;
}
