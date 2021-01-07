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

    double x1,y1,x2,y2,x3,y3,x4,y4;
    
    //The shared common point will be inputted twice, it can be either of the first 2 inputs and then either of the last 2 inputs
    //First we must find this common point then only use the 2 remaining points to calculate the vector between
    // The solution work by the fact that the length from the common point to the missing point is the sum of the vector between the common point and each of the two verticies
    //In essence, this is just vector addition, so if you need a diagram just search "vector addition" up
    //SCROLL DOWN FOR SHORTER WHILE LOOP
    
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4){
        if(x1==x3 && y1==y3){
            double a = x2 - x1;
            double b = y2 - y1;

            double c = x4 - x1;
            double d = y4 - y1;

            cout<<setprecision(3)<<fixed<<x1+a+c<<" "<<y1+b+d;
        }else if(x1==x4 && y1==y4){
            
            double a = x2 - x1;
            double b = y2 - y1;

            double c = x3 - x1;
            double d = y3 - y1;
            cout<<setprecision(3)<<fixed<<x1+a+c<<" "<<y1+b+d;
            
        }else if(x2==x3 && y2==y3){
            double a = x1 - x2;
            double b = y1 - y2;

            double c = x4 - x2;
            double d = y4 - y2;
            cout<<setprecision(3)<<fixed<<x2+a+c<<" "<<y2+b+d;
        }else{
            double a = x1 - x2;
            double b = y1 - y2;

            double c = x3 - x2;
            double d = y3 - y2;
            cout<<setprecision(3)<<fixed<<x2+a+c<<" "<<y2+b+d;
        }
        cout<<endl;
    
        
    }


    return 0;
}


/*
while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4){
        if(x1==x3 && y1==y3){            
            cout<<setprecision(3)<<fixed<<x2+x4-x1<<" "<<y2+y4-y1<<endl;            
        }else if(x1==x4 && y1==y4){            
            cout<<setprecision(3)<<fixed<<x2+x3-x1<<" "<<y2+y3-y1<<endl;            
        }else if(x2==x3 && y2==y3){
            cout<<setprecision(3)<<fixed<<x1+x4-x2<<" "<<y1+y4-y2<<endl;            
        }else{            
            cout<<setprecision(3)<<fixed<<x1+x3-x2<<" "<<y1+y3-y2<<endl;
        }
    }

*/



