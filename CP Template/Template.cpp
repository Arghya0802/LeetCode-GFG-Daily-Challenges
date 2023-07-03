#include <bits/stdc++.h>
using namespace std;
#define int long long
//#define endl "\n"
#define mod 1000000007
#define double long double
#define INT_MIN -1000000000000000
#define INT_MAX 1e18
int pwr(int x,int n)
{
    int res=1;
    if(n==0)
        return 1;
    if(n==1)
        return (x%mod);
    if(n%2)
        res=x%mod;
    int temp=pwr(x,n/2);
    return (res*((temp*temp)%mod))%mod;
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
int nCrModp(int n, int r, int p)
{
    if (r > n - r)
        r = n - r;
    int C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j - 1]) % p;
    }
    return C[r];
}
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
 
    return (ceil(log2(n)) == floor(log2(n)));
}

void solve()
{
    // write your code here
}
signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    cin>>t;    
    
    while(t--)
    {
        solve();
    }
}
