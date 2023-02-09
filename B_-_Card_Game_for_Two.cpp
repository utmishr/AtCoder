#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, c) for (int i = 0; i < (int)c; i++)

int main()
{
  ll n, sum = 0, sum2 = 0;
  cin >> n;
  ll a[n];
  rep(i, n)
  {
    cin >> a[i];
    sum = sum + a[i];
  }
  sort(a, a + n, greater<ll>());
  rep(i, n)
  {
    sum2 = sum2 + a[i];
    i++;
  }
  cout << sum2 - (sum - sum2);
}