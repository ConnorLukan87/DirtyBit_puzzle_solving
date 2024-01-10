#include <iostream>
#include <vector>

struct Graph {
    std::vector<bool> visited;
    std::vector<std::vector<bool>> adj_lists;
    int N;

    Graph(int N) // n many friends
    {
        this->N = N;
        adj_lists = std::vector<std::vector<bool>>(N, std::vector<bool>(N, false));
        visited = std::vector<bool>(N, false);
    }

    void add_edge(int a, int b)
    {
        adj_lists[a][b] = true;
        adj_lists[b][a] = true;
    }

    void reset()
    {
        visited = std::vector<bool>(N, false);
    }

    void remove_edge(int a, int b)
    {
        adj_lists[a][b] = false;
        adj_lists[b][a] = false;
    }
};

void DFS(int current, Graph& g)
{
    g.visited[current] = true;
    for (int i = 0 ; i < g.N; i++)
    {
        if (i != current && !g.visited[i] && g.adj_lists[current][i])
        {
            DFS(i, g);
        }
    }
}

int main()
{
    int p, c;
    int from, to;
    while (true)
    {
        std::cin >> p >> c;
        if (c == 0 && p == 0)
        {
            return 0;
        }
        Graph g(p);
        // build graph
        std::vector<std::pair<int,int>> edges;
        for (int edge_i = 0 ; edge_i < c ; edge_i++)
        {
            std::cin >> from >> to;
            g.add_edge(from, to);
            edges.push_back(std::make_pair(from, to));
        }

        bool possible = false;
        for (std::pair<int,int> edge : edges)
        {
            g.remove_edge(edge.first, edge.second);

            DFS(0, g);
            for (bool partier : g.visited)
            {
                if (!partier)
                {
                    possible = true;
                }
            }
            g.add_edge(edge.first, edge.second);
            g.reset();
            if (possible)
                break;
        }

        std::cout << (possible ? "Yes" : "No") << std::endl;

    }
}
