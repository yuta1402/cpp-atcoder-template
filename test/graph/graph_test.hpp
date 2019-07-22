#include "test.hpp"
#include "graph.hpp"

void dijkstra_test()
{
    WeightedGraph<int> g(4);

    g[0].emplace_back(1, 1);
    g[1].emplace_back(0, 1);

    g[1].emplace_back(2, 1);
    g[2].emplace_back(1, 1);

    g[2].emplace_back(3, 1);
    g[3].emplace_back(2, 1);

    g[3].emplace_back(0, 1);
    g[0].emplace_back(3, 1);

    auto d = dijkstra(0, g);

    eassert(d[0] == 0, "d[0] == %d", d[0]);
    eassert(d[1] == 1, "d[1] == %d", d[1]);
    eassert(d[2] == 2, "d[2] == %d", d[2]);
    eassert(d[3] == 1, "d[3] == %d", d[3]);
}

void graph_test()
{
    dijkstra_test();
}
