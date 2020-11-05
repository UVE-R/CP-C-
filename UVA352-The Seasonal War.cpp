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
#define M 26
using namespace std;


//Stores input
static int picture[M][M];
//Stores if vertex is visited
static bool visited[M][M];
//Store for input string of 1s and 0s
static char TEMP[M];
//Global store for dimensions of picture
int n;

// Check all 8 direction co-ordinates.
// N, NE, E, SE, S, SW, West, NW
//Effects the ROW
//Effects the COLUMN
static int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
static int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};


void DFS(int i,int j){
    //Set the vertex to visited so we do not count it in another traversal
    visited[i][j]=true;

    for (int k=0;k<8;++k){
        // Check if current element is not out of the boundary
        if(i + dr[k] >=0 && i + dr[k] < n  && j+dc[k] >=0 && j+dc[k] < n){
            //Move to next positions
            int nexti = i + dr[k];
            int nextj = j + dc[k];
            //Recur if the next cell is 1 and not visited
            if(!visited[nexti][nextj] && picture[nexti][nextj]){
                DFS(nexti,nextj);
            }
        }
    }
}

int main()
{
    //Stores image number
    int c=0;
    //Stores dimensions to n, and loops until no dimensions are input(so program is finished")
    while ( scanf("%d",&n)==1){

        getchar();

        for(int i=0;i<n;++i){
            //Reading input string
            scanf("%s",TEMP);

            for (int j=0;j<n;++j){
                //Store individual cell
                picture[i][j]=TEMP[j] - '0';
                //Set visited to false for DFS
                visited[i][j]=false;

            }
        }

        //Stores number of connected components
        int cn = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //If the cell is 1 and has not been visited then it is a new eagle
                if(!visited[i][j] && picture[i][j]){
                    cn++;
                    //Run DFS to mark all cells following on from that cell 1 as it only counts as 1 war eagle
                    DFS(i,j);
                }
            }
        }
        //Print in format with image number and connected components
        printf("Image number %d contains %d war eagles.\n",++c,cn);
    }

    return 0;
}
