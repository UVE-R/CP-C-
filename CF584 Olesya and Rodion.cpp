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
    long long a,b;
    cin>>a>>b;
    if (a==1 && b==10){
        cout<<-1;
    }else if (b==10){
        cout<<1;
        for (int j=0;j<a-1;j++){
            cout<<0;
        }
    }else{
       cout<<b;
       for (int j=0;j<a-1;j++){
            cout<<0;
        }
    }
    return 0;
}
