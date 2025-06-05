#include "sale.h"

#include <stdio.h>
#include <string.h>
#include "../../utils/utils.h"
#include "../saleID/saleID.h"
#include "../drink/drink.h"

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
            color_printf("Digite o peso da refeicao a quilo (em kg): ", COLOR_WHITE);
            scanf("%lf", &newSale.item.weight);

            clearTerminal();

            // Calcula o preço
            newSale.item.amount = 1;
            newSale.item.price = newSale.item.weight * KILO_PRICE;

            writeSale(&newSale);

            // Pergunta e registra se o usuário desejar adicionar bebida(s) à venda atual
            registerDrink(&newSale, 0); // 0 significa que não é uma nova venda

            color_printf("\n-----Refeicao registrada-----\n", COLOR_WHITE);
            printf("| Peso \t\t | Valor    |\n");
            printf("| %.3fkg \t | R$ %.2f |\n", newSale.item.weight, newSale.item.price);
            color_printf("-----------------------------\n", COLOR_WHITE);

            break;

        case QUENTINHA:
            color_printf("Digite a quantidade de quentinhas: ", COLOR_WHITE);
            scanf("%d", &newSale.item.amount);

            clearTerminal();

            // Calcula o preço
            newSale.item.price = (newSale.item.amount * QUENTINHA_PRICE) + (newSale.item.amount * PACKAGING_PRICE);
            newSale.item.weight = 0; // Peso é 0 para quentinhas

            writeSale(&newSale);

            color_printf("\n----- Venda  registrada -----\n", COLOR_WHITE);
            printf("| Quentinhas \t | Valor    |\n");
            printf("| %d \t\t | R$ %.2f |\n", newSale.item.amount, newSale.item.price);
            color_printf("-----------------------------\n", COLOR_WHITE);
            break;

        case BEBIDA:
            registerDrink(&newSale, 1); // 1 significa que é uma nova venda
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
