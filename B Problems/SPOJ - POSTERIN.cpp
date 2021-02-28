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
const int maxim = 1e9;

/*
The cases are : ~if there is an increase in height then a new poster is created on top of the continued poster
                ~if there is a decrease in height:
                    ~Find the first poster with a height less than or equal to the current height
                        ~if it is of the same height then we can continue on from that poster
                        ~if it is of less height then we need to add a poster on top of that continued poster
*/

int main()
{
    InTheNameOfGod

    int n,cnt = 0;
    cin>>n;
    vector<int> v;

    stack<int>s;

    lp(i,n){
        int l,h;
        cin>>l>>h;
        v.pb(h);

		//Add item to stack if it is empty and create new poster
		if (s.empty()) {
			cnt++;
			s.push(v[i]);
		} else {
		    //If the next height is less than the previous
		    //Find the first previous building with a height equal to or less than the current height
			while (s.top() > v[i]) {
				s.pop();
				//If there are no previous buildings with a height less than or equal to the current
				//Then we can stop continuing all previous posters as it it not possible to extend them
				if (s.empty())
					break;
			}

			//If there are no items in the stack then add the current one and create a new poster
			if (s.empty()) {
				cnt++;
				s.push(v[i]);
			} else {
			    //If there exists a building with the same height then we continue that poster
				if (s.top() == v[i]){
					continue;
			    //If there is a building smaller than the current then we can continue that poster but have to add one on top
			    //Or if there is an increase in height then need to add a poster above
				}else {
					cnt++;
					s.push(v[i]);
				}
			}
		}
	}
	cout << cnt<<endl;
	return 0;
}

