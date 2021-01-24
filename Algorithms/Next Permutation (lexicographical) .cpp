#include <bits/stdc++.h>

using namespace std;
int i,j;

bool next_permutation(vector<int> &v, int n){
    i = n -1;
    
    while( i>0 && v[i -1 ] >= v[i]){
        i --;
    }
    if(i <=0){
        return false;
    }
    
    j = n-1;
    
    while(v[j] <= v[i-1]){
        j--;
    }
    swap(v[j],v[i-1]);
    
    j = n-1;
    
    while(i<j){
        swap(v[i],v[j]);
        i++;
        j--;
    }
    return true;
}

int main()
{
    vector <int> v{1,2,3};
    
    do{
        for(auto &i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }while(next_permutation(v,3));
    

    return 0;
}
