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
# define kill(x)                                         return cout << x << endl, 0
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define pb					                             push_back
# define MP					                             make_pair
# define P(x)				                             cout<<#x<<" = { "<<x<<" }\n"
# define all(v)				                             ((v).begin()), ((v).end())
# define sz(v)				                             ((int)((v).size()))
# define clr(v, d)			                             memset(v, d, sizeof(v))
# define rep(i, v)		                                 for(int i=0;i<sz(v);++i)
# define lp(i, n)		                                 for(int i=0;i<(int)(n);++i)
# define lpi(i, j, n)	                                 for(int i=(j);i<(int)(n);++i)
# define lpd(i, j, n)	                                 for(int i=(j);i>=(int)(n);--i)
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
const int OO = (int)1e6;


//Same code as TOE1
bool win(string s){
    bool rows = (s[0] != '.' && s[0]== s[1] && s[0] == s[2]) || (s[3] != '.' && s[3]== s[4] && s[3] == s[5]) ||(s[6] != '.' && s[6]== s[7] && s[6] == s[8]);
    bool cols = (s[0] != '.' && s[0]== s[3] && s[0] == s[6]) || (s[1] != '.' && s[1]== s[4] && s[1] == s[7]) ||(s[2] != '.' && s[2]== s[5] && s[2] == s[8]);
    bool diag = (s[0] != '.' && s[0] == s[4] && s[0] == s[8]) || (s[2] != '.' && s[2]== s[4] && s[2] == s[6]);
    return (rows || cols) || diag;
}


string BFS(string b){
    string st = ".........";
    queue<pair<string,bool>>q;
    q.push({st,1});
    string s = "no";
    while(sz(q)){
        string cur = q.front().first;
        bool curp = q.front().second;
        q.pop();
        if(cur == b){
            s = "yes";
            break;
        }

        if(win(cur)){
            continue;
        }


        lp(i,9){
            if(cur[i] == '.'){
                cur[i] = (curp ? 'X' : 'O');
                if(cur[i] == b[i]){
                    q.push({cur, 1^curp});
                }
                cur[i] = '.';
            }
        }
    }


    //If it is not possible to create the board then it is invalid
    if(s == "no"){
       return "invalid";

    }else{
        //The only way a board is valid is that there is either a draw or one person has won
        //There is no way that 2 people have won as the code earlier checks that the board is valid
        //So we just need to count the number of X's and O's to see if there is a draw, or check if someone has won
        int cnto=0, cntx = 0;
        lp(i,9){
            if(b[i] == 'X'){
                cntx++;
            }else if(b[i] == 'O'){
                cnto++;
            }
        }

        if(cntx == 5 && cnto==4 && !(win(b)) ){ //If draw
            return "valid";
        }else if(win(b)){
            return "valid";
        }else{
            return "invalid";
        }

    }
}

int main()
{
    InTheNameOfGod

    string g;

    while(cin>>g){
        if(g=="end"){
            return 0;
        }
        string result = BFS(g);
        cout<<result<<endl;
    }


    return 0;
}
