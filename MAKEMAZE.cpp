// SPOJ - https://www.spoj.com/problems/MAKEMAZE/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define vii vector <pii>
#define pb push_back
#define mp make_pair
int n,m,k,src_x,src_y;
char grid[50][50];
int vis[50][50];
int chk[50][50];
int x_mov[] = { 0,  0, -1, 1};
int y_mov[] = { 1, -1,  0, 0};
pii dest;
 
int bt( int x, int y )
{
    if(x==dest.first && y==dest.second)
            return true;
    //cout << x <<" "<<y << endl;
    for( int i = 0; i <4 ; i++){
        int x_cur = x + x_mov[i];
        int y_cur = y + y_mov[i];
        if( x_cur>=1 && x_cur<=m && y_cur>=1 && y_cur<=n){
        if( grid[x_cur][y_cur]=='.' && vis[x_cur][y_cur]==-1){
            vis[x_cur][y_cur] = 1;
            if(bt( x_cur,y_cur) ==true)
                return true;
            vis[x_cur][y_cur]=-1;
        }
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        vii v;
        memset(vis, -1, sizeof(vis));
        memset(chk, -1, sizeof(chk));
        for( int i =1; i<=m;i++)
            for(int j=1; j<=n; j++)
                cin >> grid[i][j];
        for( int i =1; i<=m;i++){
            if( grid[i][1]=='.' && chk[i][1]==-1){
                v.pb( mp(i,1));
                chk[i][1]=1;
            }
            if(grid[i][n]=='.' && chk[i][n]==-1){
                v.pb(mp(i,n));
                chk[i][n]=1;
            }
        }
        for( int i =1; i<=n;i++){
            if( grid[1][i]=='.' && chk[1][i]==-1){
                v.pb( mp(1,i));
                chk[1][i]=1;
            }
            if(grid[m][i]=='.' && chk[m][i]==-1){
                v.pb(mp(m,i));
                chk[m][i]=1;
            }
        }
       // cout << v.size();
 
        if( v.size()>2 || v.size()<=1 )
            cout <<"invalid\n";
        else{
            dest = v[1];
            vis[v[0].first][v[0].second] = 1;
            if( bt( v[0].first, v[0].second ) == true )
                cout <<"valid\n";
            else
                cout << "invalid\n";
        }
        v.clear();
    }
    return 0;
}
