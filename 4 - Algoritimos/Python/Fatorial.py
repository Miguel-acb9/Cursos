# coding: utf-8

# Declaração de Variáveis
fatorial = 1

# Entrada de Valores
x = int(input('Fatoral de: '))

for i in range(0, x):
    fatorial *= i

print(fatorial)