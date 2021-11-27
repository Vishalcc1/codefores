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

void test(int a,int b,int x)
{
    int sm=min(a,b),bg=max(a,b);
    if(sm==0)
    {
        if(bg==x)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        return;
    }
    if(a==b) {
        if (a == x) {
            cout << "YES" << endl;

        } else {
            cout<<"NO"<<endl;
        }
        return;
    }
    if(x>bg)
    {
        cout<<"NO"<<endl;return;
    }
    int gap=bg-sm,rem;
    if(gap>sm)
    {
        rem=bg%sm;
        if((x-rem)>0 && (x-rem)%sm==0)
        {
            cout<<"YES"<<endl;
            return;
        }
        test(sm,rem,x);
        return;

    } else
    {
        rem=bg%gap;
        if((x-rem)>0 && (x-rem)%gap==0)
        {
            cout<<"YES"<<endl;
            return;
        }
        test(gap,rem,x);
        return;
    }
}


int32_t main()
{
    w{
        cin>>a>>b>>x;
        test(a,b,x);
    }
    return 0;
}