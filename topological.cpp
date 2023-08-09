#include <bits/stdc++.h>
using namespace std;

vector<int> ar[100];
vector<int> res;

void topological_sort(int in[], int n)
{
  queue<int> q;
  for (int i = 1; i <= n; i++)
  {
    if (in[i] == 0)
    {
      q.push(i);
    }
  }
  while (!q.empty())
  {
    int cur = q.front();
    res.push_back(cur);
    q.pop();
    for (int node : ar[cur])
    {
      in[node]--;
      if (in[node] == 0)
      {
        q.push(node);
      }
    }
  }
  for (auto i : res)
  {
    cout << i << " ";
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  int in[n] = {0};
  int a, b;
  while (m--)
  {
    cin >> a >> b;
    ar[a].push_back(b);
    in[b]++;
  }
  topological_sort(in, n);
}
