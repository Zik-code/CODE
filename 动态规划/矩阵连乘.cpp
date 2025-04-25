#include <iostream>
#include <sstream>
using namespace std;

// 计算矩阵链乘法最优代价和记录分割点
// p是一个数组，存储矩阵链中每个矩阵的行数和列数（第一个矩阵的行数、后续矩阵的列数）
// n是矩阵链中矩阵的数量
// m是一个二维数组，用于存储矩阵链乘法的最优代价
// s是一个二维数组，用于记录在最优代价下矩阵链的分割点
void MatrixChain(int *p, int n, int **m, int **s) {
    // 初始化对角线元素，单个矩阵相乘代价为0
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    // r表示矩阵链的长度，从2开始（因为单个矩阵已初始化）
    for (int r = 2; r <= n; r++) {
        // i是矩阵链起始位置
        for (int i = 1; i <= n - r + 1; i++) {
            // j是矩阵链结束位置
            int j = i + r - 1;
            // 先假设一种划分方式（从i和i+1处划分），计算代价并记录分割点
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            // 尝试其他划分方式，k为分割点
            for (int k = i + 1; k < j; k++) {
                // 计算当前划分方式的代价
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                // 如果当前划分方式代价更小，则更新最优代价和分割点
                if (t < m[i][j]) {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

// 追溯矩阵链乘法的加括号顺序并生成括号形式字符串
// i是矩阵链起始位置
// j是矩阵链结束位置
// s是记录分割点的二维数组
string Traceback(int i, int j, int **s) {
    // 如果起始和结束位置相同，即单个矩阵，直接返回矩阵名称
    if (i == j) {
        ostringstream oss;
        oss << "U" << i;
        return oss.str();
    }
    // 递归获取左子链的括号形式字符串
    string left = Traceback(i, s[i][j], s);
    // 递归获取右子链的括号形式字符串
    string right = Traceback(s[i][j] + 1, j, s);
    ostringstream oss;
    // 将左右子链的括号形式字符串组合起来，形成当前矩阵链的括号形式字符串
    oss << "(" << left << right << ")";
    return oss.str();
}

// 输出正确格式的乘法顺序
// s是记录分割点的二维数组
// i是矩阵链起始位置
// j是矩阵链结束位置
void PrintOptimalParens(int **s, int i, int j) {
    // 如果起始和结束位置相同，即单个矩阵，直接输出矩阵名称
    if (i == j) {
        cout << "U" << i;
        return;
    }
    // 输出左括号，表示开始计算当前矩阵链
    cout << "(";
    // 递归输出左子链的乘法顺序
    PrintOptimalParens(s, i, s[i][j]);
    // 递归输出右子链的乘法顺序
    PrintOptimalParens(s, s[i][j] + 1, j);
    // 输出右括号，表示当前矩阵链计算结束
    cout << ")";
}

int main() {
    // 定义数组p，存储矩阵链中每个矩阵的行数和列数
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    // 矩阵链中矩阵的数量
    int n = 6;
    // 动态分配二维数组m，用于存储矩阵链乘法的最优代价
    int **m = new int*[n + 1];
    // 动态分配二维数组s，用于记录在最优代价下矩阵链的分割点
    int **s = new int*[n + 1];
    // 为二维数组m的每一行分配内存
    for (int i = 0; i <= n; i++) {
        m[i] = new int[n + 1];
    }
    // 为二维数组s的每一行分配内存
    for (int i = 0; i <= n; i++) {
        s[i] = new int[n + 1];
    }

    // 调用MatrixChain函数，计算矩阵链乘法的最优代价和分割点
    MatrixChain(p, n, m, s);

    // 调用Traceback函数，获取括号形式结果并输出
    string parenForm = Traceback(1, n, s);
    cout << "括号形式: " << parenForm << endl;

    // 输出最少连乘次数
    cout << "最少连乘次数: " << m[1][n] << endl;

    // 释放二维数组m动态分配的内存
    for (int i = 0; i <= n; i++) {
        delete[] m[i];
    }
    delete[] m;
    // 释放二维数组s动态分配的内存
    for (int i = 0; i <= n; i++) {
        delete[] s[i];
    }
    delete[] s;

    return 0;
}