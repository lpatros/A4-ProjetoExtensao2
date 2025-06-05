#include "meal.h"

#include "../../utils/utils.h"
#include "drink.h"
#include <stdio.h>

void registerMeal(Sale* newSale) {
    color_printf("Digite o peso da refeicao a quilo (em kg): ", COLOR_WHITE);
    scanf("%lf", &newSale->item.weight);

    clearTerminal();

    // Calcula o preço
    newSale->item.amount = 1;
    newSale->item.price = newSale->item.weight * KILO_PRICE;

    writeSale(newSale);

    // Pergunta se o usuário desejar adicionar bebida(s) à venda atual
    int wantDrink = showWantDrink();

    // Se o usuário quiser adicionar bebida(s), chama a função registerDrink
    if (wantDrink == 1) {
        registerDrink(newSale);
    }

    // Imprime os detalhes da venda
    printSale(newSale);
}