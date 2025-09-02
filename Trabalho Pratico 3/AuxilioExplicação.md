> Árvore

    [10, 5, -3, 3, 2, 11]

              10
             /  \
            5    -3
           / \    \
          3   2    11

> Somas das Subárvores

    Subárvore com raiz 3: 3
    Subárvore com raiz 2: 2
    Subárvore com raiz 5: 5 + 3 + 2 = 10.
    Subárvore com raiz 11: 11
    Subárvore com raiz -3: -3 + 11 = 8.
    Subárvore com raiz 10: 10 + 5 + 3 + 2 + (-3) + 11 = 28.

> Frequência

    3  -> 1
    2  -> 1
    10 -> 1
    11 -> 1
    8  -> 1
    28 -> 1

> Valores [3, 2, 10, 11, 8, 28]
> Frequência [1, 1, 1, 1, 1, 1] -> A maior frequência é 1

> Resultado = [3, 2, 10, 11, 8, 28]
> *returnSize = 6