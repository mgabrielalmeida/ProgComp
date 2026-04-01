#include <bits/stdc++.h>
using namespace std;

int soma_digitos(int x) {
    int soma = 0;
    while (x > 0) {
        soma += x % 10;
        x /= 10;
    }
    return soma;
}

int main() {
    int N, M, S;
    cin >> N >> M >> S;

    for (int i = M; i >= N; i--) {
        if (soma_digitos(i) == S) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}