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
# define kill(x)                                         return cout << x << endl, 0
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define pb					                             push_back
# define MP					                             make_pair
# define P(x)				                             cout<<#x<<" = { "<<x<<" }\n"
# define all(v)				                             ((v).begin()), ((v).end())
# define sz(v)				                             ((int)((v).size()))
# define clr(v, d)			                             memset(v, d, sizeof(v))
# define rep(i, v)		                                 for(int i=0;i<sz(v);++i)
# define lp(i, n)		                                 for(int i=0;i<(int)(n);++i)
# define lpi(i, j, n)	                                 for(int i=(j);i<(int)(n);++i)
# define lpd(i, j, n)	                                 for(int i=(j);i>=(int)(n);--i)
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
const int OO = (int)1e6;
const int maxim = 1e9;

int maxK;

ll mem[21][101];

ll maxProd(int k, int rem){
    //Base case
    if(k == maxK){
        if(rem == 0){
          return 1;
        }
        return 0;
    }

    //Invalid Case
    if(rem == 0){
        return 0;
    }

    ll &ret = mem[k][rem];

    if(ret != -1){
        return ret;
    }

    ret = 0;

    lpi(i,1,rem +1){
        ll sol = maxProd(k+1, rem - i) * i;
        ret = max(ret, sol);
    }

    return ret;

}

class MaximalProduct{
public:
    long long maximalProduct(int s, int k){ //K integers so that their sum is S, and their product is a maximum
        maxK = k;
        clr(mem, -1);
        return maxProd(0,s);
    }
};

int main(){

    MaximalProduct s;

    cout<<s.maximalProduct(10,1)<<endl;

    return 0;
}
