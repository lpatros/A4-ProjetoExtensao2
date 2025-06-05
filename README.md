# Sistema de Vendas - Restaurante a Quilo

## Sumário

- [Descrição do Projeto](#descrição-do-projeto)
  - [Objetivos da Atividade](#objetivos-da-atividade)
- [Funcionalidades](#funcionalidades)
  - [Tipos de Venda Suportados](#tipos-de-venda-suportados)
  - [Sistema de Relatórios](#sistema-de-relatórios)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Compilação e Execução](#compilação-e-execução)
  - [Pré-requisitos](#pré-requisitos)
  - [Compilação](#compilação)
  - [Execução](#execução)
- [Recursos Implementados](#recursos-implementados)
  - [Estruturas de Dados](#estruturas-de-dados)
  - [Algoritmos Utilizados](#algoritmos-utilizados)
  - [Funcionalidades Extras](#funcionalidades-extras)

## Descrição do Projeto

Sistema de gerenciamento de vendas desenvolvido em C para restaurantes que trabalham com refeições a quilo, quentinhas e bebidas. O sistema oferece funcionalidades para registro de vendas e geração de relatórios detalhados com interface colorida no terminal.

### Objetivos da Atividade

Este projeto foi desenvolvido como parte da disciplina **Projeto de Extensão II** com os seguintes objetivos:

- Implementar um sistema completo de vendas em linguagem C
- Utilizar estruturas de dados como: structs, arrays e enums
- Aplicar algoritmos de ordenação e manipulação de arquivos
- Desenvolver relatórios organizados por período
- Praticar modularização através de funções

## Funcionalidades

### Tipos de Venda Suportados

1. **Refeição a Quilo** 
   - Preço: **R$ 70,00/kg**
   - Cálculo baseado no peso informado pelo usuário
   - Opção de adicionar bebidas à mesma venda

2. **Quentinha**
   - Preço base: **R$ 20,00** + **R$ 0,50** (embalagem)
   - **Total por unidade: R$ 20,50**
   - Quantidade definida pelo usuário

3. **Bebidas**
   - Preço unitário **variável** (informado pelo usuário)
   - Pode ser vendida independentemente ou como complemento

### Sistema de Relatórios

- **Relatório Diário**: Vendas do dia atual
- **Relatório Mensal**: Vendas do mês atual
- **Relatório Anual**: Vendas do ano atual

## Estrutura do Projeto

```
A4-ProjetoExtensao2/
├── data/                           # Arquivos de dados persistentes
│   ├── README.md                   # Documentação do formato dos dados
│   ├── saleID.txt                  # Controle de ID sequencial
│   └── sales.txt                   # Histórico de vendas
├── include/                        # Módulos principais do sistema
│   ├── reports/
│   │   ├── reports.c
│   │   └── reports.h               # Sistema de relatórios por período
│   ├── sale/
│   │   ├── sale.c
│   │   ├── sale.h                  # Estruturas principais e registro
│   │   ├── drink/
│   │   │   ├── drink.c
│   │   │   └── drink.h             # Módulo específico para bebidas
│   │   ├── hotMeal/
│   │   │   ├── hotMeal.c
│   │   │   └── hotMeal.h           # Módulo específico para quentinhas
│   │   └── meal/
│   │       ├── meal.c
│   │       └── meal.h              # Módulo para refeições a quilo
│   └── saleID/
│       ├── saleID.c
│       └── saleID.h                # Gerenciamento de IDs únicos
├── utils/
│   ├── utils.c
│   └── utils.h                     # Utilitários gerais e interface
├── .gitignore                      # Arquivos ignorados pelo Git
├── main.c                          # Arquivo principal com menu
└── README.md                       # Este arquivo
```

## Compilação e Execução

### Pré-requisitos

- **Compilador C**: GCC (recomendado)

### Compilação

Abra o terminal na pasta raiz do projeto e execute:

```bash
gcc main.c include/*/*.c include/*/*/*.c utils/*.c -o main
```

### Execução

**Linux/macOS:**
```bash
./main
```

**Windows:**
```bash
main.exe
```

## Recursos Implementados

### Estruturas de Dados
- **Structs**: 
  - `Sale`: Estrutura principal de venda com ID, item, total e data
  - `itemSale`: Detalhes do item (tipo, peso, quantidade, preço)
  - `SaleList`: Lista dinâmica de vendas para relatórios
  - `Time`: Gerenciamento de datas e timestamps
  - `PrintSale`: Formatação de saída personalizada

- **Enums**: 
  - `TypeItem`: Tipos de itens (REFEICAO, HOTMEAL, DRINK)
  - `ColorText`: Cores para interface do terminal
  - `ReportType`: Tipos de relatório (DAILY, MONTHLY, ANNUAL)

- **Arrays dinâmicos**: Alocação automática de memória para listas de vendas

### Algoritmos Utilizados
- **Filtragem temporal**: Busca de vendas por período (dia/mês/ano)
- **Gerenciamento de IDs**: Sistema sequencial automático
- **Manipulação de arquivos**: Leitura/escrita persistente de dados
- **Formatação de datas**: Conversão timestamp para formato brasileiro
- **Gerenciamento de memória**: Alocação e liberação dinâmica
- **Modularização**: Separação de responsabilidades em módulos específicos

### Funcionalidades Extras
- **Interface colorida**: Uso de códigos ANSI para terminal colorido
- **Validação de entrada**: Verificação de opções válidas nos menus
- **Cross-platform**: Comando de limpeza de tela
- **Vendas combinadas**: Possibilidade de adicionar bebidas a refeições
- **Persistência de dados**: Dados mantidos entre execuções do programa
