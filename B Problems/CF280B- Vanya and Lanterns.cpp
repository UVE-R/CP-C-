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

vector<int> v;
int main()
{
    InTheNameOfGod

    int n,l;
    cin>>n>>l;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int maxd = 0;

    for(int i=0; i<n-1;i++){
        maxd = max(maxd, v[i+1] - v[i]);
    }

    int maxd2 = max(v[0], l-v[n-1]);

    if(maxd/2 >= maxd2){
        cout<<fixed<<setprecision(10)<<maxd/2.0<<endl;
    }else{
        cout<<fixed<<setprecision(10)<<maxd2<<".0000000000"<<endl;
    }

    return 0;
}
