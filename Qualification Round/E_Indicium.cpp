#include <iostream>
#include <algorithm>
#define MAXN 5
using namespace std;

int T, N, K;
int latinSquares[7][5][5] = 
{
    {{1}}, 
    {{1, 2}, {2, 1}},
    {{1, 2, 3}, {2, 3, 1}, {3, 1, 2}},
    {{1, 2, 3, 4}, {2, 1, 4, 3}, {3, 4, 1, 2}, {4, 3, 2, 1}},
    {{1, 2, 3, 4}, {2, 4, 1, 3}, {3, 1, 4, 2}, {4, 3, 2, 1}},
    {{1, 2, 3, 4, 5}, {2, 3, 5, 1, 4}, {3, 5, 4, 2, 1}, {4, 1, 2, 5, 3}, {5, 4, 1, 3, 2}},
    {{1, 2, 3, 4, 5}, {2, 4, 1, 5, 3}, {3, 5, 4, 2, 1}, {4, 1, 5, 3, 2}, {5, 3, 2, 1, 4}},
};
int perm[MAXN] = {0, 1, 2, 3, 4}, perm2[MAXN] = {1, 2, 3, 4, 5}, idx[5][2] = {{0, 0}, {1, 1}, {2, 2}, {3, 4}, {5, 6}};
bool isRows;
bool check(int i){
    for(int j = 0; j < N; ++j)
        perm2[j] = j + 1;
    do{
        int sum = 0;
        for(int j = 0; j < N; ++j)
            sum += perm2[latinSquares[i][perm[j]][j] - 1];
        if(sum == K){
            isRows = true;
            return true;
        }
    }while(next_permutation(perm2, perm2 + N));
    do{
        int sum = 0;
        for(int j = 0; j < N; ++j)
            sum += perm2[latinSquares[i][j][perm[j]] - 1];
        if(sum == K){
            isRows = false;
            return true;
        }
    }while(next_permutation(perm2, perm2 + N));
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        cout << "Case #" << tt << ": ";
        cin >> N >> K;
        int pos = -1;
        for(int j = 0; j < N; ++j)
            perm[j] = j;
        for(int j = idx[N - 1][0]; j <= idx[N - 1][1]; ++j){
            do{
                if(check(j)){
                    pos = j;
                    break;
                }
            }while(next_permutation(perm, perm + N));
            if(pos != -1)
                break;
        }
        if(pos != -1){
            cout << "POSSIBLE\n";
            for(int y = 0; y < N; ++y){
                for(int x = 0; x < N; ++x){
                    if(isRows)
                        cout << perm2[latinSquares[pos][perm[y]][x] - 1] << " ";
                    else
                        cout << perm2[latinSquares[pos][y][perm[x]] - 1] << " ";
                }
                cout << "\n";
            }
        }else
            cout << "IMPOSSIBLE\n";
    }
    return 0;
}
