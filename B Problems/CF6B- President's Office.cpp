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


int main()
{
    InTheNameOfGod
    int n,m;
    char c;
    cin>>n>>m>>c;

    char v [n][m];
    vector<int>pos;

    for(int i=0;i<n; i++){
        for(int j=0; j<m; j++){
            char a;
            cin>>a;
            if(a == c){
                pos.push_back(i);
                pos.push_back(j);
            }
            v[i][j] = a;
        }
    }

    set <char>s;
    int x,y;

    while(SZ(pos) != 0){
        y= pos[0];
        x= pos[1];
        pos.erase(pos.begin(), pos.begin()+2);

        if(y-1 >=0){
            if(v[y-1][x] != '.' && v[y-1][x] != c){
                s.insert(v[y-1][x]);
            }
        }

        if(y+1 <= n-1){
            if(v[y+1][x] != '.' && v[y+1][x] != c){
                s.insert(v[y+1][x]);
            }
        }

        if(x-1>= 0){
            if(v[y][x-1] != '.' && v[y][x-1] != c){
                s.insert(v[y][x-1]);
            }
        }

        if(x+1 <= m-1){
            if(v[y][x+1] != '.' && v[y][x+1] != c){
                s.insert(v[y][x+1]);
            }
        }
    }

    cout<<SZ(s)<<endl;

    return 0;
}
