# Diretório de Dados (`data/`)

Este diretório armazena os arquivos de dados persistentes utilizados pela aplicação.

## `sales.txt`

Este arquivo armazena o histórico de todas as vendas registradas. Cada linha representa uma única transação e segue o formato de valores separados por espaço:

| ID_VENDA      | TIPO_VENDA      | PESO_KG   | QUANTIDADE | PRECO_ITEM  | DATA_VENDA |
|---------------|-----------------|-----------|------------|-------------|------------|

**Exemplo de Conteúdo:**
```
1 1 1.00 1 70.00 01/01/24
2 1 0.25 1 17.36 01/01/24
3 2 0.00 2 41.00 02/01/24
4 3 0.00 5 25.00 02/01/24
```

**Descrição dos Campos:**

| Campo         | Tipo            | Descrição                                                                                                                                                                                                                            | Exemplo    |
|---------------|-----------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------|
| `ID_VENDA`    | Inteiro         | Identificador único para cada venda.                                                                                                                                                                                                 | `1`        |
| `TIPO_VENDA`  | Inteiro (Enum)  | Tipo da venda: <br> `1`: Refeição a quilo <br> `2`: Quentinha <br> `3`: Bebida                                                                                                                                                           | `2`        |
| `PESO_KG`     | Ponto flutuante | Peso da refeição em quilogramas. Aplicável apenas para `TIPO_VENDA = 1`. Para outros tipos, o valor é `0.00`.                                                                                                                            | `0.25`     |
| `QUANTIDADE`  | Inteiro         | Número de itens na venda (ex: quentinhas, bebidas). Para `TIPO_VENDA = 1` (refeição a quilo), o valor é `1`.                                                                                                                              | `5`        |
| `PRECO_ITEM`  | Ponto flutuante | Valor monetário registrado para o item: <br> - Para Refeição a quilo (`TIPO_VENDA = 1`): É o preço total da refeição (`PESO_KG * 70.00`). <br> - Para Quentinha (`TIPO_VENDA = 2`): É o preço total de todas as quentinhas (`QUANTIDADE * 20.50`). <br> - Para Bebida (`TIPO_VENDA = 3`): É o preço unitário da bebida. | `70.00`    |
| `DATA_VENDA`  | String          | Data da venda no formato `DD/MM/AA`.                                                                                                                                                                                                   | `01/01/24` |

## `saleID.txt`

Este arquivo armazena o valor do último ID de venda utilizado. Isso garante que cada nova venda receba um ID único e sequencial.

**Exemplo de Conteúdo:**
```
4
```
O conteúdo do arquivo é um único número inteiro que representa o ID da última venda registrada. Ao registrar uma nova venda, o sistema lê este valor, incrementa-o e o utiliza como o ID da nova venda, atualizando o arquivo em seguida.