#include <iostream>
#include <thread>
using namespace std;

void threadFunc()
{
    cout << "hello world!" << endl;
}

int main()
{
    thread t(threadFunc);

    t.join();

    return 0;
}
