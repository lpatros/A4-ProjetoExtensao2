# 🍽️ Sistema de Vendas - Restaurante a Quilo

## 📑 Sumário

- [📋 Descrição do Projeto](#-descrição-do-projeto)
  - [🎯 Objetivos da Atividade](#-objetivos-da-atividade)
- [⚡ Funcionalidades](#-funcionalidades)
  - [🛒 Tipos de Venda Suportados](#-tipos-de-venda-suportados)
  - [📊 Sistema de Relatórios](#-sistema-de-relatórios)
- [🏗️ Estrutura do Projeto](#️-estrutura-do-projeto)
- [🛠️ Compilação e Execução](#️-compilação-e-execução)
  - [Pré-requisitos](#pré-requisitos)
  - [📦 Compilação](#-compilação)
  - [▶️ Execução](#️-execução)
- [🎮 Como Usar](#-como-usar)
  - [Menu Principal](#menu-principal)
  - [Exemplo de Uso - Registrando uma Venda](#exemplo-de-uso---registrando-uma-venda)
  - [Exemplo de Relatório](#exemplo-de-relatório)
- [🔧 Recursos Técnicos Implementados](#-recursos-técnicos-implementados)
  - [✅ Estruturas de Dados](#-estruturas-de-dados)
  - [✅ Algoritmos Utilizados](#-algoritmos-utilizados)

## 📋 Descrição do Projeto

Sistema de gerenciamento de vendas desenvolvido em C para restaurantes que trabalham com refeições a quilo, quentinhas e bebidas. O sistema oferece funcionalidades completas para registro de vendas e geração de relatórios detalhados (diário, mensal e anual).

### 🎯 Objetivos da Atividade

Este projeto foi desenvolvido como parte da disciplina **Projeto de Extensão II** com os seguintes objetivos:

- Implementar um sistema completo de vendas em linguagem C
- Utilizar estruturas de dados como: structs, arrays e enums
- Aplicar algoritmos de ordenação e manipulação de arquivos
- Desenvolver relatórios organizados por período
- Praticar modularização através de funções

## ⚡ Funcionalidades

### 🛒 Tipos de Venda Suportados

1. **Refeição a Quilo**
   - Preço: R$ 70,00/kg
   - Cálculo baseado no peso informado

2. **Quentinha**
   - Preço fixo: R$ 20,00 + R$ 0,50 (embalagem)
   - Total por unidade: R$ 20,50

3. **Bebidas**
   - Preço unitário variável (informado pelo usuário)
   - Pode ser adicionada a outras vendas

### 📊 Sistema de Relatórios

- **Relatório Diário**: Vendas do dia atual
- **Relatório Mensal**: Vendas do mês atual  
- **Relatório Anual**: Vendas do ano atual com ordenação por valor

## 🏗️ Estrutura do Projeto

```
A4-ProjetoExtensao2/
├── data/
│   │── README.md                   # Documentação dos dados
│   ├── saleID.txt                  # Controle de ID sequencial
│   └── sales.txt                   # Histórico de vendas
├── include/
│   ├── drink/
│   │   ├── drink.c
│   │   └── drink.h                 # Funcionalidades específicas de bebidas
│   ├── reports/
│   │    ├── reports.c
│   │    └── reports.h              # Sistema de relatórios
│   ├── sale/
│   │   ├── sale.c
│   │   └── sale.h                  # Estruturas e funções de venda
│   └── saleID/
│       ├── saleID.c
│       └── saleID.h                # Gerenciamento de IDs únicos
├── utils/
│   ├── utils.c
│   └── utils.h                     # Utilitários gerais
├──.gitignore                       
├── main.c                          # Arquivo principal
└── README.md                       # Este arquivo
```

## 🛠️ Compilação e Execução

### Pré-requisitos

- **Compilador C**: GCC (recomendado)

### 📦 Compilação

Abra o terminal na pasta raiz do projeto e execute:

```bash
gcc main.c include/*/*.c utils/*.c -o main
```

### ▶️ Execução

**Linux/macOS:**
```bash
./main
```

**Windows:**
```bash
main.exe
```

## 🎮 Como Usar

### Menu Principal

```
----- Sistema de Vendas -----
1. Registrar Venda
2. Relatório Diário
3. Relatório Mensal
4. Relatório Anual
5. Sair
-----------------------------
```

### Exemplo de Uso - Registrando uma Venda

1. **Selecione a opção 1** no menu principal
2. **Escolha o tipo de venda:**
   - `1` para Refeição a Quilo
   - `2` para Quentinha
   - `3` para Bebida

3. **Para Refeição a Quilo:**
   ```
   Digite o peso da refeição a quilo (em kg): 0.750
   ```
   - Sistema calcula: 0.750kg × R$ 70,00 = R$ 52,50
   - Opção de adicionar bebidas à venda

4. **Para Quentinha:**
   ```
   Digite a quantidade de quentinhas: 2
   ```
   - Sistema calcula: 2 × R$ 20,50 = R$ 41,00

5. **Para Bebida:**
   ```
   Digite a quantidade de bebidas: 3
   Digite o valor unitário da bebida: R$ 5.00
   ```
   - Sistema calcula: 3 × R$ 5,00 = R$ 15,00

### Exemplo de Relatório

```
----------------------------- Relatório Diário -----------------------------
| ID    | Tipo  | Peso      | Quantidade        | Preço Item    | Data     |
| 1     | 1     | 0.286kg   | 1                 | R$20.02       | 03/06/25 |
| 2     | 3     | 0.000kg   | 2                 | R$10.00       | 03/06/25 |
| 3     | 2     | 0.000kg   | 1                 | R$20.50       | 03/06/25 |
----------------------------------------------------------------------------
Total de vendas: 3
Valor total das vendas: R$50.52
```

## 🔧 Recursos Técnicos Implementados

### ✅ Estruturas de Dados
- **Structs**: `Sale`, `itemSale`, `SaleList`, `Time`, `Drink`
- **Enums**: `TypeItem`, `ColorText`, `ReportType`
- **Arrays dinâmicos**: Gerenciamento automático de memória

### ✅ Algoritmos Utilizados
- Busca e filtragem de dados por período
- Manipulação de strings e formatação de datas
- Gerenciamento dinâmico de memória
