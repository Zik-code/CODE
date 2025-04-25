#include <iostream>
#include <cstring>
using namespace std;

// 最长公共子序列函数
void LCS(char* x, char* y, int m, int n, int** c, int** b) {
    int i, j;
    // 初始化第一行和第一列为 0
    for (i = 0; i <= m; i++) {
        c[i][0] = 0;
    }
    for (j = 0; j <= n; j++) {
        c[0][j] = 0;
    }
    // 填充 c 和 b 数组
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }
        }
    }
}

// 输出最长公共子序列
void printLCS(int** b, char* x, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (b[i][j] == 1) {
        printLCS(b, x, i - 1, j - 1);
        cout << x[i - 1];
    } else if (b[i][j] == 2) {
        printLCS(b, x, i - 1, j);
    } else {
        printLCS(b, x, i, j - 1);
    }
}

// 打印 C 数组表格
void printCTable(int** c, int m, int n) {
    cout << "C 数组求解表格：" << endl;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

// 打印 b 数组表格
void printBTable(int** b, char* x, char* y, int m, int n) {
    cout << "b 数组求解表格：" << endl;
    // 打印列首字母
    cout << " ";
    for (int j = 0; j < n; j++) {
        cout << " " << y[j] << " ";
    }
    cout << endl;

    for (int i = 0; i <= m; i++) {
        if (i > 0) {
            cout << x[i - 1];
        } else {
            cout << " ";
        }
        for (int j = 0; j <= n; j++) {
            if (b[i][j] == 1) {
                cout << " 1 ";
            } else if (b[i][j] == 2) {
                cout << " 2 ";
            } else if (b[i][j] == 3) {
                cout << " 3 ";
            } else {
                cout << "   ";
            }
        }
        cout << endl;
    }
}

int main() {
    char x[100];
    char y[100];
    cout << "请输入X：";
    cin >> x;
    cout << "请输入Y：";
    cin >> y;
    int m = strlen(x);
    int n = strlen(y);

    // 动态分配 c 和 b 数组
    int** c = new int*[m + 1];
    int** b = new int*[m + 1];
    for (int i = 0; i <= m; i++) {
        c[i] = new int[n + 1];
        b[i] = new int[n + 1];
    }

    // 调用 LCS 函数
    LCS(x, y, m, n, c, b);

    // 输出最长公共子序列长度
    cout << endl;
    cout << "最长公共子序列长度是: " << c[m][n] << endl;
	cout << endl;
    // 打印 C 数组表格
    printCTable(c, m, n);

    // 打印 b 数组表格
    printBTable(b, x, y, m, n);

    // 输出最长公共子序列
    cout << "最长公共子序列是: ";
    printLCS(b, x, m, n);
    cout << endl;

    // 释放动态分配的内存
    for (int i = 0; i <= m; i++) {
        delete[] c[i];
        delete[] b[i];
    }
    delete[] c;
    delete[] b;

    return 0;
}    