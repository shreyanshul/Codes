// Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

// Make sure the combinations are sorted.

// To elaborate,

// Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
// Entries should be sorted within themselves.
// Example :

void comb(int start,vector<vector<int>> &ans, vector<int> &temp, int n, int k  )
{
    for(int i=start; i<=n;i++){
        temp.push_back(i);
        if(temp.size()==k)
            ans.push_back(temp);
        comb(i+1, ans, temp, n,k);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector< vector<int> > ans;
    vector<int> temp;
    comb(1, ans, temp, A, B);
    return ans;
}
