#include <iostream>
using namespace std;

long long fib(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    long long a = 0, b = 1;  // F(0), F(1)
    long long result = 0;

    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return b;
}

int main() {
    int n;
    cout << "n 입력: ";
    cin >> n;

    cout << n << "번째 피보나치 수: " << fib(n) << endl;
    return 0;
}