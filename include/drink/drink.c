#include "drink.h"

#include <stdio.h>
#include "../sale/sale.h"
#include "../../utils/utils.h"
#include "../sale/sale.h"

Drink registerDrink(Sale *sale, int isNewSale) {

    Drink drink =  {
        .choice = 1, // Inicializa a escolha como 1 (registrar bebida)
        .sale = {
            .id = sale->id,
            .item = {
                .type = BEBIDA,
                .weight = 0,   // Peso é 0 para bebidas
                .amount = 0,   // Quantidade será definida pelo usuário
                .price = 0.0   // Preço unitário será definido pelo usuário
            },
            .total = 0.0, // Total será calculado posteriormente
            .date = sale->date
        }
    };

    // Se não for uma nova venda, exibe a opção de adicionar bebida(s) a venda atual
    if (!isNewSale) {
        color_printf("Deseja adicionar bebida(s)?\n", COLOR_WHITE);
        color_printf("1. Sim\n", COLOR_GREEN);
        color_printf("2. Nao\n", COLOR_RED);
        color_printf("Digite a opcao: ", COLOR_WHITE);
        scanf("%d", &drink.choice);
    }

    if (drink.choice == 1) {

        color_printf("Digite a quantidade de bebidas: ", COLOR_WHITE);
        scanf("%d", &drink.sale.item.amount);
        color_printf("Digite o valor unitario da bebida: R$ ", COLOR_WHITE);
        scanf("%lf", &drink.sale.item.price);

        clearTerminal();

        // Calcula o preço da venda
        drink.sale.total = drink.sale.item.amount * drink.sale.item.price;

        // Escreve a venda no arquivo
        writeSale(&drink.sale);

        color_printf("\n-- Bebida(s) registrada(s) --\n", COLOR_WHITE);
        printf("| Bebidas \t | Valor    |\n");
        printf("| %d \t\t | R$ %.2f  |\n", drink.sale.item.amount, drink.sale.item.price);
        color_printf("-----------------------------\n", COLOR_WHITE);

        return drink;
    }            
}