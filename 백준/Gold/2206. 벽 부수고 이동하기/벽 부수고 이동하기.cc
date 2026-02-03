#include <bits/stdc++.h>
#define SZ 1'001
#define isAvail(y,x) (1<=y&&y<=N&&1<=x&&x<=M)
using namespace std;
constexpr int dx[]{0,1,0,-1}, dy[]{-1,0,1,0};
queue<tuple<int, int, int>> q;
int N, M, li[SZ][SZ], chk[SZ][SZ][2];
int bfs(int y, int x){
    chk[y][x][0]=1;
    q.push({y,x,0});
    while(!q.empty()){
        int y,x,w; tie(y,x,w)=q.front(); q.pop();
        if(y==N && x==M) return chk[y][x][w];
        for(int h=0;h<4;++h){
            int py=y+dy[h], px=x+dx[h];
            if(isAvail(py,px)&&chk[py][px][w]==0){
                if(li[py][px]==0){
                    chk[py][px][w]=chk[y][x][w]+1;
                    q.push({py,px,w});
                }
                else if(w==0 && li[py][px]==1){
                    chk[py][px][1]=chk[y][x][0]+1;
                    q.push({py,px,1});
                }
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j){
            char t; cin >> t; li[i][j]=t-'0';
        }
    cout << bfs(1,1);
    return 0;
}