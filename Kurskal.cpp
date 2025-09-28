#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

// ���� ���ķ� ���� ���� (����ġ ����)
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
            parent[x] = find(parent[x]); // ��� ����
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false; // ����Ŭ �߻�
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
    int V = 5; // ���� ����
    vector<Edge> edges;

    // ���� �߰� (u, v, w)
    edges.push_back({ 0, 1, 10 });
    edges.push_back({ 0, 2, 5 });
    edges.push_back({ 1, 3, 2 });
    edges.push_back({ 2, 3, 7 });
    edges.push_back({ 3, 4, 1 });

    // 1. �������� ����ġ ���� ���� (���� ����)
    bubbleSort(edges);

    DSU dsu(V);
    vector<Edge> mst;

    // 2. ���� ����ġ �������� ����
    for (auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
        }
    }

    // 3. ��� ���
    cout << "MST ������:\n";
    for (auto& e : mst) {
        cout << e.u << " - " << e.v << " (����ġ " << e.w << ")\n";
    }

    return 0;
}