### _Trabalho Pratico 4 - ALGORITMOS E ESTRUTURAS DE DADOS I_

***
<img align="right" src="https://i.pinimg.com/736x/92/96/51/9296519679ef05974e4aebe3715e2131.jpg" alt="Imagem 1" style="border-radius: 10px; margin: 5px;" width="70">
<img align="right" src="https://i.pinimg.com/736x/74/c2/a2/74c2a2c4fc2063cf33ca678d510752f6.jpg" alt="Imagem 2" style="border-radius: 10px; margin: 5px;" width="70">
<img align="right" src="https://i.pinimg.com/736x/03/66/80/036680d3b9ac301fd608582b273355ee.jpg" alt="Imagem 3" style="border-radius: 10px; margin: 5px;" width="70">


> _Aluna: Dienifer Bierhals Ledebuhr_ 
 
> _Turma: M1 - AED_

***

### _826. Most Profit Assigning Work_

***

_You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:_

_difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
Every worker can be assigned at most one job, but one job can be completed multiple times._

_For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs._

### _Codigos_

***

* Código desenvolvido em aula:
  
  * `AtividadePratica04.c`
    
* Código desenvolvido em casa:

  * `AtividadePratica04_EmCasa.c` 


### _Observações e Dificuldades_

***

_No início, tive uma ideia de como resolver o problema, mas logo percebi que ela não era tão eficiente quanto eu esperava. Apesar disso, continuei tentando ajustá-la, fazendo modificações e melhorias ao longo do caminho. Cheguei a um ponto em que acreditei que a base estava pronta, mas ainda faltava organizar o código ao redor dela._

_A primeira organização foi a ordenação dos vetores. Como estava mais familiarizada com o Bubble Sort, decidi usá-lo para ordenar os dados. Após ordenar os vetores, deixei-os no início do código e comecei a trabalhar na lógica principal, tentando fazer com que o restante do programa funcionasse corretamente. No final, consegui fazer o código ser aceito em 55 dos 60 casos de teste, mas não sabia mais o que modificar para resolver os casos restantes._

_Fiquei tão focada em achar que o problema estava na função maxProfitAssignment que acabei ignorando outras possíveis causas. Depois de várias tentativas e mudanças insignificativas, decidi pedir ajuda ao DeepSeek para avaliar meu código. Descobri que o problema estava no método de ordenação que escolhi. O Bubble Sort não era eficiente o suficiente para lidar com os casos maiores, o que causava 'Time Limit Exceeded'._

_A partir daí, comecei a saga para mudar o método de ordenação. Pensei em implementar o Quick Sort manualmente, mas estava tendo dificuldades para lembrar dele naquele momento, então optei por utilizar a função padrão qsort da biblioteca do C. Isso foi especialmente útil porque, no dia anterior, eu havia feito um exercício no LeetCode (56) que também utilizava qsort. Só precisei pesquisar como adaptá-lo para funcionar com uma struct, que era o caso do meu problema._

_Depois de fazer essa mudança, o código foi aceito. No entanto, ainda enfrentei alguns problemas no caminho, como esquecer um parêntese em um determinado momento. Esses pequenos erros me fizeram perder um bom tempo, mas no final valeu a pena, pois consegui resolver o problema._

### _Testes Realizados_

***

 * _Os testes realizados foram os do próprio LeetCode._

***
