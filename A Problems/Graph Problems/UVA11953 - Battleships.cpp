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
#define M 101
using namespace std;
int n;
char graph[100][100];
bool visited[100][100];

static int x[] = {1,-1,0,0};
static int y[] = {0,0,1,-1};

void dfs(int i,int j ){
    if( i<0 || j<0 || i==n || j==n){
        return;
    }

    if(graph[i][j]=='.' || visited[i][j]){
        return;
    }

    visited[i][j]=1;

    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);

}

int main()
{
    int t,ship;
    scanf("%d",&t);

    for(int T=1; T<=t ; T++){
        ship = 0;
        memset(visited,0,sizeof visited);
        scanf("%d",&n);

        for (int i=0;i<n;i++){
            scanf("\n");
            for(int j=0;j<n;j++){
                scanf("%c",&graph[i][j]);
            }
        }

        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && graph[i][j]=='x'){
                    ship++;
                    dfs(i,j);
                }
            }


        }
        cout<<"Case "<<T<<": "<<ship<<endl;


    }

    return 0;
}
