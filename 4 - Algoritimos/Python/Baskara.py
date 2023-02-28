# coding: utf-8
from math import pow, sqrt

# Entrada de Valores
print('Digite os valores de a, b e c, respectivamente. (ax^2 + bx + c = 0)')
a = int(input('A: '))
b = int(input('B: '))
c = int(input('C: '))

# Cálculo do delta
delta = pow(b, 2) - 4 * a * c

# Se delta for negativo
if delta < 0:
    print('Não há raizes dentro do conjunto dos Reais.')

# Se delta for igual a 0
elif delta == 0:
    print('As duas raizes possuem o mesmo valor.')
    x = -b / 2 * a
    print('X = {}'.format(x))

# Se delta for positivo
else:
    print('As raizes possuem valores distintos.')
    x1 = (-b + sqrt(delta)) / 2 * a
    x2 = (-b - sqrt(delta)) / 2 * a
    print('X\' = {} e X\" = {}'.format(x1, x2))

print('Fim do algoritmo.')
