#include "drink.h"

#include <stdio.h>
#include <string.h>
#include "../sale/sale.h"
#include "../../utils/utils.h"
#include "../sale/sale.h"

int showWantDrink() {
    int option;

    color_printf("Deseja adicionar bebida(s)?\n", COLOR_WHITE);
    color_printf("1. Sim\n", COLOR_GREEN);
    color_printf("2. Nao\n", COLOR_RED);
    color_printf("Digite a opcao: ", COLOR_WHITE);
    scanf("%d", &option);

    // Verifica se a opção é válida
    if (option < 1 || option > 2) {
        clearTerminal();
        color_printf("Opcao invalida! Tente novamente.\n", COLOR_RED);
        return showWantDrink(); // Chama a função recursivamente até obter uma opção válida
    }

    return option;
}

void registerDrink(Sale *sale) {

    Sale drinkSale = {
        .id = sale->id,
        .item = {
            .type = BEBIDA,
            .weight = 0,   // Peso é 0 para bebidas
            .amount = 0,   // Quantidade será definida pelo usuário
            .price = 0.0   // Preço unitário será definido pelo usuário
        },
        .total = 0.0, // Total será calculado posteriormente
    };

    // Copia a data da venda original
    strcpy(drinkSale.date, sale->date);

    color_printf("Digite a quantidade de bebidas: ", COLOR_WHITE);
    scanf("%d", &drinkSale.item.amount);
    color_printf("Digite o valor unitario da bebida: R$ ", COLOR_WHITE);
    scanf("%lf", &drinkSale.item.price);

    clearTerminal();

    // Calcula o preço da venda
    drinkSale.total = drinkSale.item.amount * drinkSale.item.price;

    // Escreve a venda no arquivo
    writeSale(&drinkSale);

    color_printf("\n-- Bebida(s) registrada(s) --\n", COLOR_WHITE);
    printf("| Bebidas \t | Valor    |\n");
    printf("| %d \t\t | R$ %.2f  |\n", drinkSale.item.amount, drinkSale.item.price);
    color_printf("-----------------------------\n", COLOR_WHITE);        
}