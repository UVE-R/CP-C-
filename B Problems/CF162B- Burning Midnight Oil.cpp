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
int N;

ll sum(ll mid , int k){
    ll sum = 0;
    ll b = 1;
    while(mid/b){
        sum += mid /b;
        b *= k;
    }
    return sum;
}

ll bs(ll n, int k){
    ll st = 1, en = n;

    while( st<=en){
        ll mid = (st + en) /2;
        ll s = sum(mid,k);

        if(s==n){
            return mid;
        }

        if(s>n){
            en = mid -1;
        }else{
            st = mid + 1;
        }

    }

    return st;


}


int main()
{
    InTheNameOfGod

    ll n;
    int k;
    cin>>n>>k;

    cout<<bs(n,k)<<endl;

    return 0;
}



