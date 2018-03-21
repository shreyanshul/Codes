class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int> divi;
        for( int i=1; i<=sqrt(num); i++){
            if( num%i==0 ){
                if(num/i==i)
                    divi.push_back(i);
                else{
                    divi.push_back(i);
                    divi.push_back(num/i);
                }
            }    
        }
        if( num==0 or accumulate(divi.begin(), divi.end(),0) != 2*num)
            return false;
        else
            return true;
    }
};