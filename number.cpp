#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}
// gcd(a, b)

bool isprime(int n)
{
  if (n == 1)
  {
    return false;
  }
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}
// isprime(14)

void SieveOfEratosthenes(int n)
{
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++)
  {
    if (prime[p] == true)
    {
      for (int i = p * p; i <= n; i += p) // i starting from p*p as p*(1,2,3...p-1) must already been searched, think!
        prime[i] = false;
    }
  }
}
// SieveOfEratosthenes(n);

void PrimeFact(int n)
{
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0) // this will be possible onl if i will be prime, think!
    {
      int count = 0;
      while (n % i == 0)
      {
        count++;
        n = n / i;
      }
      cout << i << " " << count << endl;
    }
  }
  if (n > 1) // it's not possible for there to be two prime factors greater than the square root of n. This is because if n has two prime factors, both of which are greater than the square root of n, their product would be greater than n.
  {
    cout << n << " " << 1 << endl;
  }
}
// PrimeFact(n);

long long binpow(long long a, long long b)
{
  if (b == 0)
    return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
// binpow(a, b);

int main()
{
  int b = 13, a = 5;
  PrimeFact(3315);
}