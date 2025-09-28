#include <iostream>
using namespace std;

void makeChange(int money) {
    int coins[4] = { 500, 100, 50, 10 };  
    int count[4] = { 0 };                 // 각 동전 개수 저장용 배열

    for (int i = 0; i < 4; i++) {
        count[i] = money / coins[i];   // 해당 동전 몇 개 필요한지
        money %= coins[i];             // 남은 돈 갱신
    }

    cout << "거스름돈 구성:" << endl;
    for (int i = 0; i < 4; i++) {
        if (count[i] > 0) {
            cout << coins[i] << "원: " << count[i] << "개" << endl;
        }
    }
}

int main() {
    int money;
    cout << "거스름돈 입력: ";
    cin >> money;
    makeChange(money);
    return 0;
}