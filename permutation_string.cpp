// Given a collection of numbers, return all possible permutations.

// Example:

// [1,2,3] will have the following permutations:

// [1,2,3]
// [1,3,2]
// [2,1,3] 
// [2,3,1] 
// [3,1,2] 
// [3,2,1]
// NOTE

// No two entries in the permutation sequence should be the same.
// For the purpose of this problem, assume that all the numbers in the collection are unique.

void perm(vector<int> &temp, vector<vector<int>> &ans, vector<int> &A, vector<int> &flag)
{
    if( temp.size() == A.size())
        ans.push_back(temp);
    for(int i=0;i<A.size(); i++){
        if(flag[i]==-1){
            flag[i]=1;
            temp.push_back(A[i]);
            perm(temp, ans,A, flag);
            temp.pop_back();
            flag[i]=-1;
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> flag(A.size(), -1);
    vector<int> temp;
    perm(temp, ans, A,flag);
    return ans;
}
