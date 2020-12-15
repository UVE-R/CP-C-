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
    int a;
    cin>>a;
    string s;
    //X stores diagonals
    //Y stores non-diagonals
    set<char>x,y;

    for(int i=0;i<a;i++){
        cin>>s;
        for(int j=0;j<a;j++){
            //Check if element is on either diagonal
            if(i==j || i+j==a-1){
                x.insert(s[j]);
            }else{
                y.insert(s[j]);
            }
        }
    }
    //Set will only store one character if the diagonals are the same
    //Same with non-diagonal set
    //Need to check if the diagonal letter is not the same as non-diagonal
    //For test case where everything is the same letter
    if(x.size() ==1 && y.size() ==1 && *x.begin() != *y.begin()){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}
