

// SPOJ - https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define vii vector <pii>
#define pb push_back
#define mp make_pair
#define light_dk ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i,a,b) for(int i = a; i<b;i++)
#define RFOR(i,a,b) for(int i = a; i>=b;i--)
vector<int> arr;
int c,n;
int func(int num){
	int cow=1;
	int pos=arr[0];
    for(int i=1;i<n;i++){
    	if(arr[i]-pos>=num){
    		pos=arr[i];
    		cow++;
    		if(cow==c)
    			return 1;
   		}
   	}
   	return 0;
}
int main()
{
    light_dk;
    int t,temp;
    cin>>t;
    while(t--){
    	cin>>n>>c;
    	for(int i=0;i<n;i++){
    		cin>>temp;
    		arr.push_back(temp);
    	}
    	sort(arr.begin(), arr.end());
    	int lo=0,hi=arr[n-1], maxi=-1;
    	while(lo<hi){
    		int mid=(lo+hi)/2;
    		if(func(mid)==1){
    			if(mid>maxi)
    				maxi=mid;
    			lo = mid+1;
 
    		}
    		else{
    			hi=mid;
    		}
 
    	}
    	cout<<maxi<<endl;
    	arr.clear();
    }
    return 0;
}
