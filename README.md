# A4 Projeto de Extensão II

## 🎓 Descrição da Atividade

Ao longo do desenvolvimento de um sistema implementamos diversas estruturas de programação. Visando uma maior prática, você deverá desenvolver um PROGRAMA C, que registre as vendas realizadas todos os dias, por um restaurante a Quilo.

O programa deve considerar:
- o peso e o preço do item refeição;
- caso, seja quentinha essa tem o preço fixo de R$ 20,00 + a embalagem 0,50 centavos.
- no caso de bebidas, acrescentar o valor e quando houver a quantidade.

O programa deve apresentar um **relatório diário**, ou seja, uma lista com o valor total das vendas (contemplar peso e valor) realizadas.
O programa deve apresentar uma **relatoria mensal**, ou seja, uma lista mensal com o valor total vendido mensalmente.
O programa deve pegar o total das vendas realizadas durante o ano e colocar em ordem decrescente, ou seja, pegar o mês com o valor mais alto vendido e assim sucessivamente.
O restaurante vende diariamente uma média de 100 refeições.

### Obrigatório

- utilizar struct, array, enum, algoritmo de ordenação, funções. 
- Implementar o pseudocódigo (solução) na linguagem C.
- Apresentar os testes realizados, ou seja, inserir os valores de entrada e apresentar os resultados apresentados (saída).

## ⚙️ Projeto Desenvolvido

### 🚀 Como Compilar e Executar

#### Pré-requisitos
- Compilador C (GCC recomendado)

#### Compilação
Abra o terminal na pasta raiz do projeto e execute o seguinte comando:
```bash
gcc main.c utils/utils.c include/drink/drink.c include/sale/sale.c include/saleID/saleID.c -o main
```

#### Execução
Após a compilação bem-sucedida, um arquivo executável chamado main (ou main.exe no Windows) será gerado. Para rodar o programa, execute:
No Linux/MacOS:
```bash
./main
```
No Windows:
```bash
main.exe
```
