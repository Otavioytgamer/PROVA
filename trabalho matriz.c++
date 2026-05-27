#include <stdio.h>
#include <string.h>

int main() {
    char nome[100];
    int opcao;
    char setor[20];
    int matriz[3][4];

    printf("=== NOC: MONITORAMENTO DE REDE FIBRA ===\n");
    printf("Nome do Analista: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    printf("\nSelecione o Setor de Varredura:\n");
    printf("1 - Setor Norte\n");
    printf("2 - Setor Sul\n");
    printf("3 - Setor Leste\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            strcpy(setor, "Setor Norte");
            break;
        case 2:
            strcpy(setor, "Setor Sul");
            break;
        case 3:
            strcpy(setor, "Setor Leste");
            break;
        default:
            printf("Opcao invalida! Encerrando o programa...\n");
            return 0;
    }

    printf("\n--- LEITURA DE LATENCIA (em ms) ---\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            printf("Zona %d, Caixa %d: ", i, j);
            scanf("%d", &matriz[i][j]);
            if(matriz[i][j] < 0) {
                printf("Falha critica de hardware\n");
                return 0;
            }
        }
    }

    int soma = 0;
    int max_lat = -1;
    int max_row = -1;
    int max_col = -1;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            soma += matriz[i][j];
            if(matriz[i][j] > max_lat) {
                max_lat = matriz[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    float media = (float)soma / 12.0;

    printf("\n--- DASHBOARD DO QUADRANTE ---\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            printf("[%03d ms] ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n========================================\n");
    printf("       DIAGNÓSTICO DA REDE FIBRA\n");
    printf("========================================\n");
    printf("Analista NOC: %s\n", nome);
    printf("Área Mapeada: %s\n", setor);
    printf("----------------------------------------\n");
    printf("Latência Média: %.2f ms\n", media);
    printf("----------------------------------------\n");
    printf("[ORDEM DE SERVIÇO] Caixa com Rompimento/Lentidão:\n");
    printf("Pico de Latência: %d ms\n", max_lat);
    printf("Coordenada Exata: Zona %d, Caixa %d\n", max_row, max_col);
    printf("========================================\n");

    return 0;
}