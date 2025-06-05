#include "sale.h"

#include <stdio.h>
#include <string.h>
#include "../../utils/utils.h"
#include "../saleID/saleID.h"
#include "meal.h"
#include "hotMeal.h"
#include "drink.h"

void writeSale(Sale* newSale) {

    // Abre o arquivo de vendas em modo de adição
    FILE *file = fopen(FILE_PATH_SALE, "a");
    
    if (file == NULL) {
        color_printf("Erro ao abrir o arquivo de vendas.\n", COLOR_RED);
        return;
    }

    // Escreve os dados da venda no arquivo (FILE_PATH_SALE) no formato:
    
    // -----------------------------------------------------------------
    // | ID | Tipo | Peso (kg) | Quantidade | Preço Item  | data       |
    // |  1 |   1  |   2.50    |      3     |   20.00     | 03/06/25   |
    // -----------------------------------------------------------------

    fprintf(file, "%d %d %.3f %d %.2f %s\n",
            newSale->id,
            newSale->item.type,
            newSale->item.weight,
            newSale->item.amount,
            newSale->item.price,
            newSale->date);

    fclose(file);

    // Atualiza o ID no arquivo FILE_PATH_ID
    updateFileID(newSale->id);
}

void printSale(Sale* sale) {

    PrintSale printSale;
    switch (sale->item.type) {
        case REFEICAO:
            printSale.text = "Peso";
            printSale.content = sale->item.weight;
            break;
        default:
            printSale.text = "Qntd";
            printSale.content = (double)sale->item.amount;
            break;
    }

    color_printf("\n---------Venda registrada--------\n", COLOR_WHITE);
    printf("| %s \t\t | Valor \t|\n", printSale.text);
    printf("| %.3f \t | R$ %.2f \t|\n", printSale.content, sale->item.price);
    color_printf("---------------------------------\n", COLOR_WHITE);
}

void registerSale() {

    menuSale();

    int userItem;
    scanf("%d", &userItem);

    Time currentTime = {
        .now = getCurrentTime(),            // Obtém o timestamp atual
    };
    formatDateTime(currentTime.now, currentTime.dateStr); // Formata o timestamp no formato "DD/MM/AA"

    Sale newSale = {
        .id = getNextID(),                  // Obtém o próximo ID de venda
        .item = {
            .type = (TypeItem)userItem,     // transforma o numero do usuário no enum
            .weight = 0.0,                  // Peso da refeição a quilo (inicialmente 0)
            .amount = 0,                    // Quantidade de quentinhas ou bebidas (inicialmente 0)
            .price = 0.0                    // Preço unitário do item (inicialmente 0)
        },
        .total = 0.0,                       // Preço total da venda (inicialmente 0)
    };
    
    // Copia a data formatada para a struct
    strcpy(newSale.date, currentTime.dateStr);
    
    switch (newSale.item.type) {

        case REFEICAO:
            registerMeal(&newSale);
            break;

        case HOTMEAL:
            registerHotMeal(&newSale);
            break;

        case DRINK:
            registerDrink(&newSale);
            break;
        
        case 4:
            clearTerminal();
            return;

        default:
            clearTerminal();
            color_printf("Tipo de Venda invalido! Tente novamente.\n", COLOR_RED);
            return;
    }
}
