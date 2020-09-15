## ESTUDO DE COMPARAÇÃO DE TEMPO ENTRE TIPOS DE ESTRUTURA DE DADOS EM C E SUAS RELAÇÕES
Documento principal: https://github.com/Victor-Morvy/Estudo_Pilhas_Filas_Arvores_C/blob/master/ESTUDO%20DE%20COMPARA%C3%87%C3%83O%20DE%20TEMPO%20ENTRE%20TIPOS%20DE%20ESTRUTURA%20DE.pdf

# 1. INTRODUÇÃO

Este trabalho em formato de estudo tem como o objetivo levantar o tempo
necessário para carregar e percorrer dados das estruturas do tipo: fila, pilha e árvore
binária. E posteriormente utilizar estes dados para gerar comparações entre si e
analisar qual estrutura é a mais rápida.

# 2. METODOLOGIA

Foi criado um programa que gerou 500 dados com valores aleatórios entre 0
e 100.000 em um arquivo chamado dados.txt.

criarDadosAleatorios.c:

![](/images/image--000.png)

Em seguida, um outro programa foi criado, e roda um laço do tipo ‘enquanto’
para obter 10 resultados, estes dados fazem leituras de pilha, fila e árvore binária e
percorre a pilha, fila e a árvore binária em ordem, em pré ordem e pós ordem, e é
calculado o tempo de cada evento e então são guardados em variáveis. Em seguida
são salvos em um arquivo dados.xml:

![](/images/image--002.png)

![](/images/image--003.png)

Posteriormente o arquivo dados.xml gerado foi convertido para dados.xls e
aberto no Excel e utilizados para alimentar uma outra tabela e obter os dados
comparativos.

# 3. DADOS OBTIDOS

**Tabela 1** - Dados e média para carregar as estruturas:

![](/images/image--004.png)

**Tabela 2** - Dados e média para percorrer as estruturas:

![](/images/image--005.png)

**Tabela 3** - Gráfico do tempo para carregar estruturas:

![](/images/image--006.png)

**Tabela 4** - Gráfico do tempo para percorrer estruturas:

![](/images/image--007.png)

**Tabela 5** - Tempo para carregar os dados na estrutura e relação de tempo do mais
rápido:

![](/images/image--008.png)

**Tabela 6** - Tempo para percorrer a estrutura e relação de tempo do mais rápido:

![](/images/image--009.png)

# 4. CONCLUSÃO

Ao analisarmos os dados para carregar as estruturas, é notório que o tempo
de carregamento por fila tem em torno de 30% da velocidade para carregar pilha e
árvore binária, e a árvore binária tem uma velocidade pouco maior que a pilha.

Ao percorrer estas estruturas, foi constatado que a estrutura do tipo árvore
binária, em seus três tipos de percorrer estrutura, tem uma relação muito próxima a
velocidade uma da outra. Na **Tabela 2** podemos observar que varia de acordo com o
laço gerado qual tipo é o mais rápido. Em ordem, a pilha como o segundo percorrer
mais lento, e em último a fila, que tem 86,55% a velocidade total de percorrer em
relação a pilha. Curiosamente em alguns laços de percorrer estruturas, em árvores
binárias teve resultados com uma variante de 800% a 1000%, mesmo que em
nenhum momento do programa o arquivo dados.txt fora alterado.

Diante esta análise podemos averiguar que o tipo de estrutura Árvore Binária
se destaca no quesito velocidade de processamento de modo geral em relação a
estrutura Pilha e a estrutura Fila, pois mesmo que o tempo para carregar a estrutura
do tipo Pilha seja muito próximo ao da Árvore Binária, esta pequena diferença se
torna grande quando o intuito é percorrer estes dados. E em último vem o tipo de
estrutura Fila, que demonstrou ser o mais lento, tanto para alimentá-lo, quanto para
percorre-lo.


