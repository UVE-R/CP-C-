# include <bits/stdc++.h>
using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;



int main()
{
    InTheNameOfGod


    long long b,p,n;

    while(cin>>b>>p>>n){
        ll ans = 1;
        
        if(n==1){
            cout<<0<<endl;
        }else if(b==1){
            cout<<1<<endl;
        }else if(p==0){
            cout<<1<<endl;
        }else if(b==1){
            cout<<0<<endl;
        }else{
        
            while(p>0){
                if(p %2 ==1){
                    ans = (ans*b) % n;
                }
                p/=2;
                b = (b*b) % n;
            }
            cout<<ans<<endl;
        }
        
    }
    return 0;
}
