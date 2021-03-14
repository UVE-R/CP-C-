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

#define MAX 101

int arr[MAX];
int dp[MAX][3];  //3 states of rest, gym, contest

int main(){

    int n;
    cin>>n;
    lp(i,n){
        int a;
        cin>>a;
        arr[i] = a;
    }

    //DP stores minimum days of rest if activity J is done before
    // J=1 is contest, J=2 is gym, J=3 is rest
    for(int i=1;i<=n;i++){
            dp[i][0]=min({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+1;

            dp[i][2]=dp[i][1]=OO;

            if(arr[i-1]&1){   //Contest
                dp[i][1]=min(dp[i-1][2],dp[i-1][0]); //Minimum of previous rest or gym
            }
            if(arr[i-1]&2){ //Gym
                dp[i][2]=min(dp[i-1][1],dp[i-1][0]); //Minimum of previous rest or contest

            }
    }

    int ans = OO;

    lp(i,3){
        ans = min(ans,dp[n][i]);
    }

    cout<<ans<<endl;

    return 0;
}
