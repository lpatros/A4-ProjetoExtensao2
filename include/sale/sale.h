#ifndef SALE_H
#define SALE_H

#include <time.h>

typedef enum {
    REFEICAO = 1,
    QUENTINHA = 2,
    BEBIDA = 3
} TypeItem;

typedef struct {
    TypeItem type;      // Tipo do item (1: Refeição a quilo, 2: Quentinha, 3: Bebida)
    double weight;      // Peso da refeição a quilo (em kg), 0 para outros tipos
    int amount;         // Quantidade de quentinhas ou bebidas vendidas
    double price;       // Preço unitário do item
} itemSale;

typedef struct {
    int id;             // ID da venda (incrementado automaticamente)
    itemSale item;      // Item vendido (Refeição, Quentinha ou Bebida)
    double total;       // Preço total da venda
    time_t date;        // Data e hora da venda
} Sale;

#define KILO_PRICE 70.00
#define QUENTINHA_PRICE 20.00
#define FILE_PATH_SALE "data/sales.txt"

void writeSale(Sale* newSale);

void registerSale();

#endif