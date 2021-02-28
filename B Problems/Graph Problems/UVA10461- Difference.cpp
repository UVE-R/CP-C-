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

int total,n; //Total job times

//Finds the maximum time for the job
int maxT(int v, vector<int>c, vector<vector<int>> adj){
    int maxT = total;
    queue<int>q;
    vector<bool> vis(n, false);

    q.push(v);
    vis[v] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        maxT -= c[cur];

        lp(i, sz(adj[cur])){
            int next = adj[cur][i];
            if(!vis[next]){
                q.push(next);
                vis[next] = true;
            }
        }

    }
    cout<<"Max "<<maxT<<endl;
    return maxT;

}

//Finds the minimum time for the job
int minT(int v, vector<int>c, vector<vector<int>> adj){
    int minT = - c[v];

    queue<int>q;
    vector<bool> vis(n, false);

    q.push(v);
    vis[v] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        minT += c[cur];

        lp(i, sz(adj[cur])){
            int next = adj[cur][i];
            if(!vis[next]){
                cout<<next<<endl;
                q.push(next);
                vis[next] = true;
            }
        }

    }
    cout<<"Min "<<minT<<endl;
    return minT;

}

int main()
{
    InTheNameOfGod

    int e;

    int casen = 1;
    while(cin >>n >> e){
        if(n==0 && e==0){
            return 0;
        }

        vector<vector<int>> adjBef(n); //x -> y
        vector<vector<int>>adjAft(n); // y -> x
        vector<int>cost(n);
        total = 0;
        lp(i,n){
            int a;
            cin>>a;
            cost[i] = a;
            total += a;
        }


        lp(i,e){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            adjBef[x].push_back(y);
            adjAft[y].push_back(x);
        }

        int q;
        cin>>q;
        cout<<"Case #"<<casen<<":"<<endl;
        casen++;

        lp(i,q){
            int b;
            cin>>b;
            b--;
            cout<<maxT(b,cost,adjAft) - minT(b,cost,adjBef)<<endl;
        }
        cout<<endl;

    }
    return 0;
}
