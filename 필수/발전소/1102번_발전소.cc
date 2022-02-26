#include <iostream>
#include <vector>
#include<cstring>
using namespace std;

int answer = 600;
#define MAX 16
int Cost[1 << MAX];

int Bit_Count(int B) {
    int Cnt = 0;
    while (B != 0) {
        Cnt = Cnt + (B & 1);
        B = B >> 1;
    }
    return Cnt;
}

int dfsFindAllP(vector<pair<vector<int>, int>> &currentY,int resultP, int &currentP,int &currentCost,int status) {
    //cout << "현재 켜져있는 개수: " << currentP << " 현재 비용: " << currentCost << " 현재I: " << startI << "현재 J:" << startJ << endl;
    //if (resultP <= currentP) {
    //   // cout << "켜진 개수 만족" << endl;
    //    if (answer > currentCost) {
    //      //  cout << "현재 answer: " << answer << " 바뀔 answer: " << currentCost << endl;
    //        answer = currentCost;
    //    }
    //    return;
    //}
    //cout << Bit_Count(status) << endl;
    if (Bit_Count(status)>=resultP) {
        //cout << "end come" << endl;
        return 0;
    }
    if (Cost[status] != -1) {
        return Cost[status];
    }
   
    Cost[status] = 600;

    for (int i = 0; i < currentY.size(); i++) {

        if (currentY[i].second == 1) {  //켜져있는 애들만 순회할 수 있도록 검열
            for (int j = 0; j < currentY[i].first.size(); j++) {
            
                if (currentY[j].second == 0) { //꺼져있는 애 고르기.
                    
                    currentCost += currentY[i].first[j]; //키기 위한 비용 증가.
                    currentP++;                          //켜진 발전소 수 증가.
                    currentY[j].second = 1;              //꺼져있던 애 키는걸로 변경.
                    int nextStatus = status | (1 << j);
                    Cost[status]=min(Cost[status], currentY[i].first[j] +dfsFindAllP(currentY, resultP, currentP, currentCost, nextStatus)); //변경된 상태로 재귀.
                    //cout << Cost[status] << endl;
                    //currentCost -= currentY[i].first[j];    //재귀 후 변경해준 값 원상 복귀.
                    currentP--;
                    currentY[j].second = 0;
                }
            }
        }
    }
    return Cost[status];
}
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pair<vector<int>,int>> costs;
    for (int i = 0; i < N; i++) {
        vector<int> tempvec;
        for (int j = 0; j < N; j++) {
            int tempCost;
            cin >> tempCost;
            tempvec.push_back(tempCost);
        }
        costs.push_back(make_pair(tempvec,0));
    }
    string Ponoff;
    cin >> Ponoff;
    int startstatus = 0;
    int onCount = 0;
    for (int i = 0; i < Ponoff.size(); i++) {
        if (Ponoff[i] == 'Y') {
            startstatus = startstatus | (1 << i);
            costs[i].second = 1;
        }
        else {
            costs[i].second = 0;
        }
       
    }
    memset(Cost, -1, sizeof(Cost));
    int resultP;
    cin >> resultP;
    int currentCost = 0;
    answer = dfsFindAllP(costs, resultP, onCount, currentCost,startstatus);
    if (answer == 600) {
        cout << -1;
        return 0;
    }
    cout << answer;
}
