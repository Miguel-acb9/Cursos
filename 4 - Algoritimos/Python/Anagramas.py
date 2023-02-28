# coding: utf-8
from math import factorial

# Função Principal
def principal():
    palavra = str(input('Digite uma palavra: '))
    total_anagramas(palavra)
    a = str(input('Voçe deseja mostrar todos os anagramas possíveis? [s/n] ')).lower()
    if a == 's':
        criar_anagramas(palavra)

# Função Mostra o total de anagramas possíveis com a palavra digitada
def total_anagramas(palavra):
    # Declaração de variáveis
    dic = {}
    total = 1  
    lista = []
    
    for letra in palavra:
        if letra not in dic:
            dic[letra] = 1
        else:
            dic[letra] += 1

    for i in dic:
        x = dic[i]
        lista.append(factorial(x))
    
    for l in lista:
        total *= l
    
    anagrama = factorial(len(palavra)) / total
    print(f'Total de anagramas possíveis: {int(anagrama)}')

# Cria anagramas com a palavra digitada
def criar_anagramas(palavra, termo = ''):
    if len(palavra) == 0:
        print(termo, end=', ')
    else:
        for i in range(len(palavra)):
            criar_anagramas(palavra[:i] + palavra[(i + 1):], termo + palavra[i])

# Chama a Função Principal
principal()