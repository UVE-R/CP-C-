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

const long long MOD = 1e9 + 7;


long long dp[1000006]; //Stores the number of good sequences for the sequence a1, a2, a3, ... , aj
int a [100005];

int main(){

    int n;
    cin>>n;

    for(int i=1; i<=n ;i++){
        int b;
        cin>>b;
        a[i] = b;
    }

    dp[0] = 1; //Only 1 way to form a sub-sequence with zero values

    for(int i=1; i<=n; i++){
        vector<int> div; //Stores the divisors of a[i] which corresponds to the index where it can be placed (one based)
        for(int j=1; j<= sqrt(a[i]) ; j++){ //Fast Divisor
            if(a[i] % j==0){
                div.pb(j);

                if(j != sqrt(a[i])){ //Avoids having 2 of the same divisor which leads to over counting
                    div.pb(a[i] / j);
                }

            }
        }

        sort(div.begin(), div.end()); //Sort to avoid over counting as the loop needs to be done in descending order

        //For each divisor index, the number of good sequences up to j is the number of good sequences which include j
        //As j is just appended onto the end of the sequence without j, the number of good sequences for j-1 is unchanged when j is added
        //This is why dp[j] = dp[j-1] where J IS A DIVISOR
        
        for(int j = div.size() -1; j>=0; j--){ //Carry out descendingly
            dp[div[j]] = (dp[div[j]] + dp[div[j]-1]) % MOD; 
        }
    }

    ll ans = 0;

    //Need to add all the ways for each subsequence 
    for(int i=1; i<=n; i++){
        ans = (ans + dp[i]) % MOD;
    }

    cout<<ans<<endl;


    return 0;
}
