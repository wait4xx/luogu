//
// Created by XX on 2025/02/15.
//

#include <stdio.h>

#define MAX_SIZE 100

long long count_paths(int n, int m, int horse_x, int horse_y);
int main() 
{
    int x = 0, y = 0;
    int m = 0, n = 0;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    printf("%lld\n", count_paths(n, m, x, y));
    return 0;
}

long long count_paths(int n, int m, int horse_x, int horse_y) 
{
    long long dp[MAX_SIZE][MAX_SIZE] = {0};
    
    // 检查起点是否被马控制或为马的位置
    int start_dist = horse_x * horse_x + horse_y * horse_y;
    if (start_dist == 5 || start_dist == 0) {
        return 0;
    }

    dp[0][0] = 1; // 起点
    
    for (int i = 0; i <= n; ++i) 
    {
        for (int j = 0; j <= m; ++j) 
        {
            int distance = (i - horse_x) * (i - horse_x) + (j - horse_y) * (j - horse_y);
            if (distance == 5 || distance == 0) 
            {
                dp[i][j] = 0; // 显式设置为0
                continue; // 如果是控制点，则跳过
            }
            if (i > 0) dp[i][j] += dp[i-1][j]; // 向下走来的路径数
            if (j > 0) dp[i][j] += dp[i][j-1]; // 向右走来的路径数
        }
    }
    
    return dp[n][m];
}