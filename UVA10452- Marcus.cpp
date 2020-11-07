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
#define M 500
#define N 9
using namespace std;
static char path[M][N];
static bool visited[M][N];
vector<char> moves = {'I','E','H','O','V','A','#'};
//static vector<string> directions(M);
static char temp[M];
int n;
int m;
//Up, right, left
static int dr[]={-1,0,0};
static int dc[]={0,1,-1};
//Y is row and x is column
void DFS(int y, int x){
    visited[y][x]=true;
    for (int o=0;o<3;o++){
            if(y + dr[o] >=0 && x+dc[o] >=0 && x+dc[o] < n){
                int ny = y + dr[o];
                int nx = x + dc[o];
                if(!visited[ny][nx] && path[ny][nx]==moves[0]){
                    if(o==0){
                        cout<<"forth";
                    }else if(o==1){
                        cout<<"right";
                    }else{
                        cout<<"left";
                    }
                    moves.erase(moves.begin());
                    if(moves.size()>0){
                        cout<<" ";
                    }
                    DFS(y + dr[o],x + dc[o]);
                }else{
                    continue;
                }
            }
        }
}

int main()
{
    int a;
    cin>>a;
    for (int i=0;i<a;i++){
        while(cin>>m>>n){ //m is the length, n is the width
            getchar();
            for (int j=0;j<m;j++){
                    scanf("%s",temp);
                    for(int k=0;k<n;k++){
                        path[j][k] = temp[k];
                        visited[j][k]=false;
                    }
            }
            for (int l=0;l<m;l++){
                for(int p=0;p<n;p++){
                    if (path[l][p]=='@'){
                        DFS(l,p);
                    }
                }
            }
            cout<<"\n";
            moves.insert(moves.end(),{'I','E','H','O','V','A','#'});
        }
    }
    return 0;
}
