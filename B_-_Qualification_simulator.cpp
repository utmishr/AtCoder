#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, c) for (int i = 0; i < (int)c; i++)

int main()
{
  ll c, a, b;
  cin >> c >> a >> b;
  string s;
  cin >> s;
  ll total = 0, bwin = 0;
  rep(i, c)
  {
    if (s[i] == 'a' && total < a + b)
    {
      total++;
      cout << "Yes" << endl;
    }
    else if (s[i] == 'b' && total < a + b && bwin < b)
    {
      cout << "Yes" << endl;
      total++;
      bwin++;
    }
    else
    {
      cout << "No" << endl;
    }
  }
}