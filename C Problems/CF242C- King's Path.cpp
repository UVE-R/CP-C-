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

int dirx[8] = {0,0,1,-1,1,1,-1,-1};
int diry[8] = {1,-1,0,0,1,-1,1,-1};

set<pair<int,int>>board;

int bfs(int x1, int y1, int x2, int y2){
    map<pair<int,int>,int>len;
    queue<pair<int,int>>q;
    q.push(MP(x1,y1));
    len[(MP(x1,y1))] = 0;

    pair<int,int>cur;
    int dep = 0, sz=1;

    for(; !q.empty(); ++dep, sz = q.size()){
        while(sz--){
            cur = q.front();
            q.pop();

            lp(i,8){
                pair<int,int> p = {cur.first + dirx[i], cur.second + diry[i]};

                if(board.count(p)==0 || len.count(p) !=0){
                    continue;
                }

                q.push(p);
                len[p] = dep + 1;

                if(p.first == x2 && p.second == y2){
                    return dep +1;
                }
            }
        }
    }
    return -1;


}



int main()
{
    InTheNameOfGod

    ll x1,y1,x2,y2,n;
    cin>>x1>>y1>>x2>>y2>>n;


    lp(i,n){
        int r,a,b;
        cin>>r>>a>>b;

        //Create path for traversal
        lpi(j,a,b+1){
            board.insert({r,j});
        }
    }

    cout<<bfs(x1,y1,x2,y2)<<endl;


    return 0;
}
