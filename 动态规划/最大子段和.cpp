#include <iostream>
using namespace std;

// �������������͵ĺ���
int MaxSum(int *a, int n) {
    int b = 0, sum = 0;
    for (int i = 0; i < n; i++) {  
        if (b > 0)
            b += a[i];
        else
            b = a[i];
        if (b > sum)
            sum = b;
    }
    return sum;
}
int main() {
    int n;
    cout << "����������Ԫ�ظ���: ";
    cin >> n;
    int *a = new int[n];
    cout << "����������Ԫ��: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int result = MaxSum(a, n);
    cout << "����������Ϊ: " << result << endl;
    delete[] a;  // �ͷŶ�̬����������ڴ�
    return 0;
}
