#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef long long int ll;

class comparison {
public:
    bool operator()(std::pair<ll,ll>& c1, std::pair<ll,ll>& c2)
    {
        return c1.first + c1.second > c2.first + c2.second;
    }

};

int main() {
    int h, c;
    std::cin >> h >> c;
    std::priority_queue<std::pair<ll,ll>, std::vector<std::pair<ll,ll>>, comparison> coworkers;
    ll max_annoyance = 0;
    for (int i = 0; i < c ; i++)
    {
        std::pair<ll,ll> worker;
        std::cin >> worker.first >> worker.second;
        coworkers.push(worker);
        if (worker.first > max_annoyance)
        {
            max_annoyance = worker.first;
        }
    }

    for (int i = 0 ; i < h ; i++)
    {
        auto front = coworkers.top();
        coworkers.pop();
        front.first += front.second;
        if (front.first > max_annoyance)
        {
            max_annoyance = front.first;
        }
        coworkers.push(front);
    }

    std::cout << max_annoyance;
    return 0;
}
