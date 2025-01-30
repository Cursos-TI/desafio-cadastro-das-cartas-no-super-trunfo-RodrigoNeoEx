#include <stdio.h> 
#include <stdlib.h>
#include <string.h> // Manipulação de strings (strcpy, strcmp, etc.)
#include <time.h> // Geração de números aleatórios baseada no tempo (srand, time)



#define ESTADOS 8

#define CIDADES_POR_ESTADO 4
#define TOTAL_CIDADES (ESTADOS * CIDADES_POR_ESTADO)

// Estrutura para representar uma cidade
typedef struct {
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

// Estrutura para representar um país
typedef struct {
    char nome[50];
    Cidade cidades[TOTAL_CIDADES];
} Pais;

void cadastrarCidades(Pais *pais);
void preencherCidadesAutomaticamente(Pais *pais);
void exibirCidades(Pais pais);

int main() {
    Pais pais;
    int usarPreenchimentoAutomatico = 0;

    printf("Digite o nome do país: ");
    scanf(" %49[^\n]", pais.nome);

    // Perguntar ao usuário se deseja preenchimento automático
    printf("Deseja preencher os dados automaticamente? (1 - Sim, 0 - Não): ");
    scanf("%d", &usarPreenchimentoAutomatico);

    if (usarPreenchimentoAutomatico) {
        preencherCidadesAutomaticamente(&pais);
    } else {
        cadastrarCidades(&pais);
    }

    printf("\nTodas as cidades foram cadastradas com sucesso! Exibindo os dados...\n");
    exibirCidades(pais);
    return 0;
}

void cadastrarCidades(Pais *pais) {
    char estados[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;
    
    for (int i = 0; i < ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            snprintf(pais->cidades[index].codigo, sizeof(pais->cidades[index].codigo), "%c%02d", estados[i], j + 1);
            printf("\nCadastro da cidade %s:\n", pais->cidades[index].codigo);
            
            printf("Nome: ");
            scanf(" %49[^\n]", pais->cidades[index].nome);

            printf("População: ");
            scanf("%d", &pais->cidades[index].populacao);

            printf("Área (km²): ");
            scanf("%f", &pais->cidades[index].area);

            printf("PIB (bilhões): ");
            scanf("%f", &pais->cidades[index].pib);

            printf("Número de pontos turísticos: ");
            scanf("%d", &pais->cidades[index].pontos_turisticos);
            
            index++;
        }
    }
}

void preencherCidadesAutomaticamente(Pais *pais) {
    char *nomesExemplo[] = {"Cidade Alfa", "Cidade Beta", "Cidade Gama", "Cidade Delta", "Cidade Ômega"};
    srand(time(NULL));
    char estados[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;

    for (int i = 0; i < ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            snprintf(pais->cidades[index].codigo, sizeof(pais->cidades[index].codigo), "%c%02d", estados[i], j + 1);
            strcpy(pais->cidades[index].nome, nomesExemplo[rand() % 5]);
            pais->cidades[index].populacao = rand() % 1000000 + 1000; // Entre 1000 e 1 milhão
            pais->cidades[index].area = (float)(rand() % 1000 + 10); // Entre 10 e 1000 km²
            pais->cidades[index].pib = (float)(rand() % 500 + 1); // Entre 1 e 500 bilhões
            pais->cidades[index].pontos_turisticos = rand() % 50 + 1; // Entre 1 e 50
            index++;
        }
    }
}

void exibirCidades(Pais pais) {
    printf("\n===== Dados das Cartas Cadastradas =====\n");
    printf("\nPaís: %s\n", pais.nome);
    for (int i = 0; i < TOTAL_CIDADES; i++) {
        printf("\nCódigo: %s\n", pais.cidades[i].codigo);
        printf("Cidade: %s\n", pais.cidades[i].nome);
        printf("População: %d habitantes\n", pais.cidades[i].populacao);
        printf("Área: %.2f km²\n", pais.cidades[i].area);
        printf("PIB: %.2f bilhões\n", pais.cidades[i].pib);
        printf("Pontos turísticos: %d\n", pais.cidades[i].pontos_turisticos);
        printf("---------------------------------------\n");
    }
}
