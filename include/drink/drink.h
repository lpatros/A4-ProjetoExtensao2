#ifndef DRINK_H
#define DRINK_H

#include "../sale/sale.h"

typedef struct {
    int choice;
    Sale sale;
} Drink;

void registerDrink(Sale *sale, int isNewSale);

#endif