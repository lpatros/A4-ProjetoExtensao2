#include "saleID.h"

#include <stdio.h>
#include "../sale/sale.h"
#include "../../utils/utils.h"

void updateFileID(int id) {
    FILE *file = fopen(FILE_PATH_ID, "w");

    if (file == NULL) {
        color_printf("Erro ao abrir o arquivo de id.\n", COLOR_RED);
        return;
    }

    fprintf(file, "%d\n", id);

    fclose(file);
}

int getID() {
    FILE *file = fopen(FILE_PATH_ID, "r");

    if (file == NULL) {
        color_printf("Criando novo arquivo com o ID 0.\n", COLOR_YELLOW);
        updateFileID(0);
        return 0;
    }

    int id;
    fscanf(file, "%d", &id);

    fclose(file);
    return id;
}
