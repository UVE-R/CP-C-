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

const int MAX = 1e5 + 1;

int n; //Number of trees

// dp[i][j] stores the maximum number of trees cut if the current tree has operation j onto it
//If j=0, then we do not cut the tree
//If j=1 then we cut the tree to the left
//If j=2 then we cut the tree to the right
int dp[MAX][3]; 

vector<int> c; //Coordinates
vector<int> h; //Height 

//0 is skip, 1 is cut left, 2 is cut right
int solve(int i, int last){
    //If we are at the last tree, then this can always be cut down to the right
    if(i==n-1){
        return 1;
    }
    
    int &ret = dp[i][last];

    //Check if a value for the maximum number of trees cut down exists
    if(ret != -1){
        return ret;
    }

    ret = 0;
    
    //If last was skipped or cut to the left then it does not matter which way the current tree is cut
    if(last == 0 || last == 1){ 
        ret = max(ret, solve(i+1,0)); //Choose not to cut

        if(c[i+1] - c[i] > h[i]){ //Check if we can cut to the right
           ret = max(ret, solve(i+1,2) +1); //Cut right
        }

        if(c[i] - c[i-1] > h[i]){ //Check if we can cut to the left
            ret = max(ret, solve(i+1,1) +1); //Cut left
        }

    }

    //If last was cut to the right then it does matter which way the current tree is cut
    if(last == 2){ 
        ret = max(ret, solve(i+1,0)); //Choose not to cut

        if(c[i+1] - c[i] > h[i]){
            ret = max(ret, solve(i+1,2) + 1); //Cut right if possible
        }

        //Check if there is enough space for the previous tree(which was cut right) and the current tree (which is to be cut left)
        if(c[i] - c[i-1] > h[i] + h[i-1]){ 
            ret = max(ret, solve(i+1,1) +1); //Cut left if possible
        }
    }

    return ret;
}

int main(){

    cin>>n;
    lp(i,n){
        int a,b;
        cin>>a>>b;
        c.pb(a);
        h.pb(b);
    }
    memset(dp,-1,sizeof(dp));
    
    if(n==1){ 
        //If there is only 1 tree then it can always be cut down
        cout<<1<<endl;
    }else{
        //Skip the case of the first tree as it can always be cut to the left, and so we add 1 to account for this
        cout<<solve(1,0)+1 <<endl;
    }

    return 0;
}
