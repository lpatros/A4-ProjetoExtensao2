#ifndef DRINK_H
#define DRINK_H

#include "../sale/sale.h"

typedef struct {
    int choice;
    Sale sale;
} Drink;

Drink registerDrink(int isNewSale);

#endif