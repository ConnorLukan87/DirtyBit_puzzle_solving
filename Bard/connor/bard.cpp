#include <iostream>
#include <vector>
#include <unordered_set>

struct Villager {
    std::unordered_set<int> songs_known;

    Villager() {}
};

int main() {

    int N;
    std::cin >> N;
    // village 1 is the bard

    int E;
    std::cin >> E;
    // number of evenings

    int nights_with_bard = 0;
    std::vector<Villager> villagers(N);

    for (int evening_i = 0; evening_i < E ; evening_i++)
    {
        int K;
        std::cin >> K;
        std::unordered_set<int> villagers_here;
        int villager;
        for (int i = 0; i < K; i++)
        {
            std::cin >> villager;
            villagers_here.insert(villager);
        }

        if (villagers_here.find(1) == villagers_here.end()) // no bard
        {
            // exchange all songs known
            // find the union set, then distribute among all villagers here
            std::unordered_set<int> all_songs_known;
            for (int villager_here : villagers_here)
            {
                for (int song : villagers[villager_here-1].songs_known)
                {
                    all_songs_known.insert(song);
                }
            }

            for (int song : all_songs_known)
            {
                for (int villager : villagers_here)
                {
                    villagers[villager-1].songs_known.insert(song);
                }
            }

        }
        else // the bard was here to sing
        {
            nights_with_bard++;
            for (int villager_here : villagers_here) // inser the song heard at eveining i
            {
                villagers[villager_here-1].songs_known.insert(evening_i);
            }
        }


    }

    // find the set of all villagers that know as many songs as there were nights with the bard

    for (int i =0; i < N; i++)
    {
        if (villagers[i].songs_known.size() == nights_with_bard)
        {
            std::cout << (i+1) << std::endl;
        }
    }
    return 0;
}
