#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> turnleft(int size, vector<vector<int>>& tempboard) {
    vector<vector<int>> temptempboard = tempboard;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int start = j;
            bool real = false;
            while (temptempboard[i][j] == 0) {
                if (j == size - 1) {
                    real = true;
                    break;
                }
                j++;
            }
            if (real) {
                break;
            }
            temptempboard[i].erase(temptempboard[i].begin() + start, temptempboard[i].begin()+j);

            for (int k = 0; k < j-start; k++) {
                temptempboard[i].push_back(0);
            }
            
            j=start;
        }

        for (int j = 0; j < size; j++) {
            if (j != size - 1 && temptempboard[i][j] == temptempboard[i][j + 1]) {
                temptempboard[i][j] += temptempboard[i][j + 1];
                temptempboard[i].erase(temptempboard[i].begin() + j + 1);
                temptempboard[i].push_back(0);
            }
            else if (temptempboard[i][j] == 0) {
                break;
            }
         
        }
    }
    

    return temptempboard;
}
vector<vector<int>> turnright(int size, vector<vector<int>>& tempboard) {
    vector<vector<int>> temptempboard = tempboard;
    for (int i = 0; i < size; i++) {
 
        for (int j = 0; j < size; j++) {
            if (temptempboard[i][j] == 0) {
                temptempboard[i].erase(temptempboard[i].begin() + j);
                temptempboard[i].insert(temptempboard[i].begin(), 0);
            }
        }



        for (int j = size - 1; j >= 0; j--) {
            if (j != 0 && temptempboard[i][j] == temptempboard[i][j - 1]) {
                temptempboard[i][j] += temptempboard[i][j - 1];
                temptempboard[i].erase(temptempboard[i].begin() + j - 1);
                temptempboard[i].insert(temptempboard[i].begin(), 0);
            }
            else if (temptempboard[i][j] == 0) {
                break;
            }
        }
    }
    return temptempboard;
}
vector<vector<int>> turnup(int size, vector<vector<int>>& tempboard) {
    vector<vector<int>> temptempboard = tempboard;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int temp = temptempboard[i][j];
            temptempboard[i][j] = temptempboard[j][i];
            temptempboard[j][i] = temp;
        }
    }
    temptempboard = turnleft(size, temptempboard);

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int temp = temptempboard[i][j];
            temptempboard[i][j] = temptempboard[j][i];
            temptempboard[j][i] = temp;
        }
    }
    return temptempboard;
}
vector<vector<int>> turnunder(int size, vector<vector<int>>& tempboard) {
    vector<vector<int>> temptempboard = tempboard;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int temp = temptempboard[i][j];
            temptempboard[i][j] = temptempboard[j][i];
            temptempboard[j][i] = temp;
        }
    }

    temptempboard = turnright(size, temptempboard);

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int temp = temptempboard[i][j];
            temptempboard[i][j] = temptempboard[j][i];
            temptempboard[j][i] = temp;
        }
    }
    return temptempboard;
}

int start(int size, vector<vector<int>> &board) {
    vector<vector<vector<int>>> arr;
    vector<vector<vector<int>>> arr2;
    int answer = 0;
    arr.push_back(board);
    for (int i = 0; i < 5; i++) {
        vector<vector<int>> temp1;
        vector<vector<int>> temp2;
        vector<vector<int>> temp3;
        vector<vector<int>> temp4;
        for (int j = 0; j < arr.size(); j++) {
            temp1 = turnup(size, arr[j]);
            temp2 = turnleft(size, arr[j]);
            temp3 = turnright(size, arr[j]);
            temp4 = turnunder(size, arr[j]);
            arr2.push_back(temp1);
            arr2.push_back(temp2);
            arr2.push_back(temp3);
            arr2.push_back(temp4);
        }
        arr.clear();
        for (int j = 0; j < arr2.size(); j++) {
            arr.push_back(arr2[j]);
        }
        arr2.clear();
    }

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                if (answer < arr[i][j][k]) {
                    answer = arr[i][j][k];
                }
            }
        }
    }
    return answer;
}




int main() {
    int size;
    cin >> size;
    vector<vector<int>> board;
    for (int i = 0; i < size; i++) {
        vector<int> vec;
        board.push_back(vec);
        for (int j = 0; j < size; j++) {
            int temp;
            cin >> temp;
            board[i].push_back(temp);
        }
    }

    //test(size, board);


    int result = start(size, board);
    cout << result;

}