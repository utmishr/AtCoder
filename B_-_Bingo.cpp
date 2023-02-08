#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, c) for (int i = 0; i < (int)c; i++)

int main()
{
  int n, a[3][3], b[10];
  bool f[3][3] = {0};
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
      cin >> a[i][j];
  }
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        if (a[i][j] == b[k])
          f[i][j] = 1;
      }
    }
  }
  bool flag = 0;
  for (int i = 0; i < 3; i++)
  {
    if (f[0][i] && f[1][i] && f[2][i] && flag == 0)
    {
      flag = 1;
      cout << "Yes";
    }
  }
  for (int i = 0; i < 3; i++)
  {
    if (f[i][0] && f[i][1] && f[i][2] && flag == 0)
    {
      flag = 1;
      cout << "Yes";
    }
  }
  if (f[0][0] && f[1][1] && f[2][2] && flag == 0)
  {
    flag = 1;
    cout << "Yes";
  }
  if (f[0][2] && f[1][1] && f[2][0] && flag == 0)
  {
    flag = 1;
    cout << "Yes";
  }
  if (flag == 0)
  {
    cout << "No";
  }
}