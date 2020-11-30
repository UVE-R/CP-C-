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
#define N 101
using namespace std;
vector<vector<int>> adj;
static bool vis[N];
static vector<int> init;

//Topological sort
void tsort(int a){
    vis[a]=true;
    
    for (int i=0;i<(int)adj[a].size();i++){
        int c = adj[a][i];
        if(!vis[c]){
            tsort(c);
        }
    }
    //Stores last most task
    init.push_back(a);
    
}

int main()
{
    int n,m;
    while(true){
        cin>>n>>m;
        //Stop if n and m is 0
        if(!n && !m){
            break;
        }     

        //Clearing structures
        adj.clear();
        init.clear();
        memset(vis,0,sizeof(vis));
        adj.resize(n+1);
        
        //Reading input and storing
        int a,b;
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
        }
    
        //Run Topological sort
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                tsort(i);
            }
        }
    
        //Print reverse order of init
        for(int i=n-1;i>=0;--i){
            if(!i){
                cout<<init[i]<<endl;
            }else{
                cout<<init[i]<<" ";
            }
            
        }
    }
    
    return 0;
}
