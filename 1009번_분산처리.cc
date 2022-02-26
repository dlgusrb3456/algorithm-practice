#include <iostream>
using namespace std;

int main() {
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int numCount;
    int a;
    int b;


    cin >> numCount;
    for (int i = 0; i < numCount; i++) {
        cin >> a;
        a = a % 10;
        cin >> b;
        if (a == 1) {
            cout << "1" << endl;
        }
        else if (a == 2) {
            int d = b % 4;
            if (d == 1) {
                cout << 2 << endl;
            }
            else if (d == 2) {
                cout << 4 << endl;
            }
            else if (d == 3) {
                cout << 8 << endl;
            }
            else {
                cout << 6 << endl;
            }
        }
        else if (a == 3) {
            int d = b % 4;
            if (d == 1) {
                cout << 3 << endl;
            }
            else if (d == 2) {
                cout << 9 << endl;
            }
            else if (d == 3) {
                cout << 7 << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
        else if (a == 4) {
            int d = b % 2;
            if (d == 1) {
                cout << 4 << endl;
            }
            else {
                cout << 6 << endl;
            }
        }
        else if (a == 5) {
            cout << 5 << endl;
        }
        else if (a == 6) {
            cout << 6 << endl;
        }
        else if (a == 7) {
            int d = b % 4;
            if (d == 1) {
                cout << 7 << endl;
            }
            else if (d == 2) {
                cout << 9 << endl;
            }
            else if (d == 3) {
                cout << 3 << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
        else if (a == 8) {
            int d = b % 4;
            if (d == 1) {
                cout << 8 << endl;
            }
            else if (d == 2) {
                cout << 4 << endl;
            }
            else if (d == 3) {
                cout << 2 << endl;
            }
            else {
                cout << 6 << endl;
            }
        }
        else if (a == 9) {
            int d = b % 2;
            if (d == 1) {
                cout << 9 << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
        else {
            cout << 10 << endl;
        }
    }


}
