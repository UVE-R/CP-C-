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

    int n,x;

    cin>>n>>x;

    bool yes = true;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;

        vector<int>v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(7-a);
        v.push_back(7-b);
        v.push_back(x);
        x = 7-x;
        v.push_back(x);
        
        for(int j=1;j<7;j++){
            int cnt = 0;
            for(int m=0;m<7;m++){
                if(v[m] == j){
                    cnt++;
                }
            }
            
            if(cnt !=1 && cnt>0){
                yes = false;
            }

        }
    }

    if(yes){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}



