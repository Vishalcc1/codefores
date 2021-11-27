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
//typedef tree<int,null_type,rb_tree_tag,tree_order_statistics_node_update> pbds;

void fun()
{
    int n;
    string s;
    cin>>n>>s;
    for (int i = 0; i <n-1 ; ++i) {
        if(s[i]=='a' && s[i+1]=='a')
        {
            cout<<2<<endl;
            return;
        }
    }
    for (int i = 0; i <n-2 ; ++i) {
        if(s[i]=='a' && s[i+2]=='a')
        {
            cout<<3<<endl;
            return;
        }
    }
    for (int i = 0; i <n-3 ; ++i) {
        if(s[i]=='a' && s[i+3]=='a' && s[i+1]!=s[i+2])
        {
            cout<<4<<endl;
            return;
        }
    }
    for (int i = 0; i < n-6; ++i) {
        int ca=('b'==s[i+2]);
        ca+=('b'==s[i+4]);
        ca+=('b'==s[i+1]);
        ca+=('b'==s[i+5]);
        if(s[i]=='a' && s[i+3]=='a' && s[i+6]=='a' && ca==2)
        {
            cout<<7<<endl;
            return;
        }
    }
    cout<<-1<<endl;
    return;
}

int32_t main()
{

    w{
        fun();
    }
    return 0;
}