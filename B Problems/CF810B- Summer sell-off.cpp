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

    int n,f;
    cin>>n>>f;
    vector<tuple<ll, ll, ll>>v;

    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        v.push_back( make_tuple(min(2*a,b) - min(a,b) ,a,b));
    }

    sort(v.begin(), v.end());

    ll sum = 0;

    for(int i=0;i<f;i++){
       get<1>(v[n-1-i]) *= 2;
    }

    for(int i=0; i<n; i++){
        sum += min( get<1>(v[i]),get<2>(v[i]));
    }

    cout<<sum<<endl;
    return 0;
}
