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

    vector<char>v;
    for(int i=0;i<4;i++){
        char a,b,c,d;
        cin>>a>>b>>c>>d;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);        
    }
    bool yes = false;
    for(int i=0;i<11;i++){
        int cnt = 0;
        if(i==3 || i==7){
            continue;
        }else{
            for(int j=0;j<2;j++){
                if(v[i+j] == '#'){
                    cnt++;
                }
                if(v[i+j+4] == '#'){
                    cnt++;
                }
            }
            if(cnt==4|| cnt ==3 || cnt == 0 || cnt == 1){
                yes = true;
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
