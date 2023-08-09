#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
  return a.second > b.second;
}

int main()
{
  vector<pair<int, int>> s;
  int n, i, c;
  cin >> n;
  for (i = 2; i <= n; i++)
  {
    if (n % i == 0)
    {
      c = 0;
      while (n % i == 0)
      {
        c++;
        n /= i;
      }
      s.push_back(make_pair(i, c));
    }
  }
  sort(s.rbegin(), s.rend());
  for (int i = 0; i < s.size(); i++)
  {
    cout << s[i].first << " " << s[i].second << endl;
  }
}