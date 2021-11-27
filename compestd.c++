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
int a,b,x,ans=0;


int32_t main() {
    string s;
    cin>>s;
    x=s.size();
    if(x==1)
    {
        if(s[0]=='0' || s[0]=='_' || s[0]=='X')
        {
            cout<<1;
        } else
            cout<<0;
        return 0;
    }
    char xass,currchar;
    if(x==2)
        a=25;
    else
        a=pow(10,x-1);
    for (int i = a; i < pow(10,x) ; i+=25) {
        string curr= to_string(i);
        xass='_';
        b=1;

        for (int j = 0; j < x; ++j) {
            currchar=curr[j];
            if(s[j]=='_')continue;
            if(s[j]=='X')
            {
                if(xass!='_' && xass!=currchar)
                {
                    b=0;
                    break;
                }
                xass=currchar;
            }
            else if(currchar!=s[j]){
//                cout<<i<<s[j]<<j<<currchar;
//                return 0;
                b=0;
                break;
            }
        }
//        cout<<i<<" "<<b<<"\n";
        ans+=b;

    }
    cout<<ans;
    return 0;
}
