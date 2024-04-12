/*============================================================================*/
/* ICSF13 - 2023-2 - TRABALHO 1                                               */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu                                                            */
/* Leyza E. B. Dorini                                                         */
/* Daniel F. Pigatto                                                          */
/*============================================================================*/
/** Fun��es pedidas e auxiliares para o 1o trabalho da disciplina Fundamentos
 * de Programa��o 1, 2o semestre de 2023, profs. Bogdan T. Nassu, Leyza E. B.
 * Dorini e Daniel F. Pigatto, Universidade Tecnol�gica Federal do Paran�. */
/*============================================================================*/

#include <stdio.h>
#include <stdlib.h>

/*============================================================================*/
/* RET�NGULOS                                                                 */
/*============================================================================*/
/* Tipos internos. */

typedef struct
{
    int x;
    int y;
} Coordenada;

typedef struct
{
    Coordenada tl;
    Coordenada br;
} Retangulo;

Retangulo* retangulos; /* Esta vari�vel � global somente para isolar parte do trabalho dos alunos. */

/*----------------------------------------------------------------------------*/
/** Fun��es para manipular o vetor de ret�ngulos. */

void criaVetorRetangulos (int tamanho)
{
    retangulos = (Retangulo*) malloc (sizeof (Retangulo) * tamanho);
}

void destroiVetorRetangulos ()
{
    free (retangulos);
}

void adicionaRetangulo (int pos, int tlx, int tly, int brx, int bry)
{
    retangulos [pos].tl.x = tlx;
    retangulos [pos].tl.y = tly;
    retangulos [pos].br.x = brx;
    retangulos [pos].br.y = bry;
}

void mostraRetangulos (int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf ("(%d,%d) (%d,%d)\n", retangulos [i].tl.x, retangulos [i].tl.y, retangulos [i].br.x, retangulos [i].br.y);
}

int pegaXSE (int pos) {return (retangulos [pos].tl.x);}
int pegaYSE (int pos) {return (retangulos [pos].tl.y);}
int pegaXID (int pos) {return (retangulos [pos].br.x);}
int pegaYID (int pos) {return (retangulos [pos].br.y);}

/*============================================================================*/
