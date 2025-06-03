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

<!-- ### 🏗️ Estrutura do Projeto

```
A4-ProjetoExtensao2/
├── include/
│   ├── utils.h          # Funções utilitárias e interface
│   ├── venda.h          # Estruturas e funções de vendas
│   └── relatorios.h     # Funções de relatórios
├── src/
│   ├── venda.c          # Implementação de vendas
│   └── relatorios.c     # Implementação de relatórios
├── utils/
│   └── utils.c          # Implementação de utilitários
├── main.c               # Arquivo principal
└── README.md           # Documentação do projeto
```

### 🎯 Funcionalidades Implementadas

#### 1. **Sistema de Vendas**
- ✅ Registro de vendas por tipo (Refeição a Quilo, Quentinha, Bebida)
- ✅ Cálculo automático de valores baseado em peso/quantidade
- ✅ Armazenamento em arrays estruturados

#### 2. **Sistema de Relatórios**
- ✅ **Relatório Diário**: Lista detalhada das vendas do dia
- ✅ **Relatório Mensal**: Consolidado de vendas por dia do mês
- ✅ **Relatório Anual**: Ranking dos meses em ordem decrescente de vendas

#### 3. **Interface do Usuário**
- ✅ Menu interativo colorido
- ✅ Limpeza automática do terminal
- ✅ Validação de entradas

### 🔧 Tecnologias e Conceitos Utilizados

| Conceito | Implementação | Arquivo |
|----------|---------------|---------|
| **Struct** | `Venda` para armazenar dados de vendas | `venda.h` |
| **Enum** | `TipoVenda` e `CorTexto` | `venda.h`, `utils.h` |
| **Arrays** | `vendasDiarias[]`, `totalVendasMes[]`, `totalVendasAno[]` | `venda.c` |
| **Algoritmo de Ordenação** | Bubble Sort para ranking anual | `venda.c` |
| **Funções** | Modularização em múltiplos arquivos | Todos os `.c` | -->

### 🚀 Como Compilar e Executar

#### Pré-requisitos
- Compilador C (GCC recomendado)

#### Compilação
Abra o terminal na pasta raiz do projeto e execute o seguinte comando:
```bash
gcc main.c src/venda.c src/relatorios.c utils/utils.c -o main
```

#### Execução
Após a compilação bem-sucedida, um arquivo executável chamado main (ou main.exe no Windows) será gerado. Para rodar o programa, execute:
No Linux/MacOS:
```bash
./main
```
No Windows:
```powershell
main.exe
```