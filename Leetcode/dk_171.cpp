class Solution {
public:
    long long int power(int n, int m){
        long long int pro = 1;
        for(int i =1; i<=m;i++)
            pro*=n;
        return pro;
    }
    int titleToNumber(string s) {
        int len = s.length();
        if(len==1)
            return s[0]-'A'+1;
        int pro=0;
        int k=0;
        for(int i=len-1;i>=0;i--,k++){
            int num = s[i]-'A'+1;
            pro+= num*power(26,k);
        }
        return pro;
    }
};