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

    int n,k;
    
    cin>>n>>k;

    //Store in vector 
    
    vector<string>v;
    
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        
        v.push_back(s);
    }
    
    int cnt = 0;
    
    for(int i=0;i<n;i++){
        int found = 0;
        //Find each number from 0 to k
        for(int j=0;j<=k;j++){
            //If the number is in the string
            if(v[i].find(to_string(j)) != -1){
                found++;
            }
            
            //If every number in the range is there then we have 1 good one
            //k+1 as you need to check if zero is there
            if(found == k+1){
                cnt++;
            }
            
        }
    }
    cout<<cnt<<endl;

    return 0;
}
