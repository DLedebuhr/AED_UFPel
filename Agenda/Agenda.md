### _AGENDA - ALGORITMOS E ESTRUTURAS DE DADOS I_

***

<img align="right" src="https://i.pinimg.com/736x/32/92/7b/32927bc90e27e21505679b3c23b7f64b.jpg" alt="Imagem 1" style="border-radius: 10px; margin: 5px;" height="70">
<img align="right" src="https://i.pinimg.com/736x/da/1d/b1/da1db1452129ce8557f08c8983403752.jpg" alt="Imagem 2" style="border-radius: 10px; margin: 5px;" height="70">
<img align="right" src="https://i.pinimg.com/736x/32/92/7b/32927bc90e27e21505679b3c23b7f64b.jpg" alt="Imagem 3" style="border-radius: 10px; margin: 5px;" height="70">

> _Aluna: Dienifer Bierhals Ledebuhr_ 
 
> _Turma: M1 - AED I_

***

### ___Agenda - Instruções___

***

___Faça uma agenda com o seguinte menu:___

_1. Adicionar Pessoa (Nome, Idade, email)_

_2. Remover Pessoa_

_3. Buscar Pessoa_

_4. Listar todos_

_5. Sair_

---

___Desafio: Não pode criar variáveis, mas sim um buffer de memória (void *pBuffer).___

---

___Regras:___

* _Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer._

  * _Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer._

  * _Exemplo do que não pode: int c; char a; int v[10]; void Funcao(int parametro)._

* _Não pode usar struct em todo o programa._

### _Arquivos_

***

* Código da Agenda:
  
  * `Agenda.c`
     
* Arquivo fornecido pelo Dr. Memory:
  
  * `Agenda.txt`
   


### _Testes Realizados_

---

**1. Testes de Adicionar Pessoa**

* _O programa adicionou o primeiro registro com sucesso._  
* _O programa adicionou vários registros consecutivamente (2, 5, 10), e todos foram armazenados corretamente._

* _O programa adicionou registros com:_  
  * _Nome curto._  
  * _Nome longo (100 caracteres exatos)._  
  * _Nome com espaços._  
  * _Nome com caracteres especiais._

* _O programa adicionou registros com:_  
  * _Email curto._  
  * _Email longo (100 caracteres exatos)._  
  * _Email com espaços._  
  * _Email com caracteres especiais._

* _O programa adicionou registros com:_  
  * _Idade em número positivo._

* _Observações:_  
  * _O campo de idade não possui validação para entradas vazias._  
  * _O campo de idade rejeita números negativos._

---

**2. Testes de Remover Pessoa**

* _A remoção de qualquer registro depende do nome de busca._  
* _O nome de busca precisa ser exatamente o nome registrado na agenda._  
* _Caso haja dois registros com o mesmo nome, o programa removerá o que foi adicionado primeiro entre os dois._  
* _O programa removeu um registro encontrado na primeira posição, na última posição e em uma posição intermediária._

* _O programa tentou remover um registro com nome:_  
  * _Que existia, e ele foi removido corretamente._  
  * _Que não existia, e informou erro corretamente._  
  * _Que foi parcialmente correspondente, e o tratou como um nome inexistente._  
  * _Com caracteres especiais, e o resultado depende de o nome original possuir ou não caracteres especiais._

---

**3. Testes de Buscar Pessoa**

* _O programa buscou registros em uma agenda vazia, e informou que não havia registros._
* _O programa encontrou o primeiro, último e um registro intermediário em uma agenda com múltiplos registros._
  
* _O programa buscou registros com nome:_  
  * _Que existia, e ele foi encontrado corretamente._  
  * _Que não existia, e informou corretamente que não havia registros._  
  * _Que foi parcialmente correspondente, e o tratou como um nome inexistente._  
  * _Com caracteres especiais, e o resultado depende de o nome original possuir ou não caracteres especiais._
    
---

**4. Testes de Listar Pessoas**

* _O programa listou registros em uma agenda vazia, e informou corretamente que não havia registros._  
* _O programa listou registros em uma agenda com um único registro, e ele foi exibido corretamente._  
* _O programa listou múltiplos registros (2, 5, 10), e todos foram exibidos na ordem correta (ordem de entrada)._  
* _O programa exibiu os registros restantes corretamente após adições e remoções aleatórias._

---

**5. Testes de Realloc e Memória**

* _O programa realocou memória corretamente ao adicionar e remover registros alternadamente:_  
  * _Adicionou 10 registros, removeu 5 e adicionou mais 5 sem problemas._  
  * _Realizou 10 ciclos de adição e remoção consecutiva, mantendo-se estável._

* _O programa liberou a memória ao encerrar, sem apresentar vazamentos._

---

**6. Testes Gerais**

* _O programa rejeitou opções inválidas no menu._  
* _O programa continuou funcionando corretamente ao buscar e listar registros enquanto novos eram adicionados ou removidos._  
* _O programa adicionou vários registros, buscou por alguns, listou a agenda e removeu registros aleatoriamente, executando todas as funções corretamente._  
* _O programa reiniciou com uma agenda vazia após encerrar, como esperado._

---
   
