# coding: utf-8
'''Desafio: Qual é a senha? [ ][ ][ ][ ][ ] (5 dígitos)
Dicas:
35871 -> 3 números corretos, 1 naposição correta.
70682 -> 1 número correto, mas no lugar errado.
56430 -> 2 número corretos, mas no lugar errado.
08726 -> 1 número correto na posição correta.
40962 -> 2 número corretos, mas no lugar errado.
84673 -> 1 número correto na posição correta.
61348 -> 2 números correto, mas no lugar errado.
'''

# Função Principal
def principal():
    senha = ''
    for x in range(0, 99999):  # Gera senhas
        senha = '{:0>5}'.format(x)  # Acrescenta zeros à esquerda até completar 5 dígitos. 
        if num_certo(senha, '35871') != 3 or num_e_pos_certa(senha, '35871') != 1:
            continue
        if num_certo(senha, '70682') != 1 or num_e_pos_certa(senha, '70682') != 0: 
            continue
        if num_certo(senha, '56430') != 2 or num_e_pos_certa(senha, '56430') != 0:
            continue
        if num_certo(senha, '08726') != 1 or num_e_pos_certa(senha, '08726') != 1:
            continue
        if num_certo(senha, '40962') != 2 or num_e_pos_certa(senha, '40962') != 0:
            continue
        if num_certo(senha, '84673') != 1 or num_e_pos_certa(senha, '84673') != 1:
            continue
        if num_certo(senha, '61348') != 2 or num_e_pos_certa(senha, '61348') != 0:
            continue
        print('A senha correta é: {}'.format(senha))  # Imprime a senha correta.


# Função Número Certo: Verifica igualdades, independente da posição.
def num_certo(senha, senha_certa):
    for i in range(0, 5):
        for j in range(0, 5):
            if senha[i] == senha_certa[j]:
                contador += 1
    return contador


# Função Número E Posição Correta: Verifica a igualdade na respectiva posição.
def num_e_pos_certa(senha, senha_certa):
    for i in range(0, 5):
        if senha[i] == senha_certa[i]:
            contador += 1
    return contador


# Chama a Função Principal.
if __name__ == '__main__':
    principal()