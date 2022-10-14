# Sistema Multitarefa

<p>
<div style="display: inline-block;">

![C++](https://img.shields.io/badge/-C++-05122A?style=flat&logo=Cplusplus)&nbsp;
![Visual Studio Code](https://img.shields.io/badge/-Visual%20Studio%20Code-05122A?style=flat&logo=visual-studio-code&logoColor=007ACC)&nbsp;

</p>

<p align="justify">

Neste projeto será construído um sistema de classificação cujas características permitirão observar conceitos importantes como: **escalonamento** e **gestão de memória primária**. 

Neste sistema, vamos considerar duas bases de dados: `D` e `T`. 

A `base D` será utilizada para **simular a inicialização**, fornecendo assim o conceito de **bootstrapping**, tal como no sistema operacional.

Já a `base T` representará os **processos a serem executados**, as quais serão coordenadas utilizando um sistema de **escalonamento em dois níveis: mecanismo e política**. 

</p>

## Etapa I - Trabalhando o conteúdo de D 
### Elaboração das tabelas hash para itens e classes.

<p align="justify">

Dado uma linha do arquivo, **considere `item` as `colunas` de `0` a `n - 1`**. 

Considere a **`coluna n`** de **cada linha como `classe`**. 

Nessas tabelas são armazenados **`cada item` como `chave`** e seus **`índices no arquivo` como `valor`**. Considere como índice a linha que aquele valor específico aparece. 

Considere também **item específico** aquele item **pertencente a coluna x**. 

Logo, para itens de mesmo valor, a indexação foi feita de forma separada, ou seja, **se um item aparece na coluna 1 e 3 com valor 23.4, considere como chave da hash `(1,23.4)` e `(3,23.4)`**. 

</p>

## Etapa II - Trabalhando o conteúdo de T

<p align="justify">  

O conteúdo de **`T`** foi **lido em uma `Fila`** em que **cada posição detenha uma linha inteira já tokenizada**. 

Depois de carregar todo o conteúdo de T, **foi processado linha a linha**, ou seja, **comparando os itens de T com a tabela hash de itens**, **selecionando apenas os itens em comum**.
  
Em seguida, foi realizado a **permutação dos itens comuns de 1 a N**, com **N definido estaticamente** com define diretamente no código. 

Por fim, foi **armazenenado todas as permutações** de uma entrada em T em um **segundo Vector**.

</p>

## Etapa III

<p align="justify">

Para cada **permutação** encontrada, foi **buscado individualmente** os valores dos **itens em hash**, executando em seguida uma **interseção desses valores**.

Se a **`interseção`** for **`não nula`**, **será aplicada essa na hash de todas as classes**. 
  
A **classe** que apresentar um valor de **sobreposição maior** após processar todas as permutações **será apresentada** como **classe da tarefa em T**.
  
</p>

## Etapa IV

<p align="justify">

</p>

## Etapa V

<p align="justify">

</p>

## Compilação e Execução

Os exemplos disponibilizados possuem um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

ou

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make r`              | Executa o `make clean` + `make` + `make run`                                                      |


# Contatos

<div style="display: inline-block;">

<a href="https://t.me/phpdias" target="_blank">
  <img align="center" src="https://img.shields.io/badge/-phpdias-05122A?style=flat&logo=telegram" alt="linkedin"/>
</a>
  
<a href="https://linkedin.com/in/phpd" target="_blank">
  <img align="center" src="https://img.shields.io/badge/-phpd-05122A?style=flat&logo=linkedin" alt="linkedin"/>
</a>

<a style="color:black" href="mailto:phpdias@outlook.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
 <img align="center" src="https://img.shields.io/badge/-phpdias@outlook.com-05122A?style=flat&logo=email" alt="linkedin"/>
</a>

</div>




