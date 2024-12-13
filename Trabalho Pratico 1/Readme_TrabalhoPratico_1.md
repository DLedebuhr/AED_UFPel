### _Trabalho Pratico 1 - ALGORITMOS E ESTRUTURAS DE DADOS I_

***

<img align="right" src="https://i.pinimg.com/736x/9e/71/f0/9e71f067169c6b4be5639939fb121e4a.jpg" alt="Imagem 1" style="border-radius: 10px; margin: 5px;" width="70">
<img align="right" src="https://i.pinimg.com/736x/0a/b2/4f/0ab24fde994e032363f2e57d8a5fa852.jpg" alt="Imagem 2" style="border-radius: 10px; margin: 5px;" width="70">
<img align="right" src="https://i.pinimg.com/736x/02/29/7d/02297db0f20dc00daba9b445e4d0bfe6.jpg" alt="Imagem 3" style="border-radius: 10px; margin: 5px;" width="70">

> _Aluna: Dienifer Bierhals Ledebuhr_ 
 
> _Turma: M1 - AED_

***

### _Problema: 118. Triângulo de Pascal_

***

_Informações sobre o problema estão no README que acompanha o codigo._

_O problema foi resolvido e concluído durante a aula, enviado e aceito pelo LeetCode. Em casa, realizei algumas alterações com o objetivo de organizar melhor o código._

_O código original possuía comentários incorretos e pouco claros. Por esse motivo, decidi removê-los, ajustar a estrutura, e reenviar uma versão mais limpa e organizada._



### _Codigos_

***

* Código desenvolvido em aula:
  * `Ex1.c`
    
* Código revisado e reorganizado em casa:
  * `TriânguloPascal_EmCasa.c` 

* Versão criada exclusivamente para testar com o Dr.
  * `TriânguloPascal_DrMemory.c` -> Inclui uma função main retirada da internet para possibilitar os testes.



### _Observações e Dificuldades_

***

_O código funciona conforme o esperado. No entanto, tive algumas dificuldades ao longo do desenvolvimento, principalmente com o uso de ponteiros para ponteiros._

_Tive experiência prévia com um problema semelhante o que ajudou a construir uma base funcional, mas a solução final foi resultado de várias tentativas e erros._

_Além disso, precisei utilizar desenhos das matrizes para me localizar durante a implementação dos laços._

_Desenhos são essenciais quando o assunto é ponteiros._



### _Testes Realizados_

***

1. Teste -> numRows = 5
   
   Output:
   ```
   [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
   ```
   Expected:
   ```
   [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
   ```

2. Teste -> numRows = 1
   
   Output:
   ```
   [[1]]
   ```
   Expected:
   ```
   [[1]]
   ```

3. Teste -> numRows = 8
   
   Output:
   ```
   [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1],[1,5,10,10,5,1],[1,6,15,20,15,6,1],[1,7,21,35,35,21,7,1]]
   ```
   Expected:
   ```
   [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1],[1,5,10,10,5,1],[1,6,15,20,15,6,1],[1,7,21,35,35,21,7,1]]
   ```

***
