#include "calc.h"

int main(void) {
    int opcion;
    double n1, n2, res;

    while (1) {
        printf("\n=================================\n");
        printf("           Count Play\n");
        printf("=================================\n");
        printf("1. Sumar\n2. Restar\n3. Multiplicar\n4. Dividir\n5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 5) break;
        
        if (opcion < 1 || opcion > 5) {
            printf("Opcion no valida.\n");
            continue;
        }

        printf("Ingrese primer numero: ");
        scanf("%lf", &n1);
        printf("Ingrese segundo numero: ");
        scanf("%lf", &n2);

        if (opcion == 1) res = sumar(n1, n2);
        else if (opcion == 2) res = restar(n1, n2);
        else if (opcion == 3) res = multiplicar(n1, n2);
        else if (opcion == 4) {
            if (n2 != 0) res = dividir(n1, n2);
            else {
                printf("Error: Division por cero.\n");
                continue;
            }
        }
        
        printf("Resultado: %.2lf\n", res);
    }
    return 0;
}