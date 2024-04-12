/*============================================================================*/
/* ICSF13 - 2023-2 - TRABALHO 1                                               */
/*----------------------------------------------------------------------------*/
/* Giovanni Mioto    RA: 2603454                                              */
/*============================================================================*/
/** Funções pedidas e auxiliares para o 1o trabalho da disciplina Fundamentos
 * de Programação 1, 2o semestre de 2023, profs. Bogdan T. Nassu, Leyza E. B.
 * Dorini e Daniel F. Pigatto, Universidade Tecnológica Federal do Paraná. */
/*============================================================================*/


#include "trabalho1.h"
#include <math.h>
#include <float.h>

/*============================================================================*/
/* Funções do trabalho. */

int calculaInterseccao (int n_retangulos);
unsigned int encontraParMaisProximo (int n_retangulos);

int calculaInterseccao (int n_retangulos){

    int area, atualXSE, atualYSE, atualXID, atualYID, i;

    //guarda em uma variável auxiliar as coordenadas do primeiro retangulo

    atualXSE = pegaXSE(0);
    atualYSE = pegaYSE(0);
    atualXID = pegaXID(0);
    atualYID = pegaYID(0);

    for( i = 1; i < n_retangulos; i++){

        //Verifica se os pontos do eixo das ordenadas do proximo retangulo estao dentro do retangulo anterior
        if( atualYSE <= pegaYID(i) || atualYID >= pegaYSE(i) ){
            area = 0;
            return area;
        }

        //Verifica se os pontos do eixo das abscissas do proximo retangulo estao dentro do retangulo anterior
        if( atualXSE >= pegaXID(i) || atualXID <= pegaXSE(i) ){
            area = 0;
            return area;
        }

        //Caso o retangulo tenha interseccao com o anterior, calcula as novas extremidades na interseccao
        else
        {
            //Verifica o maior X Superior Esquerdo
            if(pegaXSE(i) > atualXSE){
                atualXSE = pegaXSE(i);
            }
            //Verifica o menor X Inferior Direito
            if(pegaXID(i) < atualXID){
                atualXID = pegaXID(i);
            }
            //Verifica o menor X Inferior Direito
            if(pegaYSE(i) < atualYSE){
                atualYSE = pegaYSE(i);
            }
            //Verifica o maior Y Superior Esquerdo
            if(pegaYID(i) > atualYID){
                atualYID = pegaYID(i);
            }
        }
    }

    //Calcula a area da interseccao entre todos os retangulos, caso haja.
    area = (atualYSE-atualYID) * (atualXID - atualXSE);

    return area;
}

unsigned int encontraParMaisProximo(int n_retangulos) {

    int retangulo_mais_proximo_1,retangulo_mais_proximo_2;
    float distancia, menor_distancia, xcentro_atual, ycentro_atual, xcentro_prox, ycentro_prox;

    menor_distancia = FLT_MAX; // Inicializando a menor distantancia com um valor grande

    //Loop externo para verificar todos os possíveis retangulos
    for (int i = 0; i < n_retangulos; i++) {

        //Calculo x e y centro do retangulo do loop externo
        xcentro_atual = (pegaXID(i)+ pegaXSE(i))/2.0;
        ycentro_atual = (pegaYSE(i)+ pegaYID(i))/2.0;

        //Loop interno para verificar todas possiveis comparaçoes com o loop externo
        for (int j = i + 1; j < n_retangulos; j++) {

            //Calculo x e y centro do retangulo do loop interno
            xcentro_prox = (pegaXID(j)+ pegaXSE(j))/2.0;
            ycentro_prox = (pegaYSE(j)+ pegaYID(j))/2.0;

            //Calcula a distancia dos retangulos analisados no atual estado do loop
            distancia = sqrt((xcentro_atual - xcentro_prox) * (xcentro_atual - xcentro_prox) +
                             (ycentro_atual - ycentro_prox) * (ycentro_atual - ycentro_prox));

            //Verifica a menor distancia calculada ate o momento, e guarda os retangulos analisados
            if (distancia < menor_distancia) {
                menor_distancia = distancia;
                retangulo_mais_proximo_1 = i;
                retangulo_mais_proximo_2 = j;

            }
        }
    }

    // Transorma a posicao para hexadecimal e desloca para a esquerda por 8 bits para adicionar zeros à esquerda
    int numeroFormatado = retangulo_mais_proximo_1 << 16;

    //Adiciona a segunda posicao no numero hexadecimal
    numeroFormatado += retangulo_mais_proximo_2;

    return numeroFormatado;
}




