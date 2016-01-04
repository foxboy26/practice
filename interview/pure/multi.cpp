#include <iostream>
using namespace std;

class Top {
    public:
        int a;
};

class Left : virtual public Top {
    public:
        int b;
};

class Right : virtual public Top {
    public:
        int c;
};

class Bottom : public Left, public Right {
    public:
        int d;
};

int main()
{
    Bottom* bottom = new Bottom();
    Left* left = bottom;
    
    return 0;
}
