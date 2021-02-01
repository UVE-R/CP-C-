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

ll NcR(int n, int r)
{
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    while (r) {
        p *= n;
        k *= r;
        
        long long m = __gcd(p, k);
        p /= m;
        k /= m;
        
        n--;
        r--;
    }
    return p;
}

int main()
{
    InTheNameOfGod
    int n,m;

    while(cin>>n>>m){
        if(n==0 && m==0){
            return 0;
        }
        if(n==m){
            cout<<n<<" things taken "<<m<<" at a time is 1 exactly."<<endl;
        }else{
            cout<<n<<" things taken "<<m<<" at a time is "<<NcR(n,m)<<" exactly."<<endl;
        }
    }

    return 0;
}
