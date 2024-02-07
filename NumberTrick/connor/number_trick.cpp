//
// Created by Connor Lukan on 2/7/24.
//
#include <iostream>
#include <vector>

typedef long long int ll;

ll gcd(ll n, ll d)
{
    return d == 0 ? n : gcd(d, n % d);
}


int first_digit_of(ll k)
{
    while (k / 10 > 0)
    {
        k /= 10;
    }
    return k;
}

int number_of_digits(ll k)
{
    int num_digits = 0;
    while (k / 10 > 0)
    {
        k /= 10;
        num_digits++;
    }
    return num_digits+1;
}

int main()
{

    double x;
    std::cin >> x;

    //for (double x = 1.01; x < 10.0; x+=0.01) {
        //std::cout << "x=" << x << std::endl;
        if (x >= 10.0) {
            std::cout << "No solution";
            return 0;
        }
        double x_prime = 10.0 - x;

        // put as fraction
        ll n_xprime = 10000 * x_prime;
        ll d_xprime = 10000;
        ll k;
        if (n_xprime > d_xprime) {
            k = gcd(n_xprime, d_xprime);
        } else {
            k = gcd(d_xprime, n_xprime);
        }

        n_xprime /= k;
        d_xprime /= k;

        std::vector<ll> good_numbers;

        int nines = 9;
        for (int digits = 1; digits <= 8; digits++) {
            for (int first_digit = 1; first_digit <= 9; first_digit++) {
                ll numerator = first_digit * d_xprime * nines;
                if (numerator % n_xprime == 0 && first_digit_of(numerator / n_xprime) == first_digit && number_of_digits(numerator/n_xprime) == digits) {
                    good_numbers.push_back(numerator / n_xprime);
                }
            }
            nines = (nines * 10) + 9;
        }

        if (good_numbers.size() == 0) {
            std::cout << "No solution" << std::endl;
        } else {
            for (ll number: good_numbers) {
                std::cout << number << std::endl;
            }
        }
//}
}
