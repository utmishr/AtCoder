#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, c) for (int i = 0; i < (int)c; i++)

// converting string to int use - stoi(str);
// sorting in descending order use - greater<ll>()

int main()
{
  int n;
  cin >> n;
  if (n == 1)
  {
    cout << 1;
  }
  else
  {
    rep(i, n)
    {
      if (pow(2, i) > n)
      {
        cout << pow(2, i - 1);
        break;
      }
    }
  }
}