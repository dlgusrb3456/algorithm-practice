#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int mean(vector<int> numCount,int sum) {
    int size = numCount.size();
    int Mean = round(sum / (float)size);
    return Mean;
}

int mid(vector<int> numCount) {
    int size = numCount.size();
    int midIndex = (size / 2);
    //cout << "midIndex: " << midIndex << endl;
    return numCount[midIndex];
}

int differ(vector<int> numCount) {
    int min = numCount[0];
    int max = numCount[numCount.size() - 1];
    return max - min;
}

int manyNum(vector<pair<int,int>> numsMany) {
    if (numsMany[0].first != numsMany[1].first) {
        return numsMany[0].second;
    }
    else {
        return numsMany[1].second;
    }
}


bool many(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) {
        return true;
    }
    else if (a.first == b.first) {
        if (a.second < b.second) {
            return true;
        }
    }
    return false;
}


int main() {
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int numCount;
    vector<int> nums;
    vector<pair<int, int>> numsMany(8002);
    cin >> numCount;
    
    int sum = 0;
    for (int i = 0; i < numCount; i++) {
        int tempcount;
        cin >> tempcount;
        if (tempcount <= 0) {
            numsMany[-tempcount].first++;
            numsMany[-tempcount].second = tempcount;
        }
        else {
            numsMany[tempcount + 4000].first++;
            numsMany[tempcount + 4000].second = tempcount;
        }
        sum += tempcount;
        nums.push_back(tempcount);
    }
    sort(nums.begin(), nums.end());
    sort(numsMany.begin(), numsMany.end(), many);
    
    cout << mean(nums, sum) << endl;
    cout << mid(nums) << endl;
    cout << manyNum(numsMany) << endl;
    cout << differ(nums);


}