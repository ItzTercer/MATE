#include "calc.h"

int main(void) {
    int opcion;
    double val1;
    double val2;
    double resultado_actual;
    char texto_ingresado[32];

    while (1) {
        printf("\n=================================\n");
        printf("               MATE\n");
        printf("=================================\n");
        printf("1. + Sumar \n2. - Restar \n3. × Multiplicar \n4. ÷ Dividir \n5. ⌃ Exponente \n6. log Logaritmo \n7. √ Raíz \n8. ⊗ Salir \n");
        printf("Seleccione una opción: ");
        
        if (scanf("%d", &opcion) != 1) {
            break;
        }
        if (opcion == OPCION_SALIR) {
            break;
        }
        if (opcion < OPCION_SUMA || opcion > OPCION_SALIR) {
            printf("Opción no válida.\n");
            continue;
        }

        switch (opcion) {
            
            /* -------------------------------------------
               OPERACIONES DE SUMA Y RESTA (ACUMULATIVAS)
               ------------------------------------------- */
            case OPCION_SUMA:
            case OPCION_RESTA:
                printf("Ingrese su valor inicial (Puede usar e/pi): ");
                resultado_actual = simbolos_unicos();
                
                while (1) {
                    printf("\nAcumulado: %.6lf\n", resultado_actual);
                    printf("Ingrese un siguiente número (o presione 's' para salir al menú): ");
                    scanf("%s", texto_ingresado);
                    
                    if (strcmp(texto_ingresado, "s") == 0) {
                        break;
                    }
                    
                    double nuevo_valor;
                    if (strcmp(texto_ingresado, "e") == 0) {
                        nuevo_valor = n_e;
                    } else if (strcmp(texto_ingresado, "pi") == 0) {
                        nuevo_valor = n_pi;
                    } else {
                        nuevo_valor = atof(texto_ingresado);
                    }
                    
                    if (opcion == OPCION_SUMA) {
                        resultado_actual = sumar(resultado_actual, nuevo_valor);
                    } else {
                        resultado_actual = restar(resultado_actual, nuevo_valor);
                    }
                    verificar_magnitud(resultado_actual);
                }
                break;

            /* -------------------------------------------
               OPERACIÓN DE EXPONENTE
               ------------------------------------------- */
            case OPCION_EXPONENTE:
                printf("Inserte la base: "); 
                val1 = simbolos_unicos();
                printf("Inserte el exponente: "); 
                val2 = simbolos_unicos();
                resultado_actual = potencia(val1, val2);
                break;

            /* -------------------------------------------
               OPERACIÓN DE LOGARITMO
               ------------------------------------------- */
            case OPCION_LOGARITMO:
                printf("Inserte la base: "); 
                val1 = simbolos_unicos();
                printf("Inserte argumento: "); 
                val2 = simbolos_unicos();
                if (val1 > 0 && val1 != 1 && val2 > 0) {
                    resultado_actual = logaritmo(val1, val2);
                } else { 
                    printf("\nError: Dominio logaritmo inválido (Base > 0 y distinta de 1, Argumento > 0)\n"); 
                    continue; 
                }
                break;

            /* -------------------------------------------
               OPERACIÓN DE RAÍZ
               ------------------------------------------- */
            case OPCION_RAIZ:
                printf("Inserte el índice de la raíz: "); 
                val1 = simbolos_unicos();
                if (val1 <= 0) {
                    printf("\nEl índice no puede ser negativo o cero\n");
                    continue;
                }
                printf("Inserte Radicando (lo que esta dentro de la raíz): "); 
                val2 = simbolos_unicos();
                if (val2 < 0) {
                    int val1_int = (int)val1;
                    if (val1 != val1_int || val1_int % 2 == 0) {
                        printf("\nError: Radicando negativo requiere índice entero impar.\n");
                        continue;
                    }
                }
                resultado_actual = raiz_n(val1, val2);
                break;

            /* -------------------------------------------
               OPERACIONES DE MULTIPLICACIÓN Y DIVISIÓN
               ------------------------------------------- */
            case OPCION_MULTIPLICAR:
            case OPCION_DIVIDIR:
                printf("Ingrese un primer número: "); 
                val1 = simbolos_unicos();
                printf("Ingrese un segundo número: "); 
                val2 = simbolos_unicos();
                
                if (opcion == OPCION_MULTIPLICAR) {
                    resultado_actual = multiplicar(val1, val2);
                } else {
                    if (val2 != 0) {
                        resultado_actual = dividir(val1, val2);
                    } else { 
                        printf("Error: División por cero.\n"); 
                        continue; 
                    }
                }
                break;
        }

        /* -------------------------------------------
           IMPRESIÓN FINAL PARA OPERACIONES NO ACUMULATIVAS
           ------------------------------------------- */
        if (opcion != OPCION_SUMA && opcion != OPCION_RESTA) {
            verificar_magnitud(resultado_actual);
            printf("\nResultado final: %.6lf\n", resultado_actual);
        }
    }
    return 0;
}