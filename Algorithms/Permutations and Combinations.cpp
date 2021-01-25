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

/*
void permute(string str, string out)
{
    // When size of str becomes 0, out has a
    // permutation (length of out is n)
    if (str.size() == 0)
    {
        cout << out << endl;
        return;
    }
 
    // One be one move all characters at
    // the beginning of out (or result)
    for (int i = 0; i < str.size(); i++)
    {
        // Remove first character from str and
        // add it to out
        permute(str.substr(1), out + str[0]);
 
        // Rotate string in a way second character
        // moves to the beginning.
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}
 
// Driver code
int main()
{
    string str = "ABC";
    permute(str, "");
    return 0;
}
*/

/*
void permute(string str)
{
    // Sort the string in lexicographically
    // ascennding order
    sort(str.begin(), str.end());
 
    // Keep printing next permutation while there
    // is next permutation
    do {
       cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}
 
// Driver code
int main()
{
    string str = "CBA";
    permute(str);
    return 0;
}
*/

