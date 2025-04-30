//问题描述：给定不同面额的硬币 coins 和一个总金额 amount，计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
解题思路：创建一个长度为 amount + 1 的数组 dp，dp[i] 表示凑成金额 i 所需的最少硬币数。初始时，dp[0] 为 0，其余元素为正无穷。遍历每种硬币，对于每个金额 x，更新 dp[x] 为 dp[x] 和 dp[x - coin] + 1 中的较小值。
#代码解释
1. **零钱兑换**：
    - **问题描述**：给定不同面额的硬币 `coins` 和一个总金额 `amount`，计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
    - **解题思路**：创建一个长度为 `amount + 1` 的数组 `dp`，`dp[i]` 表示凑成金额 `i` 所需的最少硬币数。初始时，`dp[0]` 为 0，其余元素为正无穷。遍历每种硬币，对于每个金额 `x`，更新 `dp[x]` 为 `dp[x]` 和 `dp[x - coin] + 1` 中的较小值。
2. **打家劫舍**：
    - **问题描述**：你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。给定一个代表每个房屋存放金额的非负整数数组，计算你不触动警报装置的情况下，一夜之内能够偷窃到的最高金额。
    - **解题思路**：创建一个数组 `dp`，`dp[i]` 表示前 `i` 个房屋能偷到的最大金额。对于第 `i` 个房屋，有两种选择：偷或不偷。状态转移方程为 `dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])`。 


def coin_change(coins, amount):
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0

    for coin in coins:
        for x in range(coin, amount + 1):
            dp[x] = min(dp[x], dp[x - coin] + 1)

    return dp[amount] if dp[amount] != float('inf') else -1


# 测试
coins = [1, 2, 5]
amount = 11
print(f"兑换 {amount} 所需的最少硬币数为: {coin_change(coins, amount)}")
    



def house_robber(nums):
    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]

    dp = [0] * len(nums)
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])

    for i in range(2, len(nums)):
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])

    return dp[-1]


# 测试
nums = [1, 2, 3, 1]
print(f"能抢到的最大金额为: {house_robber(nums)}")
    