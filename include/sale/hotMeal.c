#include "hotMeal.h"

#include "../../utils/utils.h"
#include <stdio.h>

void registerHotMeal(Sale* newSale) {
    color_printf("Digite a quantidade de quentinhas: ", COLOR_WHITE);
    scanf("%d", &newSale->item.amount);

    clearTerminal();

    // Calcula o preço
    newSale->item.price = (newSale->item.amount * HOTMEAL_PRICE) + (newSale->item.amount * PACKAGING_PRICE);
    newSale->item.weight = 0; // Peso é 0 para quentinhas

    writeSale(newSale);

    printSale(newSale);
}