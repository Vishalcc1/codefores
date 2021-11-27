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
#define mod           998244353
#define inf           1e18
#define ps(x,y)       fixed<<setprecision(y)<<x
#define mk(arr,n,type) type *arr=new type[n];
#define w           int x125;cin>>x125;while(x125--)
#define F10            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
int a,b,x;

int solve(vi &arr)
{
    for (int i = 0; i < arr.size()/2; ++i) {
        if(arr[i]!=arr[arr.size()-1-i])
            return -1;
    }
    return 1;
}
void test()
{
    int n;
    cin>>n;
    vi arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    for (int i = 0; i <=n/2 ; ++i) {
        if(arr[i]==arr[n-i-1])
        {
            arr[i]=arr[n-i-1]=-1;
        } else
        {
            vi arr1;
            int j;
            j=arr[i];
            for (int k = i; k <=n-i-1 ; ++k) {
                if(j!=arr[k])
                    arr1.push_back(arr[k]);
            }
            if(solve(arr1)==1)
            {
                cout<<"YES\n";
                return;
            }
            arr1.resize(0);
            j=arr[n-i-1];
            for (int k = i; k <=n-i-1 ; ++k) {
                if(j!=arr[k])
                    arr1.push_back(arr[k]);
            }
            if(solve(arr1)==1)
            {
                cout<<"YES\n";
                return;
            }
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}

int32_t main() {


    w{
        test();
    }
    return 0;

}