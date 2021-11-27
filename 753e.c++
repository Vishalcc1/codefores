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
int a,b,x,row,col,cmx,cmn,rmx,rmn,rcurr,ccurr;
string  s;

void test()
{
    cmx=0,cmn=0,rmx=0,rmn=0,rcurr=0,ccurr=0;
    cin>>row>>col>>s;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]=='L')
        {
            ccurr--;
            cmn=min(cmn,ccurr);
        } else if( s[i]=='R')
        {
            ccurr++;
            cmx=max(cmx,ccurr);
        }else if( s[i]=='D')
        {
            rcurr++;
            rmx=max(rmx,rcurr);
        } else
        {
            rcurr--;
            rmn=min(rmn,rcurr);
        }
        if(cmx-cmn >= col)
        {
            if(s[i]=='L')
            {
                cout<<row-rmx<<" "<<col-cmx<<"\n";
            } else
            {
                cout<<row-rmx<<" "<<-1*cmn+1<<"\n";
            }
            return;
        }
        if(rmx-rmn >= row)
        {
//            cout<<i<<" "<<s[i]<<endl;
            if(s[i]=='D')
            {
                cout<<-1*rmn+1<<" "<<col-cmx<<"\n";
            } else
            {
                cout<<row-rmx<<" "<<col-cmx<<"\n";
            }
            return;
        }
    }

    cout<<row-rmx<<" "<<col-cmx<<"\n";

}
int32_t main() {

    w{
        test();
    }

    return 0;
}
