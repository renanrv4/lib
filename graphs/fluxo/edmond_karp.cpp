#include <bits/stdc++.h>

using namespace std;

#define MAXV 100

// Variáveis Globais (Capacidades, fluxo máximo, fluxo, source edge, terminal edge)
int res[MAXV][MAXV], mf, f, s, t;
vector<int> p; // Vetor de parents

// Função para alterar o fluxo com base no caminho encontrado pela BFS
// Aumenta backedges e diminui forward edges
void augment(int v, int minEdge) {
    if(v == s) { f = minEdge; return; }
    else if(p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

// MinEdge é a menor capacidade encontrada (gargalo)

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n;
    int net = 1;
    while(cin >> n, n != 0) {
        int c; cin >> s >> t >> c;
        s--; t--;
        memset(res, 0, sizeof(res));
        for(int i = 0; i < c; i++) {
            int a, b, wid; cin >> a >> b >> wid;
            a--; b--;
            res[a][b] += wid;
            res[b][a] += wid;
        }
        mf = 0;
        while(1) {
            f = 0;
            vector<int> dist(MAXV, INT_MAX); dist[s] = 0;
            queue<int> queue_visit; queue_visit.push(s);
            p.assign(MAXV, -1);
            while(!queue_visit.empty()) {
                int v = queue_visit.front(); queue_visit.pop();
                if(v == t) {
                    break;
                }
                for(int u = 0; u < MAXV; u++) {
                    if(res[v][u] > 0 && dist[u] == INT_MAX) {
                        dist[u] = dist[v] + 1, queue_visit.push(u), p[u] = v;
                    }
                }
            }
            augment(t, INT_MAX);
            if(f == 0) {
                break;
            }
            mf += f;
        }
        cout << mf << ".\n\n";
    }
    return 0;
}