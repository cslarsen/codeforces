#include <iostream>
#include <stdint.h>

using namespace std;
typedef uint64_t N;

int main()
{
  ios_base::sync_with_stdio(false);

  N n, m, a;
  while ( cin >> n >> m >> a ) {
    const N w = n/a + (n%a > 0);
    const N h = m/a + (m%a > 0);
    cout << w*h << endl;
  }
}
