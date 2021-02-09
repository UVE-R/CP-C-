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

int sum_range(int S, int E, vector<int> & cumulative_sum){
    if (S==0){
        return cumulative_sum[E];
    }

    return cumulative_sum[E] - cumulative_sum[S-1];
}

int sum_range_2d(int i, int j, int k, int l, vector<vector<int>> &S){
    return S[k][l] - S[k][j-1] - S[i-1][l] + S[i+1][j-1];

}

int main()
{
    InTheNameOfGod

    vector<int>v{2,1,4,5,7,9};
    vector<int>S(SZ(v), 0);

    for(int i=0; i< SZ(v); i++){
        S[i] += (i==0)? v[i] : v[i] + S[i-1];
    }

    cout<<sum_range(0,5,S)<<endl;
    cout<<sum_range(2,3,S)<<endl;


    vector<vector<int>>V =
        { { 0, 0, 0, 0, 0, 0},
          { 0, 1, 2, 2, 4, 1},
          { 0, 3, 4, 1, 5, 2},
          { 0, 2, 3, 3, 2, 4},
          { 0, 4, 1, 5, 4, 6},
          { 0, 6, 3, 2, 1, 3}, };

    for(int i=1; i< SZ(V); i++){
        for(int j=1; j<SZ(V); j++){
            V[i][j] += V[i][j-1];
        }
    }

    for(int j=1; j< SZ(V); j++){
        for(int i=1; i<SZ(V); i++){
            V[i][j] += V[i-1][j];
        }
    }

    cout<<sum_range_2d(2, 3, 3, 5, V)<<endl;



    return 0;
}
