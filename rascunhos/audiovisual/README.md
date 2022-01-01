# Projeto de Extensão ProgramAuto: Título

## Introdução

* Colocar uma explicação de cada algoritmo escolhido
* Colocar aqui uma breve explicação do programa
* Explicar o processamento


## Casos e Usos

* Colocar aqui alguns exemplos
* Casos de uso

## Arquivos

* Explicar a produção 

## Repositório

### Arquivos no repositório

No repositório devem constar apenas e tão somente os arquivos:

* pext-programa2-benante-sobrenome1-sobrenome2.tex
* pext-programa2-benante-sobrenome1-sobrenome2.pdf
* Imagens usadas que foram incluídas no artigo .tex, na subpasta imagens/
* biblio.bib: arquivo com bibliografia
* AUTHORS
* LICENSE
* README.md (este arquivo)
* VERSION
* makefile

### Comandos para criar repositório no Hydra

Apenas um aluno do grupo, o responsável por criar, faz essa sequencia:

Entre na pasta de extensao e digite:

```
$ cd extensao
$ git init
$ git add .
$ git cm "commit inicial"
$ ssh git@hydra newrepo pext01.git
$ git remote add origin git@hydra:repos/2020s2/pext01.git
$ git pull origin master --allow-unrelated-histories -s recursive -X ours --no-edit
$ git push -u origin master
```

E a partir de agora seu repositorio esta remoto, e os outros alunos do grupo poderao trabalhar em grupo após clonarem.
Para ficar com a pasta com o mesmo nome dos colegas, renomeie-a assim:

```
$ cd programa2/rascunhos
$ mv extensao pext01
```

### Comandos para clonar o repositório remoto no Hydra

Os outros alunos do grupo irão clonar o repositório com:

```
$ cd programa2/rascunhos
$ git clone git@hydra:repos/2020s2/pext01.git
```

Confira com:

```
$ cd pext01
$ ls
$ git st
```

Talvez confira também um "commit" e "push" da sua parte, seguido de um "pull" de outro aluno, para ter certeza que estão colaborando no mesmo repositório.

E depois de estar satisfeito, os alunos que fizeram clone podem apagar a pasta de extensao que acabou ficando em duplicidade com o clone:

```
$ cd programa2/rascunhos
$ rm -rf extensao
```

Lembre-se de entregar o trabalho fazendo um novo clone na pasta trabalhos ao final do prazo de entrega.

## Copyright

* Date: 2021-06-14
* License: GNU/GPL v2.0

## Authors

* Author: Prof. Dr. Ruben Carlo Benante
* Email: rcb@upe.br

* Author: Nome do aluno 1
* Email:

* Author: Nome do aluno 2
* Email:

