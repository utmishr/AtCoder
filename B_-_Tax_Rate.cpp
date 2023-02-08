#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, c) for (int i = 0; i < (int)c; i++)

int main()
{
  ll n;
  cin >> n;
  bool flag = 0;
  rep(i, n + 1)
  {
    // float p = i * 1.08;
    // if (p - int(p) <= .5)
    // {
    //   p = int(p);
    // }
    // else
    // {
    //   p = int(p + 1);
    // }
    if (int(i * 1.08) == n)
    {
      flag = 1;
      cout << i;
    }
  }
  if (flag == 0)
  {
    cout << ":(";
  }
}