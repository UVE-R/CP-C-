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

bool vis[N];
int adj[N][N], cross[N], colour[N];

void dfs(int s, int n, int c){
    //Stores the colour of each vertex from the index, e.g s[1] will be 0
    colour[s] = c;
    //Set to visited
    vis[s] = 1;

    for (int i=1;i<=n;i++){
        //Colour connected vertices opposite
        if(adj[s][i] && !vis[i]){
            dfs(i,n,!c);
        //If connected to vertex s but is already visited
        }else if(adj[s][i] && vis[i]){
            if(colour[s] == colour[i]){
                //Mark vertex to bench
                cross[i] = 1;
            }
        }

    }

}

int main()
{
	
    //Set all values to zero
	memset(colour, 0, sizeof(colour));
	memset(cross, 0, sizeof(cross));
	memset(vis, 0, sizeof(vis));
	memset(adj, 0, sizeof(adj));
	
	int n, m;
    //n is vertices, m is pairs
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>j>>k;
        //set adjacency matrix point to 1 for both vertices
        adj[j][k]=adj[k][j]=1;
    }

    //Start at 1 as vertices begin from 1 ( look at input )
    for(i=1;i<=n;i++){
        if(!vis[i]){
            //Run dfs
            dfs(i,n,0);
        }
    }

    int cnt = 0;

    //Count number of benches
    for(int i=1;i<=n;i++){
        if(cross[i]){
            cnt++;
        }
    }

    //Benches are counted twice due to pairing
    cnt /=2;

    //Check to see if number of players playing is odd
    //If it is then we need to remove another player
    if((n-cnt)%2){
        cnt++;
    }
    
    cout<<cnt;
    return 0;
}
