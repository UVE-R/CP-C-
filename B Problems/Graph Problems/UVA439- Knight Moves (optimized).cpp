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

int diry[8] = {2,2,1,1,-2,-2,-1,-1};
int dirx[8] = {1,-1,2,-2,1,-1,2,-2};

bool checkmove(int x, int y){
    if( x>=0 && x<8 && y>=0 && y<8){
        return true;
    }
    return false;
}

int moves(int x1, int y1, int x2, int y2){
    queue<pair<int,int>>q;
    int len[8][8];
    memset(len,0,sizeof(len));

    q.push(MP( x1, y1));
    len[y1][x1] = 0;

    int curx = x1, cury = y1;

    while(!q.empty()){
        pair<int,int> p = q.front();
        curx = p.first;
        cury = p.second;
        q.pop();

        if(curx == x2 && cury==y2){
            return(len[cury][curx]);
        }

        lp(i,8){
            if(checkmove(curx+dirx[i], cury+diry[i])){
                if(len[cury+diry[i]][curx+dirx[i]] == 0){
                    q.push(MP(curx+dirx[i], cury+diry[i]));
                    len[cury+diry[i]][curx+dirx[i]] = len[cury][curx] + 1;
                }
            }
        }

    }
}

int main()
{
    InTheNameOfGod
    string a,b;
    while(cin>>a>>b){
        if(a == b){
            cout<<"To get from "<<a<<" to "<<b<<" takes 0 knight moves."<<endl;
        }else{
            int moveN = moves((int)a[0] - 'a',(int)a[1] - '1', (int)b[0] - 'a', (int)b[1] - '1');
            cout<<"To get from "<<a<<" to "<<b<<" takes "<< moveN <<" knight moves."<<endl;
        }
    }
    return 0;
}
