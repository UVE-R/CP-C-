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

        int x1,y1,x2,y2;

        cin>>x1>>y1;
        cin>>x2>>y2;

        int x3,y3,x4,y4;

        cin>>x3>>y3;
        cin>>x4>>y4;

        //Check if the left side of one rectangle is past the right side of the other => meaning they will never overlap as the boxes will be completely seperate
        //Repeat this for when one rectange is totally to the left, then above then below
        
        if (!((x1 >= x4 || x3 >= x2) || (y2 <= y3 || y1 >= y4))){
            cout<<max(x1,x3)<<" "<<max(y1,y3)<<" "<< min(x2,x4)<<" "<<min(y2,y4)<<endl;
        }else{
            cout<<"No Overlap"<<endl;
        }        
        
        if(i==a-1){
            break;
        }
        cout<<"\n";

    }


    return 0;
}
