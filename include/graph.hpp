#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

template<class T>
struct Edge
{
    T to;
    T cost;

    Edge(T to, T cost) :
        to{ to },
        cost{ cost }
    {}
};

template<class T>
using WeightedGraph = vector<vector<Edge<T>>>;

/*!
@fn dijkstra
@brief 重み付き有向グラフにおける単一始点sからの最短路を計算する
*/
template<class T>
vector<T> dijkstra(T s, const WeightedGraph<T>& g)
{
    const auto INF = numeric_limits<T>::max();
    vector<T> d(g.size(), INF);

    using P = pair<T, T>;
    priority_queue<P, vector<P>, greater<P>> que;

    d[s] = 0;
    que.emplace(d[s], s);

    while (!que.empty()) {
        P p = que.top();
        que.pop();

        T v = p.second;

        if (d[v] < p.first) {
            continue;
        }

        for (const auto& e : g[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.emplace(d[e.to], e.to);
            }
        }
    }

    return d;
}

/*!
@fn warshall_floyd
@brief 重み付き有向グラフにおける全点対間最短路を計算する
*/
template<class T>
vector<vector<T>> warshall_floyd(const WeightedGraph<T>& g)
{
    const auto INF = numeric_limits<T>::max();
    vector<vector<T>> d(g.size(), vector<T>(g.size(), INF));

    for (size_t i = 0; i < g.size(); ++i) {
        d[i][i] = 0;
    }

    for (size_t i = 0; i < g.size(); ++i) {
        for (const auto& e : g[i]) {
            d[i][e.to] = e.cost;
        }
    }

    for (size_t k = 0; k < g.size(); ++k) {
        for (size_t i = 0; i < g.size(); ++i) {
            for (size_t j = 0; j < g.size(); ++j) {
                if (d[i][k] == INF || d[k][j] == INF) {
                    continue;
                }
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    return d;
}

#endif
