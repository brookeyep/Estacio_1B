# Projeto Super Trunfo de Cidades em C

## 📝 Visão Geral do Projeto

Este é um projeto em C que simula um jogo de Super Trunfo focado em dados de cidades. O programa permite ao usuário registrar informações detalhadas para duas cartas de cidade, calcular atributos estratégicos (como densidade populacional, PIB per capita e um "Super Poder" combinado), e então comparar essas cartas em diversos critérios para determinar a vencedora em cada rodada.

## ✨ Funcionalidades Principais

* **Cadastro de Cartas:** Permite a entrada de dados como nome, estado, código, população, área, PIB e pontos turísticos para duas cidades.
* **Cálculo de Atributos Derivados:** Calcula automaticamente a densidade populacional, o PIB per capita e um "Super Poder" para cada cidade.
* **Exibição Detalhada:** Apresenta todas as informações das cartas (cadastradas e calculadas) de forma clara.
* **Batalha de Atributos:** Compara as duas cartas em seus atributos numéricos, identificando a vencedora para cada categoria (com lógica especial para densidade populacional, onde o menor valor ganha).

## 💡 Conceitos Abordados

Este projeto foi desenvolvido para praticar e consolidar conhecimentos em:

* **Programação Estruturada:** Organização do código em blocos lógicos.
* **Tipos de Dados e Variáveis:** Uso adequado de `char`, `int`, `unsigned long int`, `float` e `double`.
* **Operadores:** Aplicação de operadores matemáticos e relacionais.
* **Entrada e Saída:** Interação com o usuário via `printf()` e `scanf()`.
* **Structs:** Organização de dados relacionados em uma única estrutura.
* **Tratamento de Buffer:** Gerenciamento da entrada do teclado para evitar erros.
