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

void test()
{
    cin>>x;
//    cout<<x<<endl;
    vector<pii> arr(x);
    vi ans(x);
    for (int i = 0; i < x; ++i) {
        cin>>arr[i].first;
        arr[i].second=i;
    }
    sort(arr.begin(),arr.end());
    int x1=1,sums=0;
    for (int i = arr.size()-1; i >=0 ; i-=2) {
        ans[arr[i].second]=x1;
        sums+=(2*arr[i].first*x1);
        if(i!=0)
        {
            ans[arr[i-1].second]=-1*x1;
            sums+=(2*arr[i-1].first*x1);
        }
        x1++;
    }
    cout<<sums<<"\n";
    cout<<0<<" ";
    for (int i = 0; i < x; ++i) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}


int32_t main() {

    w{
        test();
    }
    return 0;
}