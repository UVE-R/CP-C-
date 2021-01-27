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

    int n,a;

    cin>>n>>a;
    vector<int>v;
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        v.push_back(b);
    }

    a--;

    int cnt = 0;
    bool l,r;

    if(v[a] == 1){
        cnt++;
    }

    for(int i=1;i<n;i++){
        if(a-i<0 && a+i >n-1){
            l = false;
            r = false;
        }else if (a+i >n-1){
            r = false;
            l = true;
        }else if ( a-i<0){
            l = false;
            r = true;
        }else{
            l = true;
            r = true;
        }

        if(l && r){
            if(v[a-i] == 1 && v[a+i] == 1){
                cnt+=2;
            }
        }else if(l){
            if(v[a-i] == 1){
                cnt++;
            }
        }else if(r){
            if(v[a+i] == 1){
                cnt++;
            }
        }

    }

    cout<<cnt<<endl;

    return 0;
}
