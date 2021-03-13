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

const int MAX = 21;
int r[MAX];
int g[MAX];
int b[MAX];
int n;

int mem[MAX][4];

int minCost(int i, int lastColour){
    if(i == n){
        return 0;
    }

    int &ret = mem[i][lastColour];

    if(ret != -1){
        return ret;
    }

    ret = OO;

    if(lastColour != 0){
        ret = min(ret, r[i] + minCost(i+1, 0));
    }

    if(lastColour != 1){
        ret = min(ret, g[i] + minCost(i+1, 1));
    }

    if(lastColour != 2){
        ret = min(ret, b[i] + minCost(i+1, 2));
    }

    return ret;
}

class RGBStreet{
public:
    int estimateCost(vector<string> houses){
        rep(i, houses){
            istringstream iss(houses[i]);
            iss>>r[i]>>g[i]>>b[i];
        }
        clr(mem, -1);
        n = sz(houses);
        return minCost(0, 3);
    }

};

int main(){

    RGBStreet s;
    cout<<s.estimateCost(	{"30 19 5", "64 77 64", "15 19 97", "4 71 57", "90 86 84", "93 32 91"} )<<endl;

}
