#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int vis[N];
vector<int> ar[N];
void dfs(int v) // dfs traversal
{
  vis[v] = 1;
  cout << v << "->";
  for (int child : ar[v])
  {
    if (vis[child] == 0)
    {
      // cout << "child of " << v << " are " << child << endl;
      dfs(child);
    }
  }
  // main code
  // dfs(1);
}

void sssp(int v, int n, vector<int> &ss) // it provide shortest distance of every node from any 1 node.
{                                        // it doesn't give correct answer in case of cycle
  vis[v] = 1;
  for (int child : ar[v])
  {
    if (vis[child] == 0)
    {
      ss[child] = n;
      sssp(child, n + 1, ss);
    }
  }
  // main code
  // sssp(2, 1, ss);
  // cout << "Shortest path from 1" << endl;
  // for (int i = 1; i <= 9; i++)
  // {
  //   cout << i << ":" << ss[i] << endl;
  // }
}

int col[N]; // check bipartite graph
bool bipartite(int v, int c)
{
  vis[v] = 1;
  col[v] = c;
  for (int child : ar[v])
  {
    if (vis[v] == 0)
    {
      if (bipartite(child, c ^ 1) == false)
      {
        return false;
      }
    }
    else
    {
      if (col[v] == col[child])
      {
        return false;
      }
    }
  }
  return true;
}

int cont = 0; // count no. of component in the graph
void count_component(int v, int n)
{
  for (int i = 1; i <= n; i++)
  {
    if (vis[i] == 0)
    {
      dfs(i);
      cont++;
    }
  }
  // main code
  //  count_component(1, n);
  //  if ( cont == 1)
  //  {
  //    cout << "single component" << endl;
  //  }
}

bool cycle(int v, int par) // cycle detection in undirected graph
{
  vis[v] = 1;
  for (int child : ar[v])
  {
    if (vis[child] == 0)
    {
      if (cycle(child, v) == true)
      {
        return true;
      }
    }
    else
    {
      if (child != par)
      {
        return true;
      }
    }
  }
  return false;
}
// if it return false --> no cycle

void diameter(int root, int n, vector<int> ss) // diameter of the tree
{
  int max = 0, maxi = -1, maxi2 = -1;
  sssp(root, 1, ss);
  for (int i = 1; i <= n; i++)
  {
    if (max < ss[i])
    {
      max = ss[i];
      maxi = i;
    }
  }
  fill(vis, vis + n + 1, 0);
  ss.clear();
  max = 0;
  sssp(maxi, 1, ss);
  for (int i = 1; i <= n; i++)
  {
    if (max < ss[i])
    {
      max = ss[i];
      maxi2 = i;
    }
  }
  cout << "Diameter of tree is " << max << endl;
  cout << "It's between " << maxi << " & " << maxi2 << endl;
}
// in main
// diameter(any node, #nodes,ss)

/////////////////////////////////////////////////////////////////////////////////////////////////

int dis[N];
void bfs_sssp(int v, int n)
{
  queue<int> q;
  vis[v] = 1;
  dis[v] = 0;
  q.push(v);
  while (!q.empty())
  {
    int current = q.front();
    q.pop();
    for (auto child : ar[current])
    {
      if (vis[child] == 0)
      {
        dis[child] = dis[current] + 1;
        vis[child] = 1;
        q.push(child);
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    cout << "distance of " << i << " from " << v << " " << dis[i] << endl;
  }
}

int tin[N], low[N], timer = 0; // bridges in graph
void bridge(int v, int p)
{
  vis[v] = true;
  tin[v] = low[v] = timer++;
  for (int child : ar[v])
  {
    if (child == p)
      continue;
    if (vis[child])
    {
      low[v] = min(low[v], tin[child]);
    }
    else
    {
      bridge(child, v);
      low[v] = min(low[v], low[child]);
      if (low[child] > tin[v])
      {
        cout << v << "-" << child << " is a bridge";
      }
    }
  }
}
// bridge(4, -1);

void articulation(int v, int p = -1) // articulation point in graph
{
  vis[v] = true;
  tin[v] = low[v] = timer++;
  int children = 0;
  for (int child : ar[v])
  {
    if (child == p)
      continue;
    if (vis[child])
    {
      low[v] = min(low[v], tin[child]);
    }
    else
    {
      articulation(child, v);
      low[v] = min(low[v], low[child]);
      if (low[child] >= tin[v] && p != -1)
        cout << v << " is a articulation point";
      ++children;
    }
  }
  if (p == -1 && children > 1)
    cout << v << " is a articulation point";
}
// articulation(4, -1);

///////////////////////////////////////////////////////////////////////////////////////////////////

struct dsu // implementation of dsu
{
  int par[100100];
  int rank[100100];

  void init(int n)
  {
    for (int i = 1; i <= n; i++)
    {
      par[i] = i;
      rank[i] = 1;
    }
  }
  int find(int x)
  {
    if (par[x] == x)
      return x;
    else
      return (par[x] = find(par[x]));
  }
  void unite(int x, int y)
  {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx == rooty)
    {
      return;
    }
    if (rank[rootx] < rank[rooty])
      swap(rootx, rooty);
    rank[rootx] += rank[rooty];
    par[rooty] = rootx;
    rank[rooty] = 0;
  }
};
// main
//   dsu s;
//   cout << "enter no. of roots" << endl;
//   int n;
//   cin >> n;
//   s.init(n);
//   s.unite(1, 2);
//   s.unite(1, 3);
//   for (int i = 1; i <= n; i++)
//   {
//     cout << "Size of " << i << " is " << s.rank[i] << endl;
//     cout << "Parent of " << i << " is " << s.par[i] << endl;
//   }

void krushkal()
{
  int n, m;
  dsu s;
  int sum = 0;
  vector<vector<int>> v;
  cin >> n >> m;
  s.init(n);

  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    v.push_back({w, a, b});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m; i++)
  {
    if (s.find(v[i][1]) != s.find(v[i][2]))
    {
      s.unite(v[i][1], v[i][2]);
      sum += v[i][0];
    }
  }
  cout << sum;
}
// main
//  just use krushkal(), it also input n,m

int main()
{
  // cout << "Enter the no. of nodes and edges" << endl;
  // int n, m;
  // cin >> n >> m;
  // vector<int> ss(n, 0);
  // while (m--)
  // {
  //   int a, b;
  //   cin >> a >> b;
  //   ar[a].push_back(b);
  //   ar[b].push_back(a);
  // }
  // articulation(4, -1);
  krushkal();
}