#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, c) for (int i = 0; i < (int)c; i++)

int main()
{
  ll h, w;
  cin >> h >> w;
  if (h == 1 || w == 1)
  {
    cout << 1 << endl;
  }
  cout << (h * w + 1) / 2 << endl;
}
