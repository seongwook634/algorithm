#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

// 버블 정렬로 간선 정렬 (가중치 기준)
void bubbleSort(vector<Edge>& edges) {
    int n = edges.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Union-Find (Disjoint Set Union)
struct DSU {
    vector<int> parent, rank;

    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // 경로 압축
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false; // 사이클 발생
        if (rank[a] < rank[b]) {
            parent[a] = b;
        }
        else if (rank[a] > rank[b]) {
            parent[b] = a;
        }
        else {
            parent[b] = a;
            rank[a]++;
        }
        return true;
    }
};

int main() {
    int V = 5; // 정점 개수
    vector<Edge> edges;

    // 간선 추가 (u, v, w)
    edges.push_back({ 0, 1, 10 });
    edges.push_back({ 0, 2, 5 });
    edges.push_back({ 1, 3, 2 });
    edges.push_back({ 2, 3, 7 });
    edges.push_back({ 3, 4, 1 });

    // 1. 간선들을 가중치 기준 정렬 (직접 구현)
    bubbleSort(edges);

    DSU dsu(V);
    vector<Edge> mst;

    // 2. 작은 가중치 간선부터 선택
    for (auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
        }
    }

    // 3. 결과 출력
    cout << "MST 간선들:\n";
    for (auto& e : mst) {
        cout << e.u << " - " << e.v << " (가중치 " << e.w << ")\n";
    }

    return 0;
}