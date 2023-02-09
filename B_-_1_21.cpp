#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, c) for (int i = 0; i < (int)c; i++)

// converting string to int use - stoi(str);
// sorting in descending order use - greater<ll>()

int main()
{
  string a, b;
  cin >> a >> b;
  double c = sqrt(stoi(a + b));
  if (c - int(c) > 0)
  {
    cout << "No";
  }
  else
  {
    cout << "Yes";
  }
}