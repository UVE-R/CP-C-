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

//Sum from 1 to n
ll sum( ll n){
    return (n * (n+1) /2);
}

//Sum from s to e
ll sum ( ll s, ll e){
    if( s<=1){
        return sum(e);
    }
    return sum(e) - sum(s-1);
}

ll minSplitters (ll k, ll n){
    ll st = 1, en = k;

    while(st < en){
        ll mid = (st+en) / 2;
        ll s = sum(mid,k);

        //if the sum of the subarry is n then
        if(s == n){
           return k - mid +1;
        }

        if(s >n){
            st = mid+1;
        }else{
            en = mid;
        }

    }

    return k - st+2;

}

int main()
{
    InTheNameOfGod

    ll n,k;

    cin>>n>>k;

    if(n==1){ //Dont need to add splitter
        cout<<0<<endl;
    }else if( n <=k){ //Only 1 splitter as there will always be a splitter in this case
        cout<<1<<endl;
    }else{
        --k;
        --n;

        if(sum(k) < n){ //if the sum of the splitters is less than n then it cant be made
            cout<<-1<<endl;
        }else{
            cout<< minSplitters(k,n)<<endl;
        }
    }




    return 0;
}



