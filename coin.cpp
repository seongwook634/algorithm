#include <iostream>
using namespace std;

void makeChange(int money) {
    int coins[4] = { 500, 100, 50, 10 };  
    int count[4] = { 0 };                 // �� ���� ���� ����� �迭

    for (int i = 0; i < 4; i++) {
        count[i] = money / coins[i];   // �ش� ���� �� �� �ʿ�����
        money %= coins[i];             // ���� �� ����
    }

    cout << "�Ž����� ����:" << endl;
    for (int i = 0; i < 4; i++) {
        if (count[i] > 0) {
            cout << coins[i] << "��: " << count[i] << "��" << endl;
        }
    }
}

int main() {
    int money;
    cout << "�Ž����� �Է�: ";
    cin >> money;
    makeChange(money);
    return 0;
}