#include<bits/stdc++.h>
using namespace std;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>

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
//typedef tree<int,null_type,rb_tree_tag,tree_order_statistics_node_update> pbds;

void testcase()
{
    int n,a,ans=0;
    vi arr(64,0);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a;
    }
    for (int i = 0; i < n; ++i) {
        cin>>a;
        for (int j = 0; j < 64; ++j) {
            if((a&(1ll<<j)))
            {
                ans=ans^(1ll<<j);
            }
        }
    }
    if(ans==0)
        cout<<ans<<"\n";
    else
        cout<<1<<endl;
}
int32_t main() {
	w{
        testcase();
    }
    return 0;
}
