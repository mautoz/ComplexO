# Complex0
Código em C para alunos de ACH2023. Conteúdo oficial da disciplina:
[http://www.each.usp.br/digiampietri/ACH2023/]


## Sites que podem ajudar nos estudos

- Algoritmos do prof. Paulo Feofiloff: 
[https://www.ime.usp.br/~pf/algoritmos/]

- Estruturas de dados e Análise de Algoritmos (também do Feofiloff): 
[https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/index.html] 

[https://www.ime.usp.br/~pf/analise_de_algoritmos/]


## Recomendações

O Windows possui problemas para quem utiliza antivírus. Vocês podem até compilar, mas é capaz que não execute. Sendo assim, mantenham desativado durante os estudos!


## Compilação arquivo único

```
gcc -o <nomeDoPrograma> <nomeDoPrograma>.c
```


## Compilação de múltiplos arquivos

Alguns arquivos disponibilizados pelo professor contém mais de um arquivo, isto é, no topo deles tem um #include "codigo.c". Para compilar:

```
gcc -c <arquivo1>.c
gcc -c <arquivo2>.c
...
gcc -o <nomeDoProgramaParaExecutar> <arquivoComMain>.c
```


## Execução

Para Windows: 
```
.\<nomeDoPrograma>
```
ou 
```
.\<nomeDoPrograma>.exe
```
Para Ubuntu: 
```
./<nomeDoPrograma>
```


## Sugestões

Para quem quer utilizar a linha de comando, existem algumas alternativas no lugar do PowerShell  e que é parecido com o Linux, chamado CMDER. Para saber mais: 
[https://cmder.net/]

Já para a instalação do GCC, Python e outros, leiam: 
[https://chocolatey.org/]

Muitos devem utilizar o DevC++ ou o CodeBlocks para editar o código. Existem outras duas opções gratuitas e utéis:

- Sublime:
[https://www.sublimetext.com/]

- VSCode (eu prefiro):
[https://code.visualstudio.com/]


## Informações importantes

Os código colocados aqui não substituem as aulas, exercício ou qualquer outro material do professor Luciano. O material deste repositório serve apenas para auxiliar nos estudos, pois é interessante ver outras maneiras de estruturar o código.
