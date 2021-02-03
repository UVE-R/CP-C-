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
    int n;
    cin>>n;
    vector<char> v1;
    vector<char>v2;
    vector<int>v3;

    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;

        for(int j=0;j < a.length();j++){
            v1.push_back(a[j]);
        }

        for(int j=0;j < b.length();j++){
            v2.push_back(b[j]);
        }

        int j = max(a.length(),b.length());

        int curra, currb, carry = 0, sum;

        for(int k=0; k<j; k++){
            if(k >= a.length()){
                curra = 0;
                currb = v2[k] - '0';
            }else if(k >= b.length()){
                currb = 0;
                curra = v1[k] - '0';
            }else{
                curra = v1[k] - '0';
                currb = v2[k] - '0';
            }
            
            sum = curra + currb + carry;
            carry = 0;
            if( sum >=10){
                sum = sum % 10;
                carry = 1;
            }

            v3.push_back(sum);

        }
        
        
        if(carry == 1){
            v3.push_back(1);
        }
        

        while(true){
            if(v3[0] != 0){
                break;
            }
            v3.erase(v3.begin());
        }

        for(int k=0; k<SZ(v3); k++){
            cout<<v3[k];
        }
        cout<<endl;
        v1.clear();
        v2.clear();
        v3.clear();

    }



    return 0;
}
