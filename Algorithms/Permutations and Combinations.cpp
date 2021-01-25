#include <bits/stdc++.h>
using namespace std;

vector <int> permutation;
bool is_visited[4];
int r = 4;
int perm_cnt = 0;

vector<int> combination;
int comb_n = 20, comb_r=4, comb_cnt = 0;

void get_perm(int i=0){
    if(i == r){
        ++perm_cnt;
        return;
    }
    
    for(int j=0; j<r; j++){
        if(is_visited[j]){
            continue;
        }
        permutation.push_back(j);
        is_visited[j] = 1;
        get_perm(i+1);
        is_visited[j] = 0;
        permutation.pop_back();
    }
    
}

void get_comb(int i=0, int last_val = 0){
    if(i == comb_r){
        comb_cnt++;
        return;
    }
    
    for(int j=last_val+1 ; j<=comb_n ; j++){
        combination.push_back(j);
        get_comb(i+1,j);
        combination.pop_back();
    }
    
}

int main()
{
    //4P4
    get_perm();
    cout<<perm_cnt<<endl;
    
    //20C4
    get_comb();
    cout<<comb_cnt<<endl;
    
    return 0;
}
