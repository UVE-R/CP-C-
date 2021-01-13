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
int N;

int smaller(int arr[], int val, int l, int r){
    int ans = -1;

    while( l<= r){
        int mid = l+(r-l)/2;
        //If the value is greater than the target, then everything to the right of the value is too large
        if(arr[mid] >= val){
            r = mid -1;
        //If the value is less than the target, then everything to the left of the value is too small
        }else{
            ans = mid;
            l = mid +1;
        }

    }
    return ans;
}

int larger(int arr[], int val, int l, int r){
    int ans = -1;

    while( l<= r){
        int mid = l+(r-l)/2;
        if(arr[mid] <= val){
            l = mid +1;
        }else{
            ans = mid;
            r = mid -1;
        }

    }
    return ans;
}

int main()
{
    InTheNameOfGod

    //int N;
    cin>>N;
    int s[N];

    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        s[i] = a;
    }

    int q;
    cin>>q;
    int qu[q];

    for(int i=0;i<q;i++){
        int b;
        cin>>b;
        qu[i] = b;
    }

    int x = sizeof(s)/sizeof(s[0]);

    for(int i=0;i<q;i++){
        int val = qu[i];

        int small = smaller(s,val,0,x);

        if(small == -1){
            cout<<'X'<<" ";
        }else if(small >= x){
            cout<<s[x-1]<< " ";
        }else{
            cout<<s[small]<<" ";
        }

        //Could instead use upper_bound(s,s+x,val)
        int large = larger(s,val,0,x);

        if(large == -1 || large >=x){
            cout<<'X'<<endl;
        }else{
            cout<<s[large]<<endl;
        }

    }

    return 0;
}
