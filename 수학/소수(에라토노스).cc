#include <iostream>
#include <vector>
using namespace std;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long min, max;
	cin >> min >> max;
	vector<int> primes;
	bool* real = new bool[max+1];
    for (int i = 0; i < max+1; i++) {
		real[i] = true;
	}
	for (long long i = 2; i <= max; i++) {
		if (real[i]&&i>=min) {
			primes.push_back(i);
		}
		for (long long j = i*i; j <= max; j += i) {
			real[j] = false;
		}
	}
	for (long long i = 0; i < primes.size(); i++) {
		cout << primes[i] << '\n';
	}
	
}