#include <stdio.h>  // Para funções de entrada e saída como printf e scanf
#include <string.h> // Para funções de string, como strlen (útil, embora não estritamente necessária aqui)
#include <stdlib.h> // Para funções de utilidade geral (não usamos nenhuma aqui, mas bom para ter)

// Definindo a estrutura (o "molde") para as nossas cartas de cidade
typedef struct {
    char nome[100];       // Nome da cidade, até 99 caracteres + terminador null
    char estado;          // A letra do estado (e.g., 'A', 'B')
    char codigo[5];       // O código da carta (e.g., "A01"), até 4 caracteres + terminador null
    unsigned long int populacao; // População, pode ser bem grande, sem sinal
    double area;          // Área da cidade em km², usando double para maior precisão
    double pib;           // PIB em bilhões de reais, usando double para maior precisão
    int pontos_turisticos; // Número de pontos turísticos

    // Atributos que serão calculados a partir dos dados acima
    double densidade_populacional; // Habitantes por km²
    double pib_per_capita;         // Riqueza média por pessoa
    float super_poder;             // Pontuação geral da carta
} Carta;

// Função para calcular a densidade populacional de uma carta
// Recebe um ponteiro para a Carta para poder modificar seus membros
void calcular_densidade_populacional(Carta *c) {
    // Evita divisão por zero: se a área for 0, a densidade é 0.
    c->densidade_populacional = (c->area > 0) ? ((double)c->populacao / c->area) : 0.0;
}

// Função para calcular o PIB per capita de uma carta
void calcular_pib_per_capita(Carta *c) {
    // PIB é dado em bilhões de reais, então multiplicamos por 1 bilhão para ter o valor total em reais.
    // Evita divisão por zero: se a população for 0, o PIB per capita é 0.
    c->pib_per_capita = (c->populacao > 0) ? ((c->pib * 1000000000.0) / c->populacao) : 0.0;
}

// Função para calcular o "Super Poder" de uma carta
void calcular_super_poder(Carta *c) {
    // Soma os atributos principais e adiciona o inverso da densidade.
    // Usamos (double) para garantir que as somas intermediárias mantenham precisão antes de converter para float.
    double temp_super_poder = (double)c->populacao + c->area + c->pib + (double)c->pontos_turisticos + c->pib_per_capita;
    // Adiciona o inverso da densidade, se a densidade não for zero.
    temp_super_poder += (c->densidade_populacional > 0) ? (1.0 / c->densidade_populacional) : 0.0;

    // Converte o resultado final para float, conforme a declaração em 'Carta'.
    c->super_poder = (float)temp_super_poder;
}

// Função para exibir todos os detalhes de uma carta
void exibir_detalhes_carta(const char* titulo, const Carta *c) {
    printf("\n--- %s ---\n", titulo);
    printf("Estado: %c\n", c->estado);
    printf("Código: %s\n", c->codigo);
    printf("Nome da Cidade: %s", c->nome); // fgets inclui o '\n', então não adicionamos um aqui.
    printf("População: %lu habitantes\n", c->populacao);
    printf("Área: %.2lf km²\n", c->area); // %.2lf para double com 2 casas decimais
    printf("PIB: %.2lf bilhões de reais\n", c->pib);
    printf("Pontos Turísticos: %d\n", c->pontos_turisticos);
    printf("Densidade Populacional: %.2lf hab/km²\n", c->densidade_populacional);
    printf("PIB per Capita: %.2lf reais\n", c->pib_per_capita);
    printf("Super Poder: %.2f\n", c->super_poder); // Super Poder é float, então %.2f
}


// Função para comparar os atributos de duas cartas e exibir o vencedor
// Esta função assume que a lógica de "maior valor vence" e "menor valor vence" é pré-definida.
// Como solicitado, não usa if/else, mas sim a conversão booleana para int (0 ou 1) e o operador ternário para string.
void comparar_atributos(Carta c1, Carta c2) {
    printf("\n--- Comparação de Cartas ---\n");

    // Lógica de comparação: resultado é 1 se Carta 1 vence, 0 se Carta 2 vence (ou empata).
    // Para atributos onde MAIOR valor vence: (valor1 > valor2)
    // Para Densidade Populacional onde MENOR valor vence: (valor1 < valor2)
    int c1_vence_populacao = (c1.populacao > c2.populacao);
    int c1_vence_area = (c1.area > c2.area);
    int c1_vence_pib = (c1.pib > c2.pib);
    int c1_vence_pontosTuristicos = (c1.pontos_turisticos > c2.pontos_turisticos);
    int c1_vence_densidadePopulacional = (c1.densidade_populacional < c2.densidade_populacional); // INVERTIDO: menor densidade vence
    int c1_vence_pibPerCapita = (c1.pib_per_capita > c2.pib_per_capita);
    int c1_vence_superPoder = (c1.super_poder > c2.super_poder);

    // Exibe o resultado usando o operador ternário para a string "Carta 1" ou "Carta 2"
    printf("População: %s venceu (%d)\n", c1_vence_populacao ? "Carta 1" : "Carta 2", c1_vence_populacao);
    printf("Área: %s venceu (%d)\n", c1_vence_area ? "Carta 1" : "Carta 2", c1_vence_area);
    printf("PIB: %s venceu (%d)\n", c1_vence_pib ? "Carta 1" : "Carta 2", c1_vence_pib);
    printf("Pontos Turísticos: %s venceu (%d)\n", c1_vence_pontosTuristicos ? "Carta 1" : "Carta 2", c1_vence_pontosTuristicos);
    printf("Densidade Populacional: %s venceu (%d)\n", c1_vence_densidadePopulacional ? "Carta 1" : "Carta 2", c1_vence_densidadePopulacional);
    printf("PIB per Capita: %s venceu (%d)\n", c1_vence_pibPerCapita ? "Carta 1" : "Carta 2", c1_vence_pibPerCapita);
    printf("Super Poder: %s venceu (%d)\n", c1_vence_superPoder ? "Carta 1" : "Carta 2", c1_vence_superPoder);
}

int main() {
    // Criamos duas variáveis do tipo Carta para armazenar os dados das nossas duas cartas
    Carta carta1, carta2;

    // --- Leitura dos dados para a primeira carta ---
    printf("Digite os dados para a Carta 1:\n");
    printf("Nome da cidade: ");
    // Usamos fgets para ler o nome da cidade (permite espaços) e evitar problemas de buffer.
    // Ele inclui o '\n' no final, que trataremos depois.
    fgets(carta1.nome, sizeof(carta1.nome), stdin);
    // Limpamos o '\n' que fgets pode ter deixado no final da string.
    carta1.nome[strcspn(carta1.nome, "\n")] = 0;

    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta1.estado); // O espaço antes de %c consome qualquer '\n' pendente.

    // Limpa o restante do buffer para a próxima leitura de string.
    // Enquanto houver caracteres no buffer (incluindo o '\n' que scanf %c deixa), consome.
    while (getchar() != '\n');

    printf("Código da carta (ex: A01): ");
    fgets(carta1.codigo, sizeof(carta1.codigo), stdin);
    carta1.codigo[strcspn(carta1.codigo, "\n")] = 0;

    printf("População: ");
    scanf("%lu", &carta1.populacao);

    printf("Área (em km²): ");
    scanf("%lf", &carta1.area); // %lf é o especificador para double

    printf("PIB (em bilhões de reais): ");
    scanf("%lf", &carta1.pib);

    printf("Pontos Turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // --- Leitura dos dados para a segunda carta ---
    // Importante: limpa o buffer após a última leitura de scanf numérico antes de ler strings novamente.
    while (getchar() != '\n'); 
    
    printf("\nDigite os dados para a Carta 2:\n");
    printf("Nome da cidade: ");
    fgets(carta2.nome, sizeof(carta2.nome), stdin);
    carta2.nome[strcspn(carta2.nome, "\n")] = 0;

    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta2.estado);
    
    // Limpa o buffer novamente.
    while (getchar() != '\n');

    printf("Código da carta (ex: B02): ");
    fgets(carta2.codigo, sizeof(carta2.codigo), stdin);
    carta2.codigo[strcspn(carta2.codigo, "\n")] = 0;

    printf("População: ");
    scanf("%lu", &carta2.populacao);

    printf("Área (em km²): ");
    scanf("%lf", &carta2.area);

    printf("PIB (em bilhões de reais): ");
    scanf("%lf", &carta2.pib);

    printf("Pontos Turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // --- Calcular atributos adicionais para ambas as cartas ---
    // Chamamos as funções que criamos para preencher os valores derivados.
    calcular_densidade_populacional(&carta1);
    calcular_pib_per_capita(&carta1);
    calcular_super_poder(&carta1);

    calcular_densidade_populacional(&carta2);
    calcular_pib_per_capita(&carta2);
    calcular_super_poder(&carta2);

    // --- Exibir os detalhes completos das cartas ---
    exibir_detalhes_carta("Detalhes da Carta 1", &carta1);
    exibir_detalhes_carta("Detalhes da Carta 2", &carta2);

    // --- Comparar as duas cartas e mostrar o vencedor de cada atributo ---
    comparar_atributos(carta1, carta2);

    return 0; // Sinaliza que o programa terminou sem erros.
}