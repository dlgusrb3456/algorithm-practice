#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int Bit_Count(int B) {
    int Cnt = 0;
    while (B != 0) {
        Cnt = Cnt + (B & 1);
        B = B >> 1;
    }
    return Cnt;
}


int dp[16][1 << 17];
vector<vector<int>> Costs;
int dfsFindAllCost(int visit,int xpos) {
    //cout << bitset<4>(visit) << endl;
    if (dp[xpos][visit] != -1) {
        return dp[xpos][visit];
    }
    if (Bit_Count(visit) >= Costs.size()) {
       /* cout << "Cost: " << CurrentCost << endl;
        cout << xpos<< endl;*/
        if (Costs[xpos][0] != 0) {
            return Costs[xpos][0];
        }
        return 987654321;
    }
   
    dp[xpos][visit] = 987654321;

        for (int j = 0; j < Costs.size(); j++) {
            if (Costs[xpos][j] == 0 || (visit & (1 << j))>0) {
                //cout << (visit & (1 << j)) << endl;
                continue;
            }

            int ijcost = Costs[xpos][j];
            int nextvisit = visit | (1 << j);
            dp[xpos][visit] = min(dp[xpos][visit], ijcost + dfsFindAllCost(nextvisit,j));
           
        }
    return dp[xpos][visit];
}


int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int Count;
    cin >> Count;
    for (int i = 0; i < 16; i++) {
        memset(dp[i], -1, sizeof(dp[i]));
    }
    int visit = 0;
    for (int i = 0; i < Count; i++) {
        vector<int> tempVec;
        for (int j = 0; j < Count; j++) {
            int TempCost;
            cin >> TempCost;
            tempVec.push_back(TempCost);
        }
        Costs.push_back(tempVec);
    }
    visit += 1 << 0;
    int result = dfsFindAllCost(visit, 0);
    cout << result << endl;
}
