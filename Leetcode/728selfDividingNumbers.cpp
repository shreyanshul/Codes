class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for( int i=left; i<=right; i++){
            int num = i;
            int flag=1;
            for(;num>0;num/=10){
                if((num%10)==0){
                    flag=0;
                    break;
                }
                if(i%(num%10)!=0){
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                ans.push_back(i);
        }
        return ans;
    }
};