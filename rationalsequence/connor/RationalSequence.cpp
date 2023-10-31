//
// Created by Connor Lukan on 10/27/23.
//
#include <iostream>

int main()
{

    int K, n, d, c;
    std::cin >> K;
    std::string noverd;

    for (int i = 0; i < K; i++)
    {
        std::cin >> c >> noverd;
        n = 0;
        int idx = 0;
        while (noverd[idx] != '/')
        {
            n*= 10;
            n += noverd[idx++] - '0';
        }
        d = 0;
        for (int j = idx + 1; j < noverd.size(); j++)
        {
            d*=10;
            d += noverd[j] - '0';
        }


        int steps_down = 0;
        if (n==1 && d == 1) // case that input is 1/1, just go left
        {
            d += n;
        }
        else if (n >= d)
        {

            if (n==1) // it's a far right node
            {
                steps_down = n;
            }
            else
            {

              // walk up the tree until the current node is a right child
              //  get the parent of that child
              // go right one
              // walk all the way left down the tree the same amount of steps taken walking up
                steps_down = n/d;
                n -= d*steps_down;
                d -= n;
                n += d;
                // walk down steps_down many
                // int d_next;
                d += steps_down*n;
            }
         
        }
        else // its the left child of something
        {
            // go up one, then down one
            d -= n;
            n += d;
        }

        std::cout << c << " " << n << "/" << d << std::endl;

    }
}
