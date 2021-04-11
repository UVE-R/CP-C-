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
 
    int t;
    cin>>t;
 
    lp(i,t){
        int n,k;
        cin>>n>>k;
 
        if( (n==1 && k!=0) || (n==2 && k!=0) || ( n%2 == 0 && (n/2) -1 <k ) || ( n%2 == 1 && floor(n/2.0) <k ) ){
            cout<<-1<<endl;
        }else{
            deque<int>v;
            for(int j=1;j<=n;j++){
                v.pb(j);
            }
 
            vector<int>ans;
            for(int j=0; j<k; j++){
                ans.pb(v.front());
                ans.pb(v.back());
 
                v.pop_front();
                v.pop_back();
            }
 
            for(auto &it:ans){
                cout<<it<<" ";
            }
 
            if( !(v.empty()) ){
                for(auto it:v){
                    cout<<it<<" ";
                }
            }
            cout<<endl;
        }
 
    }
 
 
    return 0;
}
