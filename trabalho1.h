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

#ifndef __TRABALHO1_H
#define __TRABALHO1_H

/*============================================================================*/
/* Fun��es do trabalho. */

int calculaInterseccao (int n_retangulos);
unsigned int encontraParMaisProximo (int n_retangulos);

/*----------------------------------------------------------------------------*/
/* Fun��es auxiliares que DEVEM ser chamadas pelos alunos. */

int pegaXSE (int pos);
int pegaYSE (int pos);
int pegaXID (int pos);
int pegaYID (int pos);

/*----------------------------------------------------------------------------*/
/* Fun��es auxiliares que N�O DEVEM ser chamadas pelos alunos. */

void criaVetorRetangulos (int tamanho);
void destroiVetorRetangulos ();
void adicionaRetangulo (int pos, int tlx, int tly, int brx, int bry);
void mostraRetangulos (int n);

/*============================================================================*/
#endif /* __TRABALHO1_H */

