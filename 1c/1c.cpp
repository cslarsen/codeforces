#include <iostream>
#include <math.h>

using namespace std;

typedef double F;

struct rads {
  F r;

  rads(F v) : r(v<0? v+2*M_PI : v) {
  }

  F degs() const {
    return 360.*r/(2*M_PI);
  }

  operator const F& () const {
    return r;
  }
};

struct pos {
  F x, y;
  pos(F x_=0, F y_=0) : x(x_), y(y_) {
  }

  friend ostream& operator<<(ostream& o, const pos& p) {
    return o << p.x << "," << p.y;
  }
};

struct vec {
  F x, y;
  vec(pos origo, pos p) : x(p.x - origo.x), y(p.y - origo.y) {
  }
};

// counter-clockwise directional angle
rads angle(vec a, vec b)
{
  return atan2(b.y, b.x) - atan2(a.y, a.x);
}

int main()
{
  pos a, b, c;
  cin >> a.x >> a.y
      >> b.x >> b.y
      >> c.x >> c.y;

  cout << angle(vec(a,c), vec(c,b)).degs() << endl;
}
