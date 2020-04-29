#include <iostream>
#include <set>
#define MAXN 100
using namespace std;

int T, N, M[MAXN][MAXN], K, R, C;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        cout << "Case #" << tt << ": ";
        cin >> N;
        for(int y = 0; y < N; ++y)
            for(int x = 0; x < N; ++x)
                cin >> M[y][x];
        K = R = C = 0;
        for(int y = 0; y < N; ++y)
            K += M[y][y];
        for(int y = 0; y < N; ++y){
            set<int> exi;
            bool pos = true;
            for(int x = 0; x < N; ++x){
                if(exi.find(M[y][x]) == exi.end()){
                    exi.insert(M[y][x]);
                    continue;
                }
                pos = false;
                break;
            }
            if(!pos)
                R++;
        }
        for(int x = 0; x < N; ++x){
            set<int> exi;
            bool pos = true;
            for(int y = 0; y < N; ++y){
                if(exi.find(M[y][x]) == exi.end()){
                    exi.insert(M[y][x]);
                    continue;
                }
                pos = false;
                break;
            }
            if(!pos)
                C++;
        }
        cout << K << " " << R << " " << C << "\n";
    }
    return 0;
}
