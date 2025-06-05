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

int getNextID() {
    int currentID = getID();
    return currentID + 1;
}

int getID() {
    FILE *file = fopen(FILE_PATH_ID, "r");

    // Verifica se o arquivo existe
    if (file == NULL) {
        color_printf("Criando novo arquivo com o ID 0.\n", COLOR_YELLOW);
        updateFileID(0);
        return 0;
    }

    // Tenta ler o ID do arquivo
    static int id;
    if (fscanf(file, "%d", &id) != true) {
    
        // Se não conseguiu ler o ID, ou o arquivo está vazio
        color_printf("Arquivo de ID inválido ou vazio. Definindo ID como 0.\n", COLOR_YELLOW);
        fclose(file);

        updateFileID(0);
        return 0;
    }

    fclose(file);
    return id;
}
