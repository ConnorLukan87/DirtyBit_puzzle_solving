//
// Created by connputer on 11/26/23.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

struct Node
{
    std::pair<int,int> coord;
    std::vector<Node*> next_available;
    bool visited = false;
    char symbol;
    Node() {

    }

    Node(int x, int y)
    {
        coord = std::make_pair(x,y);
    }
};

int main()
{
    int R, C;
    std::cin >> R >> C;

    Node** map = new Node*[R];

    std::unordered_map<char, std::vector<Node*>> symbol_to_portals;
    Node* start = nullptr;

    for (int r = 0; r < R; r++)
    {
        map[r] = new Node[C];
        for (int c = 0 ; c < C; c++)
        {
            map[r][c].coord = std::make_pair(r,c);
            std::cin >> map[r][c].symbol;

            if (map[r][c].symbol == 'S')
            {
                start = &map[r][c];
            }
            else if (map[r][c].symbol <= 'z' && 'a' <= map[r][c].symbol)
            {
                symbol_to_portals[map[r][c].symbol].push_back(&map[r][c]);
            }
            // if its a portal push it back in this symbols portal vector


        }
    }


    for (int r = 0 ; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (map[r][c].symbol <= 'z' && 'a' <= map[r][c].symbol)
            {
                for (Node* portal_out : symbol_to_portals[map[r][c].symbol])
                {
                    map[r][c].next_available.push_back(portal_out);
                }
            }

            if (r != R-1 && map[r+1][c].symbol != '#')
            {
                map[r][c].next_available.push_back(&map[r+1][c]);
            }

            if (c != C-1 && map[r][c+1].symbol != '#')
            {
                map[r][c].next_available.push_back(&map[r][c+1]);
            }

            if (r!=0 && map[r-1][c].symbol != '#')
            {
                map[r][c].next_available.push_back(&map[r-1][c]);
            }

            if (c!=0 && map[r][c-1].symbol != '#')
            {
                map[r][c].next_available.push_back(&map[r][c-1]);
            }

        }
    }


    std::queue<Node*> current_step;
    current_step.push(start);
    start->visited=true;
    int t = 0;

    int in_q = 1;
    int just_enqueued;
    while (in_q != 0)
    {
        just_enqueued = 0;
        for (int i=0; i < in_q; i++)
        {
            Node* c = current_step.front();
            current_step.pop();
            if (c->symbol == 'E')
            {
                for (int k= 0; k< R; k++)
                {
                    delete[] map[k];
                }
                delete[] map;
                std::cout << t << std::endl;
                return 0;
            }

            for (Node* a : c->next_available)
            {
                if (!a->visited)
                {
                    current_step.push(a);
                    just_enqueued++;
                    a->visited = true;
                }
            }
        }


        in_q = just_enqueued;
        t++;
    }


    // CLEAN UP
    for (int i= 0; i < R; i++)
    {
        delete[] map[i];
    }
    delete[] map;

    std::cout << -1 << std::endl;
    return 0;
}
