//내 풀이
#include <iostream>
#include <vector>
using namespace std;
bool checkArr(int xPos, int yPos, int xSize,int ySize) {
    return 0 <= xPos && xPos < xSize && 0 <= yPos && yPos < ySize;
}

bool checkDif(vector<string> vec, int nXPos, int nYPos, int aXPos, int aYPos) {
    //cout << "pos1: " << vec[nXPos][nYPos] << " pos2: " << vec[aXPos][aYPos] << '\n';
    return vec[nXPos][nYPos] != vec[aXPos][aYPos];
}

int countRC(vector<string> vec, int posX, int posY) {
    int returnInt = 0;
    int tempR = 0;
    int tempC = 0;
    char startR = vec[posX][0];
    char startC = vec[0][posY];
    for (int i = 0; i < vec.size(); i++) {
        if (startR == vec[posX][i]) {
            tempR++;
        }
        else {
            if (returnInt < tempR) {
                returnInt = tempR;
            }
            tempR = 1;
            startR = vec[posX][i];
        }

        if (startC == vec[i][posY]) {
            tempC++;
        }
        else {
            if (returnInt < tempC) {
                returnInt = tempC;
            }
            tempC = 1;
            startC = vec[i][posY];
        }
    }
    if (tempR > returnInt) {
        returnInt = tempR;
    }
    if (tempC > returnInt) {
        returnInt = tempC;
    }
    return returnInt;
}

int checkAll(vector<string> vec) {
    int returnInt = 0;
    for (int i = 0; i < vec.size(); i++) {
        char startR = vec[i][0];
        char startC = vec[0][i];
        int tempR = 0;
        int tempC = 0;
        for (int j = 0; j < vec.size(); j++) {
            if (startR == vec[i][j]) {
                tempR++;
            }
            else {
                if (returnInt < tempR) {
                    returnInt = tempR;
                }
                tempR = 1;
                startR = vec[i][j];
            }

            if (startC == vec[j][i]) {
                tempC++;
            }
            else {
                if (returnInt < tempC) {
                    returnInt = tempC;
                }
                tempC = 1;
                startC = vec[j][i];
            }

        }
        if (tempR > returnInt) {
            returnInt = tempR;
        }
        if (tempC > returnInt) {
            returnInt = tempC;
        }
    }
    return returnInt;
}

int countAnswer(vector<string> vec, int nXPos, int nYPos, int aXPos, int aYPos) {
    //int theBig = 0;

    char temp = vec[nXPos][nYPos];
    vec[nXPos][nYPos] = vec[aXPos][aYPos];
    vec[aXPos][aYPos] = temp;

    int theBig1 = countRC(vec, nXPos, nYPos);
    int theBig2 = countRC(vec, aXPos, aYPos);
    if (theBig1 < theBig2) {
        return theBig2;
    }
    else {
        return theBig1;
    }
    //return checkAll(vec);
}
 

int main() {
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int answerNum = 0;
    int size = 0;        //전체 크기
    cin >> size;
    vector<string> maps; //배열 정보
    vector<vector<int>> checkMap(size, vector<int>(size, 0)); //2차원 배열 벡터 0으로 초기화.
    

    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    for (int i = 0; i < size; i++) { //배열 정보 입력 받기
        string tempStr;
        cin >> tempStr;
        maps.push_back(tempStr);
    }

    answerNum = checkAll(maps);
    for (int i = 0; i < size; i++) { //이중포문
        for (int k = 0; k < size; k++) {
            for (int j = 0; j < 4; j++) {
                if (checkArr(i + dx[j], k + dy[j], size, size) && checkDif(maps, i,k, i + dx[j], k + dy[j])&&checkMap[i + dx[j]][k + dy[j]]==0) {
                    int tempAnswer = countAnswer(maps, i, k, i + dx[j], k + dy[j]);
                    if (tempAnswer > answerNum) {
                        answerNum = tempAnswer;
                    }
                }
            }
            checkMap[i][k] = 1;
        }
        
    }
    cout << answerNum;
}

//main에서 사용된 이중 for문에서 O(N^2) 그리고 countAnswer에서 O(N)이므로 시간 복잡도는 O(N^3)이다.

//N의 범위는 50까지이므로 제한시간인 1초를 넘기지 않는다.

//DP사용 하면 64ms 사용 안하면 44ms가 나온다.

//잘한 사람 코드 리뷰
#include <cstdio>
#include <algorithm>
#define N 52
using namespace std;

int n, k = 1;
char a[N][N];

int cross(int x, int y)
{
	int cnt1 = 1, cnt2 = 1;
	char ch = a[x][y];
	
	for(int i = x + 1; a[i][y] == ch; i++) cnt1++; //5. 반복문 안에 조건문을 넣어서 간결함
																								 //6. 주어진 위치에서 위로 자신과 같은 개수 세기
																								 // + 아래로 자신과 같은 개수 세기
																								 // => 자신이 포함된 문자열 길이만 도출
																								 // => 이러면 문제가 생기지 않나 싶지만 아님
	// 모든 배열 인자에 대해 검사가 진행되고 어차피 그중 제일 큰수가 결과값이 되므로 상관 없음
	for(int i = x - 1; a[i][y] == ch; i--) cnt1++;
	
	for(int i = y + 1; a[x][i] == ch; i++) cnt2++;
	for(int i = y - 1; a[x][i] == ch; i--) cnt2++;
	
	return max(cnt1, cnt2);
}

int f(int x, int y)
{
	int cnt1, cnt2;

	if(a[x + 1][y]) //2. 문제의 범위보다 조금 크게 전역변수로 2차원 배열 선언 (범위 검사 할필요 없음)
	{
		swap(a[x][y], a[x + 1][y]);  //3. 굳이 바꾸려는 자리랑 문자가 다른지 확인 안함. swap()함수로 간결함
		cnt1 = max(cross(x, y), cross(x + 1, y)); //4. max()함수로 간결함. 그리고 둘중 큰 함수 가져옴
		swap(a[x][y], a[x + 1][y]);
	}
	if(a[x][y + 1])
	{
		swap(a[x][y], a[x][y + 1]);
		cnt2 = max(cross(x, y), cross(x, y + 1));
		swap(a[x][y], a[x][y + 1]);
	}
	
	return max(cnt1, cnt2);
}

int main()
{	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf(" %c", a[i] + j);
	
	for(int i = 1; i <= n; i++) //1. 어차피 우측이랑 아래만 보면 됨.
		for(int j = 1; j <= n; j++)
			k = max(k, f(i, j));
	
	printf("%d", k);
}