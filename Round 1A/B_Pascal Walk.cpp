#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <ctime>
#include <complex>
#include <bitset>
#include <tuple>
#define MAXL 500
#define MOD 1000000000000000LL
using namespace std;

typedef long long int lli;

struct point{
    int x, y, idx;
    bool operator<(const point& p)const{
        if(x == p.x)
            return y < p.y;
        return x < p.x;
    }
    bool operator>(const point& p)const{
        if(x == p.x)
            return y > p.y;
        return x > p.x;
    }
};
int T, dir[6][2] = {{1, 1}, {0, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, 0}};
lli N, Pascal[MAXL + 1][MAXL + 1];
bool visit[MAXL + 1][MAXL + 1], nvalid[MAXL + 1][MAXL + 1];
void getPascal(){
    Pascal[0][0] = 1;
    for(int y = 1; y <= MAXL; ++y){
        Pascal[y][0] = 1;
        Pascal[y][y] =  1;
        for(int x = 1; x < y; ++x){
            Pascal[y][x] += Pascal[y - 1][x - 1] + Pascal[y - 1][x];
            if(Pascal[y][x] >= MOD || nvalid[y - 1][x - 1] || nvalid[y - 1][x]){
                nvalid[y][x] = true;
            }
            Pascal[y][x] %= MOD;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    getPascal();
    cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        cout << "Case #" << tt << ": \n";
        cin >> N; 
        //N = tt;
        lli sum = 1, S = 1;
        for(int y = 0; y <= MAXL; ++y)
            for(int x = 0; x <= y; ++x)
                visit[y][x] = false;
        deque<point> dq;
        dq.push_back({0, 0, 0}); visit[0][0] = true;
        while(sum != N && S <= 500){
            point t = dq.back();
            if(S > 500){
                sum -= Pascal[dq.back().y][dq.back().x];
                visit[dq.back().y][dq.back().x] = false;
                S--;
                dq.pop_back();
            }
            bool f = true;
            for(int j = t.idx; j < 6; ++j){
                int nx = t.x + dir[j][0];
                int ny = t.y + dir[j][1];
                if(t.y % 2 == 0){
                    if(j == 0){
                        nx = t.x + dir[1][0];
                        ny = t.y + dir[1][1];
                    }else if(j == 1){
                        nx = t.x + dir[0][0];
                        ny = t.y + dir[0][1];
                    }
                }
                if(nx < 0 || ny < 0 || nx > ny || visit[ny][nx] || nvalid[ny][nx])
                    continue;
                
                lli next_sum = sum + Pascal[ny][nx];
                if(next_sum <= N){
                    sum = next_sum; ++S;
                    dq.back().idx = j + 1;
                    dq.push_back({nx, ny, 0});
                    visit[ny][nx] = true;
                    f = false;
                    break;
                }
            }
            if(f){
                sum -= Pascal[dq.back().y][dq.back().x];
                visit[dq.back().y][dq.back().x] = false;
                S--;
                dq.pop_back();
            }
        }
        lli ss = 0;
        while(!dq.empty()){
            cout << dq.front().y + 1 << " " << dq.front().x + 1 << "\n";
            ss += Pascal[dq.front().y][dq.front().x];
            dq.pop_front();
        }
    }
    return 0;
}
