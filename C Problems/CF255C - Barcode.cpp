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

int main(){

    int n,m,x,y;

    cin>>n>>m>>x>>y;

    int w[m]; //Stores number of white in each column
    int b[m]; //Stores number of black in each column
    memset(w,0,sizeof(w));
    memset(b,0,sizeof(b));

    lp(i,n){
        string s;
        cin>>s;

        lp(i,s.length()){
            if(s[i] == '.'){
                w[i] ++;
            }else if (s[i] == '#'){
                b[i] ++;
            }
        }

    }

    //Prefix sum of the number of whites in each column
    //Allows us to calculate the number of white in a certain range of columns
    int wsum[m+1];
    memset(wsum,0,sizeof(wsum));

    lpi(i,1,m+1){
        wsum[i] += w[i-1] + wsum[i-1];
    }

    //Repeat for black
    int bsum[m+1];
    memset(bsum,0,sizeof(bsum));

    lpi(i,1,m+1){
        bsum[i] += b[i-1] + bsum[i-1];
    }

    //dp[i][j] holds the minimal amount to be repainted in columns [1-j] and last colour is i
    //if i=1 then the colour is white, else if i=0 then the colour is black
    int dp[2][m+1];
    memset(dp,0,sizeof(dp));

    dp[0][0] = dp[1][0] = 0; //No repaints if there is no columns


    for(int j=1; j<=m;j++){
        int minw = OO, minb = OO; //Minimum re-paints for black or white
        
        for(int a=x; a<=y && j>=a;a++){
            //If we want to make the current column black, we must first make the ( current - a ) columns black
            //This means turning all the white pixels to black which is done by wsum[j] - wsum[j-a]
            //We also need the 1st to ath column to be white which is dp[1][j-a]
            //The same is done for white 
            minb = min(minb, dp[1][j-a] + wsum[j] - wsum[j-a]);  
            minw = min(minw, dp[0][j-a] + bsum[j] - bsum[j-a]);
        }

        dp[0][j] = minb;
        dp[1][j] = minw;
    }

    cout<<min(dp[0][m], dp[1][m])<<endl;

    return 0;
}
