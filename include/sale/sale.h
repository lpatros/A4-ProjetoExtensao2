#ifndef SALE_H
#define SALE_H

#include <time.h>

#define FILE_PATH_SALE "data/sales.txt"

typedef enum {
    MEAL = 1,
    HOTMEAL = 2,
    DRINK = 3
} TypeItem;

typedef struct {
    TypeItem type;      // Tipo do item (1: Refeição a quilo, 2: Quentinha, 3: Bebida)
    double weight;      // Peso da refeição a quilo (em kg), 0 para outros tipos
    int amount;         // Quantidade de quentinhas ou bebidas vendidas
    double price;       // Preço unitário do item
} itemSale;

typedef struct {
    int id;             // ID da venda (incrementado automaticamente)
    itemSale item;      // Item vendido (Refeição, HOTMEAL ou Bebida)
    double total;       // Preço total da venda
    char date[20];      // Data e hora da venda
} Sale;

typedef struct {
    int countLines;     // Número de linhas no arquivo
    Sale *sales;        // Array dinâmico de vendas
    double totalValue;  // Valor total das vendas
    int totalSales;     // Total de vendas registradas no arquivo
} SaleList;

typedef struct {
    char *text;
    double content;
} PrintSale;

void writeSale(Sale* newSale);

void printSale(Sale* sale);

void registerSale();

#endif