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
using namespace std;

typedef long long int lli;

struct strt{
    int x, y;
    bool operator<(const strt& st)const{
        if(x == st.x)
            return y < st.y;
        return x < st.x;
    }
    bool operator>(const strt& st)const{
        if(x == st.x)
            return y > st.y;
        return x > st.x;
    }
};
lli T, R, C, ans, dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        cout << "Case #" << tt << ": ";
        cin >> R >> C;
        vector<vector<lli>> M;
        M.resize(R);
        for(int y = 0; y < R; ++y){
            M[y].resize(C, 0);
            for(int x = 0; x < C; ++x){
                cin >> M[y][x];
            }
        }
        ans = 0;
        lli sum = 0;
        queue<strt> q;
        set<strt> next;
        for(int y = 0; y < R; ++y){
            for(int x = 0; x < C; ++x){
                if(!M[y][x])
                    continue;
                ans += M[y][x];
                sum += M[y][x];
                int skill = 0, cnt = 0;
                queue<strt> tq;
                for(int j = 0; j < 4; ++j){
                    int nx = x + dir[j][0];
                    int ny = y + dir[j][1];
                    while(nx >= 0 && ny >= 0 && nx < C && ny < R){
                        if(M[ny][nx]){
                            skill += M[ny][nx];
                            cnt++;
                            tq.push({nx, ny});
                            break;
                        }
                        nx += dir[j][0];
                        ny += dir[j][1];
                    }
                }
                if(M[y][x] * cnt < skill){
                    q.push({x, y});
                    while(!tq.empty()){
                        next.insert(tq.front());
                        tq.pop();
                    }
                }
            }
        }
        bool ch = false;
        while(!q.empty()){
            strt t = q.front(); q.pop();
            sum -= M[t.y][t.x];
            M[t.y][t.x] = 0;
            ch = true;
        }
        if(ch)
            ans += sum;
        while(!next.empty()){
            set<strt> nnext;
            while(!next.empty()){
                strt t = *next.begin(); next.erase(next.begin());
                if(!M[t.y][t.x])
                    continue;
                int skill = 0, cnt = 0;
                queue<strt> tq;
                for(int j = 0; j < 4; ++j){
                    int nx = t.x + dir[j][0];
                    int ny = t.y + dir[j][1];
                    while(nx >= 0 && ny >= 0 && nx < C && ny < R){
                        if(M[ny][nx]){
                            skill += M[ny][nx];
                            cnt++;
                            tq.push({nx, ny});
                            break;
                        }
                        nx += dir[j][0];
                        ny += dir[j][1];
                    }
                }
                if(M[t.y][t.x] * cnt < skill){
                    q.push({t.x, t.y});
                    while(!tq.empty()){
                        nnext.insert(tq.front());
                        tq.pop();
                    }
                }
            }
            ch = false;
            while(!q.empty()){
                strt t = q.front(); q.pop();
                sum -= M[t.y][t.x];
                M[t.y][t.x] = 0;
                ch = true;
            }
            if(ch)
                ans += sum;
            while(!nnext.empty()){
                next.insert(*nnext.begin());
                nnext.erase(nnext.begin());
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}
