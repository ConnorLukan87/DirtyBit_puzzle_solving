#include <iostream>
#include <vector>

std::vector<std::vector<std::vector<int>>> dp;

bool can_lay(int current, int c_1_left, int c_2_left, int c_3_left, const int& end, const std::vector<bool>& has_end_at)
{
    if (current == end)
    {
        return true;
    }
    else if (current > end)
    {
        return false;
    }

    if (dp[current][c_1_left][c_2_left] != -1)
    {
        return dp[current][c_1_left][c_2_left];
    }

    bool cond1 = false, cond2 = false, cond3 = false;
    cond1 = (c_1_left > 0) && (!has_end_at[current + 1]) && can_lay(current+1, c_1_left-1, c_2_left, c_3_left, end, has_end_at);
    cond2 = (c_2_left > 0) && !has_end_at[current+2] && can_lay(current+2, c_1_left, c_2_left-1, c_3_left, end, has_end_at);
    cond3 = (c_3_left > 0) && (!has_end_at[current+3]) && can_lay(current+3, c_1_left, c_2_left, c_3_left-1, end, has_end_at);

    dp[current][c_1_left][c_2_left] = (cond1 || cond2 || cond3) ? 1 : 0;
    return dp[current][c_1_left][c_2_left];
}

int main()
{
    int N;
    std::cin >> N;
    int c_1, c_2, c_3;
    std::cin >> c_1 >> c_2 >> c_3;

    std::vector<int> bricks(N);
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> bricks[i];
        sum += bricks[i];
    }

    std::vector<bool> has_end_at(sum+1, false);
    int current = 0;
    for (int brick_l : bricks)
    {
        current += brick_l;
        has_end_at[current] = true;
    }

    dp.assign(sum + 1, std::vector<std::vector<int>>(c_1 + 1, std::vector<int>(c_2 + 1, -1)));
    has_end_at[sum] = false;
    int start = 0;
    int next_start = sum;

    std::cout << (can_lay(start, c_1, c_2, c_3, sum, has_end_at) ? "YES" : "NO") << std::endl;

    return 0;
}
