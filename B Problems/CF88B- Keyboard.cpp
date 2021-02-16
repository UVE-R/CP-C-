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


    int n,m,x;
    cin>>n>>m>>x;

    bool pres = false;
    vector<tuple<int,int>> shift;
    vector<vector<char>> key; //Row column of "S" keys
    vector<char>vv;
    for(int i=0;i < n; i++){
        for(int j=0; j<m; j++){
            char a;
            cin>>a;
            if( a == 'S'){
                shift.push_back(make_tuple(i,j));
                a = '.';
                pres = true;
            }
            vv.push_back(a);
        }
        key.push_back(vv);
        vv.clear();
    }
    int q,cnt = 0;
    string s;
    cin>>q>>s;


    shift.push_back(make_tuple(333,333));
    vector<tuple<char,ll>>v;
    x = x*x;
    ll x1,y1;
    ll dist;

    vector<char>good;
    vector<char>bad;
    for(int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            for(int k=0; k<SZ(shift); k++){
                x1 = abs( get<0>(shift[k]) - i);
                y1 = abs( get<1>(shift[k]) - j);
                dist = min(x1*x1 + y1*y1, dist);
            }
            if(dist > x){
                bad.push_back(key[i][j]);
            }else{
                good.push_back(key[i][j]);
            }
            dist = 33333333;
        }
    }

    for(int i=0; i< q; i++){
        if(find(good.begin(), good.end(), tolower(s[i]))== good.end() && find(bad.begin(), bad.end(), tolower(s[i]))== bad.end()){
            cout<<-1<<endl;
            return 0;
        }
        if( isupper(s[i])){
            if( !(find(good.begin(), good.end(), tolower(s[i])) != good.end() )){
                cnt++;
            }

            if(!pres){
                cout<<-1<<endl;
                return 0;
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}
