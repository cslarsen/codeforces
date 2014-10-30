#include <iostream>
#include <stdint.h>
#include <ctype.h>

#define BUFLEN 32
using namespace std;
typedef uint32_t N;

// BC23 -> R23C55
static void tocoord(const char* s)
{
  N row=0, col=0;

  while ( !isdigit(*s) )
    col = col*26 + (1 + *s++ - 'A');

  while ( isdigit(*s) )
    row = row*10 + (*s++ - '0');

  cout << "R" << row << "C" << col;
}

// R23C55 -> BC23
static void tocell(const char* s)
{
  static char buf[BUFLEN] = {0};

  N row=0, col=0;

  for ( ++s; isdigit(*s); ++s )
    row = row*10 + *s - '0';

  for ( ++s; isdigit(*s); ++s )
    col = col*10 + *s - '0';

  char *t = buf+sizeof(buf)-2;
  while ( col ) {
    *t-- = 'A' + (--col % 26);
    col /= 26;
  }
  cout << t+1 << row;
}

static bool iscoord(const char* s)
{
  if ( *s++ == 'R' && isdigit(*s) ) {
    while ( isdigit(*++s) );
    if ( *s++ == 'C' )
      return isdigit(*s);
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);

  N rows;
  cin >> rows;

  static char s[32] = {0};
  for ( N n=0; n<rows; ++n ) {
    cin >> s;
    (iscoord(s) ? tocell : tocoord)(s);
    cout << endl;
  }
}
