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

int t,n,c;
int a[100025];

int main()
{
    InTheNameOfGod

    cin>>t;

    while(t--){
        cin>>n>>c;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort(a,a+n);

        int low = 0, high = a[n-1], mid, best = 0;

        while(low <=high){
            mid = (low + high+1) /2;
            //cnt keeps track of how many cows have been placed
            //last keeps track of the last place we put a cow
            int cnt = 1, last = 0;

            //Try to place all the cows between first and last value
            //Mid will act as our gap which we are trying to minimize
            //If this gap is too large then it will not be able to fit all the cows
            for(int j = 1; j<n && cnt < c; j++){
                if(a[j] - a[last] >= mid){
                    last = j;
                    cnt++;
                }
            }
            
            //If we were able to place all the cows then this gap value worked
            //We can now try to find a larger gap value
            if( cnt >= c){
                best = mid;
                low = mid +1;
            }else{
                //If the gap value did not work then it will only work for gap values less than current gap
                high = mid -1;
            }
        }

        cout<<best<<endl;

    }
    return 0;
}
