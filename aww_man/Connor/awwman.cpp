#include <iostream>
typedef long long int ll;

int main()
{
    int T;
    ll N, M, a, b, d;
    std::cin >> T;
    for (int trip_i = 0 ; trip_i < T; trip_i++)
    {
        std::cin >> N >> M >> a >> b >> d;
        ll travel_length = a < b ? b - a : N + b - a;
        ll t = b - 1;
        t = (t + d) % N;
        t = (t + travel_length) % N;
        if (t >= N-M && t <= N-1)
        {
            std::cout << "NO\n";
        }
        else
        {
            std::cout << "YES\n";
        }
    }

}
