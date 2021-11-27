#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}
#define ff            first
#define ss            second
#define int           long long
#define pb            push_back
#define mp            make_pair
#define pii           pair<int,int>
#define vi            vector<int>
#define mii           map<int,int>
#define pqb           priority_queue<int>
#define pqs           priority_queue<int,vi,greater<int>>
#define setbits(x)    __builtin_popcountll(x)
#define zrobits(x)    __builtin_ctzll(x)
#define mod           1000000007
#define inf           1e18
#define ps(x,y)       fixed<<setprecision(y)<<x
#define mk(arr,n,type) type *arr=new type[n];
#define w           int x125;cin>>x125;while(x125--)
#define F10            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(long long x, int y, int p)
{
    int res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
void test()
{
    int a,b,x,n,m,l,r,mn;
    cin>>n>>m;
    int ans=0;
    vector<vector<int>> arr(31,vi(n+1,-1)),arr1(31,vi(2,0));
    for (int i = 0; i < m; ++i) {
        cin>>l>>r>>x;
        ans|=x;
    }
    cout<<power(2,n-1,mod)*ans%mod<<endl;

}
int32_t main() {

    w{
        test();
    }
    return 0;
}