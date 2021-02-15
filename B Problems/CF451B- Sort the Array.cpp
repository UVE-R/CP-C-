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
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    int in1=0,in2=0;
    bool dec = false;

    for(int i=0;i<n-1;i++){
        if(dec && v[i] < v[i+1]){
            in2 = i;
            dec = false;
        }else if(v[i] > v[i+1] && !dec){
            dec = true;
            in1 = i;
        }
    }

    if(dec && in2==0){
        in2 = n-1;
    }

    if(!in1 && !in2){
        cout<<"yes"<<endl;
        cout<<"1 1"<<endl;
    }else{
        reverse(v.begin() + in1, v.begin() + in2 + 1);

        if(is_sorted(v.begin(), v.end())){
            cout<<"yes"<<endl;
            cout<<in1+1<<" "<<in2+1;
        }else{
            cout<<"no"<<endl;
        }
    }

    return 0;
}
