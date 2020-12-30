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
 
    int a;
    cin>>a;
 
    for(int i=0;i<a;i++){
        long b;
        cin>>b;
        set <int>set;
        vector<int>v;
        for(int j=0;j<b;j++){
            int c;
            cin >>c;
            set.insert(c);
            v.push_back(c);
        }
        
        int d = v[0];
        
        
        int last = 0;
        if (b==1){
            cout<<1<<endl;
        }else{
            for(int j=1;j<b;j++){
                //cout<<" Checking: "<<v[j]<< " End is: "<<last;
                if(d==v[j]){
                    //cout<<v[j]+1<<" ";
                   set.insert(v[j]+1);
                   last = v[j]+1;
                }else{
                    if(v[j] == last){
                        set.insert(v[j]+1);
                        last = v[j]+1;
                    }
                    d=v[j];
                }
                
            }
            
            /*
            cout<<"Set is: ";
            for (auto it = set.begin(); it !=set.end(); ++it) {
                cout << *it<<" ";
            }
            */
            cout<<set.size()<<endl;
        }       
    }   
    return 0;
}
