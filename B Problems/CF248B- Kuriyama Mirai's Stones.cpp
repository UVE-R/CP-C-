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


ll sum_range(int l, int r, vector<ll> &S){
    if(l==0){
        return S[r];
    }

    return S[r] - S[l-1];
}

int main()
{
    InTheNameOfGod

    vector <int> v;
    v.push_back(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    vector <ll> v1;
    vector <ll> v2;
    v1.push_back(0);
    v2.push_back(0);

    for(int i=1; i<= n; i++){
        v1.push_back(v[i] + v1[i-1]);
    }

    sort(v.begin(), v.end());
    for(int i=1; i<= n; i++){
        v2.push_back(v[i] + v2[i-1]);
    }

    int m;
    cin>>m;
    int t,l,r;
    for(int i=0; i<m; i++){
        cin>>t>>l>>r;

        if(t==2){
            cout<<sum_range(l,r, v2)<<endl;
        }else{
            cout<<sum_range(l,r, v1)<<endl;
        }
    }

    return 0;
}
