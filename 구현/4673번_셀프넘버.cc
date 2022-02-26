#include <iostream>
using namespace std;
int main() {
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int limitNums = 10000;
    int checkVal[10001] = { 0 };
    for (int i = 0; i <= 10000; i++) {
        int sums = i;
        int trashI = i;
        while (true) {
            if (trashI / 10 == 0) {
                sums += trashI;
                break;
            }
            else {
                sums += trashI % 10;
                trashI = trashI / 10;
            }
        }

        if (sums <= 10000) {
            checkVal[sums] = 1;
        }
        
    }
    for (int i = 1; i < 10001; i++) {
        if (checkVal[i] == 0) {
            cout << i << '\n';
        }
    }

}