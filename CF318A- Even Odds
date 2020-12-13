#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <math.h>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <stack>

using namespace std;


int main()
{
    long long n,k,x;
    long long m;
    cin>>n>>k;
    if(int(n)%2){
        m = ceil(n/2)+1;
    }else{
        m=n/2;
    }
    x = m-k;
    if(x>0){
        cout<<(2*(m-abs(x)))-1;
    }else if (x<0){
        cout<<abs(2*x);
    }else{
        cout<<(2*m)-1;
    }
    return 0;
}
