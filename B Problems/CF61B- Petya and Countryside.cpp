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

    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    int maxn = 1;
    int l,r;
    for(int i=0;i<n;i++){
        int cnt = 1;
        int pos = v[i];
        if(i==0){
            l = 1001;
            r = v[i+1];
        }else if(i == n-1){
            r=1001;
            l = v[i-1];
        }else{
            l = v[i-1];
            r = v[i+1];
        }
        if(l <= pos){
            for(int j=i; j>0 ; j--){
                if(v[j] >= v[j-1]){
                    cnt++;
                }else{
                    break;
                }
            }
        }
        if(r<=pos){
            for(int j=i; j<n-1; j++){
                if(v[j] >= v[j+1]){
                    cnt++;
                }else{
                    break;
                }
            }
        }
        maxn = max(maxn,cnt);
    }

    cout<<maxn<<endl;



    return 0;
}
