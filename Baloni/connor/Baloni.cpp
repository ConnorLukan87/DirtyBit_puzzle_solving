//
// Created by Connor Lukan on 1/10/24.
//

#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<bool> popped(N, false);

    std::vector<int> H(N);
    for (int i = 0 ; i < N; i++)
    {
        std::cin >> H[i];
    }

    int count = 0;
    for (int x_i = 0 ; x_i < N; x_i++)
    {
        if (!popped[x_i])
        {
            popped[x_i] = true;
            count++;
            // find a decreasing continuous sequence of unpopped balloons after x_i
            int height = H[x_i] - 1;
            for (int x_j = x_i +1; x_j < N && height > 0; x_j++)
            {
                if (H[x_j] == height && !popped[x_j])
                {
                    popped[x_j] = true;
                    height--;
                }
            }
        }
    }
    std::cout << count << std::endl;
}
