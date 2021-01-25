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

int calc(int n,int k){
    int s = 0;
    int cnt = 1;
    while(cnt <= n){
        s += cnt * 5;
        cnt++;
    }
    return s;
}


int bs(int n, int k){
    int l = 0;
    int r = n;
    while(l <=r){
        int mid = l + (r-l)/2;
        int sum = calc(mid, k);

        if(sum == k){
            return mid;
        }else if(sum > k){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return l-1;
}


int main()
{
    InTheNameOfGod
    int n,k;
    cin>>n>>k;
    k = 240 - k;

    if(k==0){
        cout<<0<<endl;
    }else{
        cout<<bs(n,k)<<endl;
    }

    return 0;
}
