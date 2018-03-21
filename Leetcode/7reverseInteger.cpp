class Solution {
public:
    int reverse(int x) {
        long long int num=x;
        string str = to_string(num);
        if( str[0]!='-' ){
            long long int rev = 0;
            while(num>0){
                rev = rev*10 + num%10;
                num/=10;
            }
            if( rev>INT_MAX)
                return 0;
            return rev;
        }
        else{
            string rev = str;
            int k=1;
            rev[0]='-';
            for(int i = str.length()-1; i>=1;i--,k++ )
                rev[k] = str[i];
            rev[str.length()] = '\0';
            long long int ans;
            stringstream geek(rev);
            geek >> ans;
            if( ans < INT_MIN)
                return 0;
            return ans;
        }
    }
};
/*
class Solution {
public:
    int reverse(int x) {
        long long int num=x,rev=0;
            while(num){
                rev = rev*10 + num%10;
                num/=10;
            }
            return rev > INT_MAX or rev < INT_MIN ? 0 : rev;
        }
};
*/