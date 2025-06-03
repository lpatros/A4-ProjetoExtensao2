# Diretório de Dados (`data/`)

Este diretório armazena os arquivos de dados persistentes utilizados pela aplicação.

## `sales.txt`

Este arquivo armazena o histórico de todas as vendas registradas. Cada linha representa uma única transação e segue o formato de valores separados por espaço:

| ID_VENDA      | TIPO_VENDA      | PESO_KG   | QUANTIDADE | PRECO_TOTAL |
|---------------|-----------------|-----------|------------|-------------|

**Exemplo de Conteúdo:**
```
1 1 1.00 1 70.00
2 1 0.25 1 17.36
3 2 0.00 2 41.00
4 3 0.00 5 25.00
```

**Descrição dos Campos:**

| Campo         | Tipo            | Descrição                                                                                                | Exemplo |
|---------------|-----------------|----------------------------------------------------------------------------------------------------------|---------|
| `ID_VENDA`    | Inteiro         | Identificador único para cada venda.                                                                     | `1`       |
| `TIPO_VENDA`  | Inteiro (Enum)  | Tipo da venda: <br> `1`: Refeição a quilo <br> `2`: Quentinha <br> `3`: Bebida                               | `2`       |
| `PESO_KG`     | Ponto flutuante | Peso da refeição em quilogramas. Aplicável apenas para `TIPO_VENDA = 1`. Para outros tipos, o valor é `0.00`. | `0.25`  |
| `QUANTIDADE`  | Inteiro         | Número de itens na venda (ex: quentinhas, bebidas). Para `TIPO_VENDA = 1` (refeição a quilo), o valor é `1`. | `5`       |
| `PRECO_TOTAL` | Ponto flutuante | Valor total monetário da venda.                                                                          | `41.00`   |

## `saleID.txt`

Este arquivo armazena o valor do último ID de venda utilizado. Isso garante que cada nova venda receba um ID único e sequencial.

**Exemplo de Conteúdo:**
```
4
```
O conteúdo do arquivo é um único número inteiro que representa o ID da última venda registrada. Ao registrar uma nova venda, o sistema lê este valor, incrementa-o e o utiliza como o ID da nova venda, atualizando o arquivo em seguida.