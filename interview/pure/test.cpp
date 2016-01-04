#include <iostream>
using namespace std;

class A {};
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    return 0;
}
