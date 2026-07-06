import numpy as np
import matplotlib.pyplot as plt

# 1. Parâmetros do Problema
h = 0.1
N = 10
# O vetor x vai de x_0 a x_10 (11 pontos)
x = np.linspace(0, 1, N + 1)

# Condições de Contorno
y0_val = 5.0
dy1_val = 8.0

# 2. Inicialização da Matriz K (10x10) e do Vetor b (10x1)
# O índice da matriz vai de 0 a 9, correspondendo às incógnitas y_1 até y_10
K = np.zeros((N, N))
b = np.zeros(N)

# 3. Preenchimento do Sistema
# Equação para o nó i=1 (índice 0 nos arrays)
K[0, 0] = -11.91
K[0, 1] = 6.35
b[0] = 0.05 * np.exp(-x[1]) - 5.65 * y0_val

# Equações para os nós internos i=2 até i=9 (índices 1 a 8 nos arrays)
for i in range(1, N - 1):
    K[i, i-1] = 5.65
    K[i, i]   = -11.91
    K[i, i+1] = 6.35
    b[i]      = 0.05 * np.exp(-x[i+1]) # x[i+1] porque o índice de 'x' inclui o x_0

# Equação para o nó i=10 contorno de Neumann (índice 9 nos arrays)
# Relação do nó fantasma: y_11 = y_9 + 2h * 8 = y_9 + 1.6
K[N-1, N-2] = 5.65 + 6.35  # que resulta em 12.0
K[N-1, N-1] = -11.91
b[N-1] = 0.05 * np.exp(-x[N]) - 6.35 * (2 * h * dy1_val)

# 4. Resolução Numérica do Sistema Linear
y_incognitas = np.linalg.solve(K, b)

# 5. Montagem do Vetor de Solução Final
# Concatenamos o valor conhecido y0 com os valores calculados
y_solucao = np.concatenate(([y0_val], y_incognitas))

# 6. Plotagem dos Resultados
plt.figure(figsize=(8, 5))
plt.plot(x, y_solucao, 'bo-', linewidth=2, label='Aproximação FDM (h=0.1)')
plt.title('Solução Numérica do Problema de Valor de Contorno')
plt.xlabel('x')
plt.ylabel('y(x)')
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend()
plt.show()

# Opcional: imprimir os valores para verificação
print("Valores de y(x):")
for i in range(len(x)):
    print(f"x_{i} = {x[i]:.1f} \t y_{i} = {y_solucao[i]:.4f}")