def matrix_chain_multiplication(p):
    n = len(p) - 1
    dp = [[0] * n for _ in range(n)]
    for l in range(2, n + 1):
        for i in range(n - l + 1):
            j = i + l - 1
            dp[i][j] = float('inf')
            for k in range(i, j):
                q = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1]
                if q < dp[i][j]:
                    dp[i][j] = q
    return dp[0][n - 1]


# 测试
p = [30, 35, 15, 5, 10, 20, 25]
print(f"矩阵链乘法的最少乘法次数为: {matrix_chain_multiplication(p)}")
    