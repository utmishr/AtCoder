#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
  ll n;
  cin >> n;
  ll sum = 0;
  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum = sum + a[i];
  }
  ll p = sum / n;
  sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += (a[i] - p) * (a[i] - p);
  }
  ll sum2 = 0;
  p++;
  for (int i = 0; i < n; i++)
  {
    sum2 += (a[i] - p) * (a[i] - p);
  }
  cout << min(sum, sum2);
}