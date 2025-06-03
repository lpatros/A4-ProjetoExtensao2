#include "drink.h"

#include <stdio.h>
#include "../sale/sale.h"
#include "../../utils/utils.h"
#include "../sale/sale.h"

Drink registerDrink(int isNewSale) {

    Drink drink;
    drink.choice = 1;

    // Se não for uma nova venda, exibe a opção de adicionar bebida(s) a venda atual
    if (!isNewSale) {
        color_printf("Deseja adicionar bebida(s)?\n", COLOR_WHITE);
        color_printf("1. Sim\n", COLOR_GREEN);
        color_printf("2. Nao\n", COLOR_RED);
        color_printf("Digite a opcao: ", COLOR_WHITE);
        scanf("%d", &drink.choice);
    }

    switch (drink.choice) {
    
        // Se for uma nova venda, ou o usuário escolheu adicionar bebida(s)
        case 1:
            drink.sale.item.type = BEBIDA;
            drink.sale.item.weight = 0; // Peso é 0 para bebidas

            // Incrementa o ID da venda se for uma nova venda (isNewSale == 1, ou seja, true)
            drink.sale.id = getID() + isNewSale; 

            color_printf("Digite a quantidade de bebidas: ", COLOR_WHITE);
            scanf("%d", &drink.sale.item.amount);
            color_printf("Digite o valor unitario da bebida: R$ ", COLOR_WHITE);
            scanf("%lf", &drink.sale.item.price);

            // Calcula o preço total da venda
            drink.sale.total = drink.sale.item.amount * drink.sale.item.price;

            // Escreve a venda no arquivo
            writeSale(&drink.sale);

            color_printf("\n-- Bebida(s) registrada(s) --\n", COLOR_WHITE);
            printf("| Bebidas \t | Valor    |\n");
            printf("| %d \t\t | R$ %.2f  |\n", drink.sale.item.amount, drink.sale.item.price);
            color_printf("-----------------------------\n", COLOR_WHITE);

            return drink;

        default:
            break;
    }            
}