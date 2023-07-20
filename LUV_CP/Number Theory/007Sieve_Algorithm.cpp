#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 100;

/* Iterative Function to calculate (x^y)%p
in O(log y) */
unsigned long long power(unsigned long long x, 
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
  
    x = x % p; // Update x if it is more than or
    // equal to p
  
    while (y > 0) 
    {
      
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
  
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
  
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,  
                                            int p)
{
    return power(n, p - 2, p);
}
  
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
  
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
  
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
//q = 10 ^ 7 , N = 10^7;
signed main()
{
    int a, b, k;
    cin >> a >> b >> k;

    //Sieve Algorithm  --> N * log(log(N))

    vector<bool> isPrime(N, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    int ans = 0;
    int pct = 0;

    for (int i = a; i <= b; i++)
    {
        if (isPrime[i])
            pct++;
    }
    if (k > pct)
    {
        cout << -1;
        return 0;
    }

    else if (k == 1)
    {
        int prev = a - 1;
        int curr = 0;
        for (int i = a; i <= b; i++)
        {
            if (isPrime[i] or i == b)
            {
                curr = i;
                if (i == b)
                    curr++;
                ans = max(ans, curr - prev);
                prev = i;
            }
        }
    }
    else if (k > 1)
    {
        int ct = 0;
        int fp = 0;

        for (int i = a; i <= b; i++)
        {
            if (isPrime[i])
            {
                if (!ct)
                    fp = i;
                ct++;
            }
            if (ct == k)
            {
                ans = max(ans, i - (a - 1));
                break;
            }
        }
        int lp = 0;
        ct = 0;
        for (int i = b; i >= a; i--)
        {
            if (isPrime[i])
            {
                if (!ct)
                    lp = i;
                ct++;
            }
            if (ct == k)
            {
                ans = max(ans, b + 1 - i);
                break;
            }
        }
        int prev = a;
        for (int i = a + 1; i <= b; i++)
        {
            if (isPrime[i] or i == b)
            {
                ans = max(ans, i + 1 - prev);
                prev = i;
            }
        }
    }
    cout << ans;

    return 0;
}