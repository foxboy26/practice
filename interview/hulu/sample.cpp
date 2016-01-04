#include <iostream>
using namespace std;

int main()
{
  int T;
  cin >> T;
  int a, b;
  for (int t = 1; t <= T; t++) {
    cin >> a >> b;
    cout << "Case #" << t << "\n";
    cout << a + b << "\n";
  }

  return 0;
}
