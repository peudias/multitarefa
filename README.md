# Sistema Multitarefa

<p>
<div style="display: inline-block;">
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
</p>

<p align="justify">
Neste projeto será construído um sistema de classificação cujas características permitirão observar conceitos importantes como: escalonamento e gestão de memória primária. 
</p>

<p align="justify">
Neste sistema, vamos considerar duas bases de dados: D e T. 
</p>

<p align="justify">
A base D será utilizada para simular a inicialização, fornecendo assim o conceito de bootstrapping, tal como no sistema operacional.
</p>

<p align="justify">
Já a base T representará os processos a serem executados, as quais serão coordenadas utilizando um sistema de escalonamento em dois níveis: mecanismo e política. 
</p>

# Etapa I
<p align="justify">
Elaboração das tabelas hash para itens e classes. Dado uma linha do arquivo, considere item as colunas de 0 a n - 1. 

Considere a coluna n de cada linha como classe. 

Nessas tabelas é armazenado cada item como chave e seus índices no arquivo como valor. Considere como índice a linha que aquele valor específico aparece. 

Considere também item específico aquele item pertencente a coluna x. 

Logo, para itens de mesmo valor, a indexação foi feita de forma separada, ou seja, se um item aparece na coluna 1 e 3 com valor 23.4, considere como chave da hash (1,23.4) e (3,23.4). 
</p>

# Etapa II
<p align="justify">
Nessa etapa foi trabahado o conteúdo de T. 
  
O conteúdo de T foi lido em uma Fila em que cada posição detenha uma linha inteira já tokenizada. 

Depois de carregar todo o conteúdo de T, foi processado linha a linha, ou seja, comparando os itens de T com a tabela hash de itens, selecionando apenas os itens em comum.
  
Em seguida, foi realizado a permutação dos itens comuns de 1 a N, com N definido estaticamente com define diretamente no código. 

Por fim, foi armazenenado todas as permutações de uma entrada em T em um segundo Vector.
</p>

# Compilação e Execução

Os exemplos disponibilizados possuem um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contatos

<div style="display: inline-block;">
<a href="https://t.me/phpdias">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/phpd/">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>

<p> </p>


<a style="color:black" href="mailto:michel@cefetmg.br?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>phpdias@outlook.com</i>
</a>
