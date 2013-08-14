#include <string>
using namespace std;

class JumpFurther {
  public:
  int furthest(int N, int badStep) {
    int i;
    bool bad = false;
    for (i = 1; i <= N; i++) {
      if (i * (i + 1) / 2 == badStep) {
        bad = true;
        break;
      } else if (i * (i + 1) / 2 > badStep) {
        break;
      }
    }

    int sum = N*(N+1)/2;
    return (bad)? sum - 1 : sum;
  }
};
