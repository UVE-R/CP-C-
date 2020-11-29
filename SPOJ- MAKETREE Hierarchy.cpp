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
#define N 111
using namespace std;

int n, k, w, pos, a;
vector<vector<int>> adj;
static bool vis[100074];
vector<int> init;
int p[100074];

void tsort(int s){
    vis[s]=true;
    //iterate on every node connected to s to find lowest node
    for(int i=0; i< (int) adj[s].size();i++){
        int c = adj[s][i];
        if(!vis[c]){
            tsort(c);
        }
    }
    
    //Add lowest node to init
    init.push_back(s);
}

int main()
{
    //Reading input
    int n,k;
    scanf("%d %d",&n,&k);
    adj.resize(n+1);
    for (int i = 1; i<=k ; i++){
        scanf("%d",&w);
        for(int j=0;j<w;j++){
            scanf("%d",&a);
            adj[i].push_back(a);
        }

    }

    //topological sort into init
    for(int i=1; i<=n;i++){
        if(!vis[i]){
            tsort(i);
        }
    }
    
    //init now stores the reverse topological sort(last item upwards)
    
    //Used to get correct output from init
    //E.g. if 4 is the boss of 1 then the first value outputted is 1
    //And then if 3 is the boss of 2 then the second value outputted is 3
    pos = 0;
    for(int i=n-1; i>=0; i--){
        //Starts at boss(which would be at index[n-1] in init) then works down
        int n = init[i];
        //Sets each node to previous node
        p[n] = pos;
        //Stores current node for next iteration
        pos = n;
    }

    for(int i=1;i<=n;i++){
        printf("%d\n", p[i]);
    }

    return 0;
}
