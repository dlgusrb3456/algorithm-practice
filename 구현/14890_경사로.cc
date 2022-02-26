#include <iostream>
#include <vector>

using namespace std;

bool check(vector<pair<int,int>> vec, int L) {
   /* cout << "start" << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].first << " ";
    }
    cout << endl;*/
    for (int i = 0; i < vec.size()-1; i++) {
        if (vec[i].first - vec[i + 1].first > 1 || vec[i].first - vec[i + 1].first < -1) {
            return false;
        }
        else if (vec[i].first - vec[i + 1].first == 1) {
            //cout << "down i " << i << " ";
            bool itcan = true;
            int level = vec[i + 1].first;
            for (int j = i + 1; j < i + 1 + L; j++) {
                //cout << "down j " << j << " ";
                if (j >= vec.size()) {
                    itcan = false;
                }
                else {
                    if (vec[j].first == level && vec[j].second == 0) {
                        vec[j].second = 1;
                    }
                    else {
                        itcan = false;
                    }
                }
            }
            //cout << endl;
            if (itcan == false) {
                return false;
            }

        }
        else if (vec[i].first - vec[i + 1].first == -1) {
            //cout << "up i " << i << " ";
            bool itcan = true;
            int level = vec[i].first;
            for (int j = i; j > i - L; j--) {
                //cout << "up j " << j << " ";
                if (j < 0) {
                    itcan = false;
                    break;
                }
                else {
                    if (vec[j].first == level && vec[j].second == 0) {
                        vec[j].second = 1;
                    }
                    else {
                        itcan = false;
                    }
                }
            }
            if (itcan == false) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int size, L;
    vector<vector<pair<int, int>>> maps;
    cin >> size >> L;
    for (int i = 0; i < size; i++) {
        vector<pair<int, int>> tempvec;
        for (int j = 0; j < size; j++) {
            int temp;
            cin >> temp;
            tempvec.push_back({ temp,0 });
        }
        maps.push_back(tempvec);
    }
   
   /* cout << "size: " << size << endl;
    cout << "l : " << L << endl;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
     
            cout << maps[i][j].first << " ";
        }
        cout << endl;
    }*/
    int answer = 0;
    for (int i = 0; i < size; i++) {
        if (check(maps[i], L)) {
            answer++;
        }
        vector<pair<int, int>> temp;
        for (int j = 0; j < size; j++) {
            temp.push_back(maps[j][i]);
        }
        if (check(temp, L)) {
            answer++;
        }
        
    }
    cout << answer;
}