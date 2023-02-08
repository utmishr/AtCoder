#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, c) for (int i = 0; i < (int)c; i++)

int main()
{
  ll n, m, c;
  cin >> n >> m >> c;
  ll b[m], a[m];
  rep(i, m)
  {
    cin >> b[i];
  }
  ll sum = 0, count = 0;
  rep(i, n)
  {
    sum = 0;
    rep(i, m)
    {
      cin >> a[i];
      sum = sum + a[i] * b[i];
    }
    if (sum = sum + c > 0)
    {
      count++;
    }
  }
  cout << count;
}