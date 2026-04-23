#include "calc.h"

int main(void) {
    int opcion;
    double val1;
    double val2;
    double sim_esp;
    char tcad[32];

    while (1) {
        printf("\n=================================\n");
        printf("           Count Play\n");
        printf("=================================\n");
        printf("1. + Sumar \n2. - Restar \n3. × Multiplicar \n4. ÷ Dividir \n5. ⌃ Exponente \n6. log Logaritmo \n7. √ Raíz \n8. ⊗ Salir \n");
        printf("Seleccione una opción: ");
        
        if (scanf("%d", &opcion) != 1) {
            break;
        }

        if (opcion == 8) {
            break;
        }

        if (opcion < 1 || opcion > 8) {
            printf("Opción no válida.\n");
            continue;
        }

        if (opcion == 1 || opcion == 2) {
            printf("Ingrese su valor inicial (Puede usar e/pi): ");
            sim_esp = simbolos_unicos();

            while (1) {
                printf("\nAcumulado: %.6lf\n", sim_esp);
                printf("Ingrese un siguiente número (o presione 's' para salir al menú): ");
                scanf("%s", tcad);

                if (strcmp(tcad, "s") == 0) {
                    break;
                }

                double n_v;
                if (strcmp(tcad, "e") == 0) {
                    n_v = n_e;
                } else if (strcmp(tcad, "pi") == 0) {
                    n_v = n_pi;
                } else {
                    n_v = atof(tcad);
                }

                sim_esp = (opcion == 1) ? sumar(sim_esp, n_v) : restar(sim_esp, n_v);
            }
        } 
        else if (opcion == 5) {
            printf("Inserte la base: "); 
            val1 = simbolos_unicos();

            printf("Inserte el exponente: "); 
            val2 = simbolos_unicos();

            sim_esp = potencia(val1, val2);
        } 
        else if (opcion == 6) {
            printf("Inserte la base: "); 
            val1 = simbolos_unicos();

            printf("Inserte argumento: "); 
            val2 = simbolos_unicos();

            if (val1 > 0 && val1 != 1 && val2 > 0) {
                sim_esp = logaritmo(val1, val2);
            } else { 
                printf("Error: Dominio logaritmo inválido (Base > 0 y distinta de 1, Argumento > 0)\n"); 
                continue; 
            }
        } 
        else if (opcion == 7) {
            printf("Inserte el índice de la raíz: "); 
            val1 = simbolos_unicos();

            printf("Radical (lo que esta dentro de la raíz): "); 
            val2 = simbolos_unicos();

            sim_esp = raiz_n(val1, val2);
        } 
        else {
            printf("Ingrese un primer número: "); 
            val1 = simbolos_unicos();

            printf("Ingrese un segundo número: "); 
            val2 = simbolos_unicos();

            if (opcion == 3) {
                sim_esp = multiplicar(val1, val2);
            } else if (val2 != 0) {
                sim_esp = dividir(val1, val2);
            } else { 
                printf("Error: División por cero.\n"); 
                continue; 
            }
        }

        printf("\nResultado final: %.6lf\n", sim_esp);
    }

    return 0;
}