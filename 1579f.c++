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
int a,b,x,n,d,curridx;


void test()
{
    int ans=0;
    cin>>n>>d;
    vi arr(n),temp;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    for (int i = 0; i < n; ++i) {
        curridx=i;
        while (arr[curridx]!=-1)
        {
            temp.push_back(arr[curridx]);
            arr[curridx]=-1;
            curridx=(curridx+d)%n;
        }
        int ts=temp.size();
        for (int j = 0; j < ts; ++j) {
            temp.push_back(temp[j]);
        }
        int mx=0,tmx=0;
        for (int j = 0; j < 2*ts; ++j) {
            if(temp[j]==1)
            {
                mx++;
                tmx=max(tmx,mx);
            } else
            {
                mx=0;
            }
        }
        if(ts<tmx)
        {
            cout<<-1<<endl;
            return;
        }
        ans=max(ans,tmx);
        temp.resize(0);
    }
    cout<<ans<<endl;

}
int32_t main() {

    w{
        test();
    }

    return 0;
}
