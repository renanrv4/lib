// Retorna a posição da primeira folha que satisfaz a condição.
// Retorne -1 caso não exista resposta.
int walk(int l, int r, int idx = 0) {

    // --------------------------------------------------
    // CASO 1:
    // Este segmento não pode conter uma resposta.
    //
    // Exemplos:
    // - seg[idx] <= H
    // - r < start
    // - soma do segmento < K
    // --------------------------------------------------
    if(/* segmento impossível */) {
        return -1;
    }

    // --------------------------------------------------
    // CASO 2:
    // Chegamos em uma folha.
    //
    // Como os casos impossíveis já foram filtrados,
    // esta folha é a resposta.
    // --------------------------------------------------
    if(l == r) {
        return l;
    }

    int mid = (l + r) / 2;

    // --------------------------------------------------
    // CASO 3:
    // Tenta encontrar a resposta no filho esquerdo.
    // --------------------------------------------------
    int ans = walk(l, mid, 2*idx + 1);

    // --------------------------------------------------
    // CASO 4:
    // Se encontrou no esquerdo, retorna.
    // --------------------------------------------------
    if(ans != -1) {
        return ans;
    }

    // --------------------------------------------------
    // CASO 5:
    // Caso contrário, procura no direito.
    // --------------------------------------------------
    return walk(mid + 1, r, 2*idx + 2);
}
