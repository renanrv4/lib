pair<int, int> floyd_cycle(int x0) {
    int tortoise = f(x0);
    int hare = f(f(x0));
    // Encontrar ponto em que se encontram
    while(tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
    // Encontrar começo do ciclo
    int mu = 0; hare = x0;
    while(tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }
    // Encontrar tamanho do ciclo
    int lambda = 1; hare = f(tortoise);
    while(tortoise != hare) {
        hare = f(hare); lambda++;
    }
    return {mu, lambda};
}

// Algoritmo de floy para encontrar ciclos de forma eficiente