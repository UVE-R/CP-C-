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

//Works by the principle a^b = (a ^ b/2)^2
//Recursively finds a ^ b/2 until the power is 0
long long powerRecursive(long long a, long long b){
    if(b==0){
        return 1;
    }
    long long tmp = powerRecursive(a,b/2);
    int result = tmp * tmp;
    if(b%2==1){
        result *=a;
    }
    return result;
}

//Uses binary representations  of the exponent to calculate power
//e.g. 3^13 = 3 ^ 1101(base2) = 3^8 x 3^4 x 3^1
//It will calculate the powers for 1,2,4,8,16...
//Then if a bit is set (i.e. in its binary representations it is a 1)
//It will multiply the result by the current power
long long powerIterative(long long a, long long b){
    int result = 1;
    while(b >0){
        if(b&1){ //If bit is set
            result *=a;
        }
        a *= a; //Computes a^1, a^2, a^4, a^8 ...
        b >>=1; //Right shift to remove the bit we evaluated
    }
    return result;

}

int main()
{
    InTheNameOfGod
    cout<<powerRecursive(2,10)<<endl;
    cout<<powerIterative(2,10)<<endl;

    return 0;
}
