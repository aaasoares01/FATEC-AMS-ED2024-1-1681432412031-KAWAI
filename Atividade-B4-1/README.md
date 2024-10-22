# Programa BubbleSort

O programaMelhorado 2 é mais eficiente que o programaOriginal, embora ambos implementem o algoritmo Bubble Sort, que tem complexidade de tempoO(n2)O(n2) no pior caso. A diferença principal está na otimização que o programaMelhorado inclui. 

Ele usa uma variável chamada trocas (ou flag) para monitorar se houve trocas durante uma passagem pelo array. Se não houver trocas em uma iteração, isso significa que o array já está ordenado, e o algoritmo pode interromper sua execução, evitando passagens desnecessárias.