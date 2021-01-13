# include <bits/stdc++.h>
using namespace std;

int main()
{
    InTheNameOfGod

    int a[5] = {1,2,3,4,5};
    
    //Number to find
    int x = 5;

    //upper and lower range
    int r = sizeof(a)/sizeof(a[0]) -1 ;
    int l = 0;

    while(r >= l){
        //Find midpoint
        int m = l+ (r-l)/2;
        //If midpoint is the target
        if(a[m] == x){
            cout<<m<<endl;
            return 0;
        //If the midpoint is greater than the target, we no longer need the top half of the array
        }else if (a[m]>x){
            r -=1;
        //If the midpoint is less than the target, we no longer need the bottom half of the array
        }else{
            l +=1;
        }
    }
    //If the target is not in the array
    cout<<"Not Found"<<endl;
    return 0;
}

