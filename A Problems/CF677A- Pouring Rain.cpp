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

    double d,h,v,e;
    cin>>d>>h>>v>>e;

    double pi = 2*acos(0.0);
    double area = (pi*d*d)/4;
    
    //To calculate the time, we first need to calculate the loss of height due to the water being drunk
    //The loss of the height water in a given time is v/area - e
    //Which is expressed in cm/s
    //h is expressed in cm
    //So cm/(cm/s) => (cm/cm)*s => s (which is time)
    //Therefore the full equation is : h / (v / (pi*d*d)/4) - e   
    
    if(v/area > e){
        cout<<"YES"<<endl;
        cout<<setprecision(11)<< h/ ((v/area) - (e))<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}
