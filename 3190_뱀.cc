#include <iostream>
#include <vector>
using namespace std;

int moveX[4] = { 0,1,0,-1 };
int moveY[4] = { 1,0,-1,0 };

string check(int size,vector<pair<int,int>> &applePos, vector<pair<int,int>> snakePos,int directionNum) {

    //cout << "check directionNum: " << directionNum << endl;
    pair<int, int> headPos = snakePos[0];
    int headPosX = headPos.first + moveX[directionNum];
    int headPosY = headPos.second + moveY[directionNum];

    if (headPosX >= size || headPosY >= size || headPosY < 0 || headPosX < 0) {
        return "done";
    }
    
    for (int i = 1; i < snakePos.size(); i++) {
        if (snakePos[i].first == headPosX && snakePos[i].second == headPosY) {
            
            return "done";
        }
    }

    for (int i = 0; i < applePos.size(); i++) {
       
        //cout << "before: (" << applePos[i].first << "," << applePos[i].second << "), ";
        if (applePos[i].first == headPosX && applePos[i].second== headPosY) {
            
            applePos.erase(applePos.begin() + i);
            return "apple";
        }
    }
    //cout << endl;

    /*for (int i = 0; i < applePos.size(); i++) {
        cout << "after: (" << applePos[i].first << "," << applePos[i].second << "), ";
    }
    cout << endl;*/
    return "null";
}

void move(vector<pair<int, int>> &snakePos,string status,int directionNum) {
    
  /*  cout << endl;
    for (int i = 0; i < snakePos.size(); i++) {
        cout << "(" << snakePos[i].first << "," << snakePos[i].second << "), ";
    }
    cout << endl;*/
    pair<int, int> tailPos = snakePos[snakePos.size() - 1];

    for (int i = snakePos.size() - 1; i > 0; i--) {
        //cout << "move i " << i << endl;
        snakePos[i].first = snakePos[i - 1].first;
        snakePos[i].second = snakePos[i - 1].second;
    }
    snakePos[0].first += moveX[directionNum];
    snakePos[0].second += moveY[directionNum];

    if (status == "apple") {
        snakePos.push_back(tailPos);
    }

  /*  cout << endl;
    for (int i = 0; i < snakePos.size(); i++) {
        cout << "(" << snakePos[i].first << "," << snakePos[i].second << "), ";
    }
    cout << endl;
    cout << "move Done" << endl;*/
}

bool checkHead(vector<pair<int, int>> snakePos) {
    //cout << "checkHeand start" << endl;
    for (int i = 1; i < snakePos.size(); i++) {
        if (snakePos[i].first == snakePos[0].first && snakePos[i].second == snakePos[0].second) {
            return false;
        }
    }
    //cout << "checkHead Done" << endl;
    return true;
}

int main() {
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int size, applecount, moveDirection;
    int time = 0;
    int directionNum = 0;
    string status = "";
    vector<pair<int, int>> applePos;
    vector<pair<int, char>> moveDirectionTime;
    vector<pair<int, int>> snakePos;

    
    cin >> size >> applecount;

    for (int i = 0; i < applecount; i++) {
        int tempapplePosx, tempapplePosy;
        cin >> tempapplePosx;
        cin >> tempapplePosy;
        applePos.push_back({ tempapplePosx-1,tempapplePosy-1 });
    }
    cin >> moveDirection;

    for (int i = 0; i < moveDirection; i++) {
        int tempMoveDirectionTime;
        char tempMoveDirection;
        cin >> tempMoveDirectionTime;
        cin >> tempMoveDirection;
        moveDirectionTime.push_back({ tempMoveDirectionTime,tempMoveDirection });
    }

    snakePos.push_back({ 0,0 });

    while (true) {


        time++;
        //cout << "========" << time << "=====================" << endl;
        status = check(size,applePos,snakePos,directionNum);
        //cout << "status: " << status << endl;
        if (status == "done") {
            break;
        }
        else {
            move(snakePos,status,directionNum);
        }

 /*       if (!checkHead(snakePos)) {
            break;
        }*/
        
        if (moveDirectionTime.size()>0 && moveDirectionTime[0].first == time) {
            char rotation = moveDirectionTime[0].second;
            if (rotation == 'L') {
                directionNum--;
                if (directionNum == -1) {
                    directionNum = 3;
                }
            }
            else {
                directionNum++;
                if (directionNum == 4) {
                    directionNum = 0;
                }
            }

            moveDirectionTime.erase(moveDirectionTime.begin());
        }
    }
    cout << time;
}