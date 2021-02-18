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

//Checks to see if there is any winning combination
bool win(string s){
    //Check if there is a 3 in a row
    bool rows = (s[0] != '.' && s[0]== s[1] && s[0] == s[2]) || (s[3] != '.' && s[3]== s[4] && s[3] == s[5]) ||(s[6] != '.' && s[6]== s[7] && s[6] == s[8]);
    //Check if there is a 3 in a column
    bool cols = (s[0] != '.' && s[0]== s[3] && s[0] == s[6]) || (s[1] != '.' && s[1]== s[4] && s[1] == s[7]) ||(s[2] != '.' && s[2]== s[5] && s[2] == s[8]);
    //Check if there is a 3 in a diagonal
    bool diag = (s[0] != '.' && s[0] == s[4] && s[0] == s[8]) || (s[2] != '.' && s[2]== s[4] && s[2] == s[6]);

    return (rows || cols) || diag;
}

string BFS(string b){

    //Starting board
    string st = ".........";

    //Queue holds board and which player
    queue<pair<string,bool>>q;
    q.push({st,1});
    string s = "no";


    //We are going to build the board from ground up, taking each players turn one by one
    //We will check if someone has won on the board, and if so then we dont want to update the board any more
    //We will check if the boards are equal and therefore valid as we have followed the rules of the game through the BFS
    //We dont want to update the board after a win as is the boards are not equal after, someone has won but then kept on playing which is invalid
    //If we exhaust all the moves on the board, and the boards are never equal then the rules have been broken
    while(sz(q)){
        string cur = q.front().first; //Current board
        bool curp = q.front().second; //Current player
        q.pop();

        //Checks if the current board is the same as the actual boards
        //In the case that someone has won, if they have kept playing then our output stays no
        //If someone has won and our boards are the same, then they stopped playing after a win and so output is yes
        //If no-one has won but the current boards are the same then the output is still yes
        if(cur == b){ 
            s = "yes";
            break;
        }


        //Checks if someone has won, if they have then we do not want to change the current board
        //This is so that the current board can be checked with the acutal board
        if(win(cur)){ 
            continue; 
        }


        lp(i,9){ //Go through every "box"
            if(cur[i] == '.'){ //If the box is empty
                cur[i] = (curp ? 'X' : 'O'); //Update the box with the current players move

                if(cur[i] == b[i]){ //If the new box is the same as the actual box from the input
                    q.push({cur, 1^curp}); //Add the new box to the stack and change turn (1^0 = 1, 1^1 = 0)
                }
                cur[i] = '.'; //Revert change if it was not the same
            }
        }
    }
    return s;
}

int main()
{
    InTheNameOfGod

    int n;
    cin>>n;
    lp(i,n){
        string board = "";
        lp(j,3){
            string a;
            cin>>a;
            board += a;
        }
        cout<<BFS(board)<<endl;
    }

    return 0;
}
