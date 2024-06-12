#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int pic[501][501];

int x[4] = { 0,0,-1,1 };
int y[4] = { 1,-1,0,0 };


struct pos{
    int x;
    int y;
};

int bfs(int i,int j , int n, int m)
{
    queue<pos> q;
    int num = 1;
    
    pic[i][j] = 0;
    
    pos nowidx = {i,j};
    pos searchidx;
    q.push(nowidx);
    
    while(!q.empty())
    {
        nowidx = q.front();
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++)
        {
            searchidx.x = nowidx.x + x[i];
            searchidx.y = nowidx.y + y[i];
            
            if(searchidx.x <= n-1 && searchidx.x >= 0&&searchidx.y <= m-1 && searchidx.y >= 0 )
            {
                if(pic[searchidx.x][searchidx.y] == 1)
                {
                    pic[searchidx.x][searchidx.y] = 0;
                    q.push(searchidx);
                    num++;
                }
            }
        }
    }
    
    return num;
    
    
    
}





int main(void)
{
    int n,m,now;
    int cnt = 0;
    int max = 0;

    cin>>n>>m;
    
    for(int i =0 ; i < n ; i++)
        for(int j =0 ; j < m ; j++)
            cin>>pic[i][j];
    
    for(int i =0 ; i < n ; i++){
        for(int j =0 ; j < m ; j++)
        {
            if(pic[i][j] == 1)
            {
                cnt++;
                now = bfs(i,j,n,m);
                if(now > max)
                    max = now;
            }
        }
    }
    
    cout<<cnt<<"\n"<<max;
}