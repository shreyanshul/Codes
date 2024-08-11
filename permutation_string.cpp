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
