#include <iostream>  
#include <stdlib.h>
#include <vector>
#include <array>
#define int long long
using namespace std;

const int md1 = 1e9 + 7;
const int md2 = 1e9 + 9;
const int p = 31;

int power(int a,int b,int md){
    int ret = 1;
    int cur = a;
    for(int i=0;i<=30;i++){
        if(b & (1ll<<i)){
            ret *= cur;
            ret %= md;
        }
        cur *= cur;
        cur %= md;
    }
    return ret;
}

void ColorPrint(char text, int fg_color, int bg_color)
{
    static const char begin_sequence[]{0x1B,'[','\0'};
    static const char reset[]{0x1B,'[','0','m','\0'};
    cout << begin_sequence << fg_color << ';' << bg_color << 'm' << text << reset;

}
signed main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<pair<int,int>>> col_down(n+2,vector<pair<int,int>>(m+2,{0,0}));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            col_down[i][j].first = ((grid[i][j]-'a'+1)*(power(p,i-1,md1)))%md1;
            col_down[i][j].first += col_down[i-1][j].first;
            col_down[i][j].first %= md1;
            col_down[i][j].second = ((grid[i][j]-'a'+1)*(power(p,i-1,md2)))%md2;
            col_down[i][j].second += col_down[i-1][j].second;
            col_down[i][j].second %= md2;
        }
    }
    vector<vector<pair<int,int>>> col_up(n+2,vector<pair<int,int>>(m+2,{0,0}));
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            if(i==n){
                col_up[i][j].first = ((grid[i][j]-'a'+1)*(power(p,n-i,md1)))%md1;
                col_up[i][j].second = ((grid[i][j]-'a'+1)*(power(p,n-i,md2)))%md2;
                continue;
            }
            col_up[i][j].first = ((grid[i][j]-'a'+1)*(power(p,n-i,md1)))%md1;
            col_up[i][j].second = ((grid[i][j]-'a'+1)*(power(p,n-i,md2)))%md2;
            col_up[i][j].first += col_up[i+1][j].first;
            col_up[i][j].first %= md1;
            col_up[i][j].second += col_up[i+1][j].second;
            col_up[i][j].second %= md2;
        }
    }
    vector<vector<pair<int,int>>> row_l_to_r(n+2,vector<pair<int,int>>(m+2,{0,0}));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            row_l_to_r[i][j].first = ((grid[i][j]-'a'+1)*(power(p,j-1,md1)))%md1;
            row_l_to_r[i][j].second = ((grid[i][j]-'a'+1)*(power(p,j-1,md2)))%md2;
            row_l_to_r[i][j].first += row_l_to_r[i][j-1].first;
            row_l_to_r[i][j].first %= md1;
            row_l_to_r[i][j].second += row_l_to_r[i][j-1].second;
            row_l_to_r[i][j].second %= md2;
        }
    }
    vector<vector<pair<int,int>>> row_r_to_l(n+2,vector<pair<int,int>>(m+2,{0,0}));
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            row_r_to_l[i][j].first = ((grid[i][j]-'a'+1)*(power(p,m-j,md1)))%md1;
            row_r_to_l[i][j].second = ((grid[i][j]-'a'+1)*(power(p,m-j,md2)))%md2;
            row_r_to_l[i][j].first += row_r_to_l[i][j+1].first;
            row_r_to_l[i][j].first %= md1;
            row_r_to_l[i][j].second += row_r_to_l[i][j+1].second;
            row_r_to_l[i][j].second %= md2;
        }
    }
    vector<vector<pair<int,int>>> diag_down(n+2,vector<pair<int,int>>(m+2,{0,0}));
    vector<vector<int>> pows(n+2,vector<int>(m+2,-1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pows[i][j]=pows[i-1][j-1]+1;
            diag_down[i][j].first = ((grid[i][j]-'a'+1)*(power(p,pows[i][j],md1))%md1);
            diag_down[i][j].second = ((grid[i][j]-'a'+1)*(power(p,pows[i][j],md2))%md2);
            diag_down[i][j].first += diag_down[i-1][j-1].first;
            diag_down[i][j].second += diag_down[i-1][j-1].second;
            diag_down[i][j].first %= md1;
            diag_down[i][j].second %= md2;
        }
    }
    vector<vector<pair<int,int>>> diag_up(n+2,vector<pair<int,int>>(m+2,{0,0}));
    vector<vector<int>> pows1(n+2,vector<int>(m+2,-1));
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            pows1[i][j]=pows1[i+1][j+1]+1;
            diag_up[i][j].first = ((grid[i][j]-'a'+1)*(power(p,pows1[i][j],md1))%md1);
            diag_up[i][j].second = ((grid[i][j]-'a'+1)*(power(p,pows1[i][j],md2))%md2);
            diag_up[i][j].first += diag_up[i+1][j+1].first;
            diag_up[i][j].second += diag_up[i+1][j+1].second;
            diag_up[i][j].first %= md1;
            diag_up[i][j].second %= md2;
        }
    }
    vector<vector<pair<int,int>>> diag_down2(n+2,vector<pair<int,int>>(m+2,{0,0}));
    vector<vector<int>> pows2(n+2,vector<int>(m+2,-1));
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            pows2[i][j]=pows2[i-1][j+1]+1;
            diag_down2[i][j].first = ((grid[i][j]-'a'+1)*(power(p,pows2[i][j],md1))%md1);
            diag_down2[i][j].second = ((grid[i][j]-'a'+1)*(power(p,pows2[i][j],md2))%md2);
            diag_down2[i][j].first += diag_down2[i-1][j+1].first;
            diag_down2[i][j].second += diag_down2[i-1][j+1].second;
            diag_down2[i][j].first %= md1;
            diag_down2[i][j].second %= md2;
        }
    }
    vector<vector<pair<int,int>>> diag_up2(n+2,vector<pair<int,int>>(m+2,{0,0}));
    vector<vector<int>> pows3(n+2,vector<int>(m+2,-1));
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            pows3[i][j]=pows3[i+1][j-1]+1;
            diag_up2[i][j].first = ((grid[i][j]-'a'+1)*(power(p,pows3[i][j],md1))%md1);
            diag_up2[i][j].second = ((grid[i][j]-'a'+1)*(power(p,pows3[i][j],md2))%md2);
            diag_up2[i][j].first += diag_up2[i+1][j-1].first;
            diag_up2[i][j].second += diag_up2[i+1][j-1].second;
            diag_up2[i][j].first %= md1;
            diag_up2[i][j].second %= md2;
        }
    }
    int sz;
    cin >> sz;
    vector<string> words(sz+1);
    vector<vector<int>> ans(n+1,vector<int>(m+1,0));
    vector<array<int,4>> good;
    for(int i=1;i<=sz;i++){
        cin >> words[i];
        pair<int,int> hash = {0,0};
        int cur1 = 1;
        int cur2 = 1;
        for(char c:words[i]){
            hash.first += ((c-'a'+1)*cur1)%md1;
            hash.first %= md1;
            hash.second += ((c-'a'+1)*cur2)%md2;
            hash.second %= md2;
            cur1 *= p;
            cur2 *= p;
            cur1 %= md1;
            cur2 %= md2;
        }
        //cout << "o";
        int check = words[i].size();
        int taken = 0;
        for(int j=1;j<=n;j++){
            if(taken)break;
            for(int k=1;k<=m;k++){
                if(grid[j][k]!=words[i][0])continue;
                if(taken)break;
                if(k+check-1<=m){
                    pair<int,int> take = row_l_to_r[j][k+check-1];
                    take.first -= row_l_to_r[j][k-1].first;
                    take.first += md1;
                    take.first %= md1;
                    take.second -= row_l_to_r[j][k-1].second;
                    take.second += md2;
                    take.second %= md2;
                    take.first *= power(power(p,k-1,md1),md1-2,md1);
                    take.first %= md1;
                    take.second *= power(power(p,k-1,md2),md2-2,md2);
                    take.second %= md2;
                    if(take == hash){
                        good.push_back({j,k,check,1});
                        taken = 1;
                        break;
                    }
                }
                if(k-check+1>=1){
                    pair<int,int> take = row_r_to_l[j][k-check+1];
                    take.first -= row_r_to_l[j][k+1].first;
                    take.first += md1;
                    take.first %= md1;
                    take.second -= row_r_to_l[j][k+1].second;
                    take.second += md2;
                    take.second %= md2;
                    take.first *= power(power(p,m-k,md1),md1-2,md1);
                    take.first %= md1;
                    take.second *= power(power(p,m-k,md2),md2-2,md2);
                    take.second %= md2;
                    if(take == hash){
                        good.push_back({j,k,check,2});
                        taken = 1;
                        break;
                    }
                }
                if(j+check-1<=n){
                    pair<int,int> take = col_down[j+check-1][k];
                    take.first -= col_down[j-1][k].first;
                    take.first += md1;
                    take.first %= md1;
                    take.second -= col_down[j-1][k].second;
                    take.second += md2;
                    take.second %= md2;
                    take.first *= power(power(p,j-1,md1),md1-2,md1);
                    take.first %= md1;
                    take.second *= power(power(p,j-1,md2),md2-2,md2);
                    take.second %= md2;
                    if(take == hash){
                        good.push_back({j,k,check,3});
                        taken = 1;
                        break;
                    }
                }
                if(j-check+1>=1){
                    pair<int,int> take = col_up[j-check+1][k];
                    take.first -= col_up[j+1][k].first;
                    take.first += md1;
                    take.first %= md1;
                    take.second -= col_up[j+1][k].second;
                    take.second += md2;
                    take.second %= md2;
                    take.first *= power(power(p,n-j,md1),md1-2,md1);
                    take.first %= md1;
                    take.second *= power(power(p,n-j,md2),md2-2,md2);
                    take.second %= md2;  
                    if(take == hash){
                        good.push_back({j,k,check,4});
                        taken = 1;
                        break;
                    }
                }
                if(j+check-1<=n && k+check-1<=m){
                    pair<int,int> take = diag_down[j+check-1][k+check-1];
                    take.first -= diag_down[j-1][k-1].first;
                    take.first += md1;
                    take.first %= md1;
                    take.second -= diag_down[j-1][k-1].second;
                    take.second += md2;
                    take.second %= md2;
                    take.first *= power(power(p,pows[j][k],md1),md1-2,md1);
                    take.first %= md1;
                    take.second *= power(power(p,pows[j][k],md2),md2-2,md2);
                    take.second %= md2;
                    if(take == hash){
                        good.push_back({j,k,check,5});
                        taken = 1;
                        break;
                    }
                }
                if(j-check+1>=1 && k-check+1>=1){
                    pair<int,int> take = diag_up[j-check+1][k-check+1];
                    take.first -= diag_up[j+1][k+1].first;
                    take.first += md1;
                    take.first %= md1;
                    take.second -= diag_up[j+1][k+1].second;
                    take.second += md2;
                    take.second %= md2;
                    take.first *= power(power(p,pows1[j][k],md1),md1-2,md1);
                    take.first %= md1;
                    take.second *= power(power(p,pows1[j][k],md2),md2-2,md2);
                    take.second %= md2;
                    if(take == hash){
                        good.push_back({j,k,check,6});
                        taken = 1;
                        break;
                    }
                }
                if(j+check-1<=n && k-check+1>=1){
                    pair<int,int> take = diag_down2[j+check-1][k-check+1];
                    take.first -= diag_down2[j-1][k+1].first;
                    take.first += md1;
                    take.first %= md1;
                    take.second -= diag_down2[j-1][k+1].second;
                    take.second += md2;
                    take.second %= md2;
                    take.first *= power(power(p,pows2[j][k],md1),md1-2,md1);
                    take.first %= md1;
                    take.second *= power(power(p,pows2[j][k],md2),md2-2,md2);
                    take.second %= md2;
                    if(take == hash){
                        good.push_back({j,k,check,7});
                        taken = 1;
                        break;
                    }
                }
                if(j-check+1>=1 && k+check-1<=m){
                    pair<int,int> take = diag_up2[j-check+1][k+check-1];
                    take.first -= diag_up2[j+1][k-1].first;
                    take.first += md1;
                    take.first %= md1;
                    take.second -= diag_up2[j+1][k-1].second;
                    take.second += md2;
                    take.second %= md2;
                    take.first *= power(power(p,pows3[j][k],md1),md1-2,md1);
                    take.first %= md1;
                    take.second *= power(power(p,pows3[j][k],md2),md2-2,md2);
                    take.second %= md2;
                    if(take == hash){
                        good.push_back({j,k,check,8});
                        taken = 1;
                        break;
                    }
                }

            }
        }

    }
    int dx[]={0,0,0,1,-1,1,-1,1,-1};
    int dy[]={0,1,-1,0,0,1,-1,-1,1};
    int ind = 1;
    for(auto [i,j,len,type]:good){
        int x = dx[type];
        int y = dy[type];
        int cur_x = i;
        int cur_y = j;
        for(int k=1;k<=len;k++){
            ans[cur_x][cur_y]=ind;
            cur_x+=x;
            cur_y+=y;
        }
        ind++;
    }
    vector<int> cols={31,32,33,34,35,36,91,92,93,94,95,96};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ans[i][j]==0){
                ColorPrint(grid[i][j],97,40);
            }
            else{
                ColorPrint(grid[i][j],cols[ans[i][j]%12],40);
            }
            cout << " ";
        }
        cout << '\n';
    }
}























