#include "sale.h"

#include <stdio.h>
#include "../../utils/utils.h"
#include "../saleID/saleID.h"
#include "../drink/drink.h"

time_t getCurrentTime() {
    time_t currentTime;
    time(&currentTime);
    return currentTime;
}

void writeSale(Sale* newSale) {

    // Abre o arquivo de vendas em modo de adição
    FILE *file = fopen(FILE_PATH_SALE, "a");
    
    if (file == NULL) {
        color_printf("Erro ao abrir o arquivo de vendas.\n", COLOR_RED);
        return;
    }

    // Escreve os dados da venda no arquivo (FILE_PATH_SALE) no formato:

    // ----------------------------------------------------
    // | ID | Tipo | Peso (kg) | Quantidade | Preço Total |
    // |  1 |   1  |   2.50    |      3     |   20.00     |
    // ----------------------------------------------------

    fprintf(file, "%d %d %.3f %d %.2f\n",
            newSale->id,
            newSale->item.type,
            newSale->item.weight,
            newSale->item.amount,
            newSale->item.price);

    fclose(file);

    // Atualiza o ID no arquivo FILE_PATH_ID
    updateFileID(newSale->id);
}

void registerSale() {

    menuSale();

    int typeItem;
    scanf("%d", &typeItem);

    Sale newSale;
    // transforma o numero do usuário no enum
    newSale.item.type = (TypeItem)typeItem;

    // Incrementa o ID da venda
    int id = getID() + 1;
    newSale.id = id;

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
            registerDrink(0); // 0 significa que a bebida será adicionada ao id da venda atual

            // Exibe os detalhes da venda
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
            newSale.item.price = (newSale.item.amount * QUENTINHA_PRICE) + (newSale.item.amount * 0.50);
            newSale.item.weight = 0; // Peso é 0 para quentinhas

            writeSale(&newSale);

            color_printf("\n----- Venda  registrada -----\n", COLOR_WHITE);
            printf("| Quentinhas \t | Valor    |\n");
            printf("| %d \t\t | R$ %.2f |\n", newSale.item.amount, newSale.item.price);
            color_printf("-----------------------------\n", COLOR_WHITE);
            break;

        case BEBIDA:
            registerDrink(1); // 1 significa que a bebida é uma nova venda
            break;

        default:
            color_printf("Tipo de Venda invalido! Tente novamente.\n", COLOR_RED);
            return;
    }
}
