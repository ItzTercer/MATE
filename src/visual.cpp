#include "calc.h"

void calc_mate::iniciar() {
    int opcion;
    std::string cadena;

    while (true) {
            std::cout << "\n\033[1m\033[38;5;18m====\033[38;5;19m====\033[38;5;20m====\033[38;5;21m=========\033[38;5;20m====\033[38;5;19m====\033[38;5;18m====\033[0m\n"
                    "               \033[1m\033[38;5;19mMATE\033[0m\n"            
                    "\033[1m\033[38;5;18m====\033[38;5;19m====\033[38;5;20m====\033[38;5;21m=========\033[38;5;20m====\033[38;5;19m====\033[38;5;18m====\033[0m\n"
                    "\033[38;5;18m1. \033[38;5;19m+ \033[38;5;20mSumar\n"
                    "\033[38;5;18m2. \033[38;5;19m- \033[38;5;20mRestar \n"
                    "\033[38;5;18m3. \033[38;5;19m× \033[38;5;20mMultiplicar \n"
                    "\033[38;5;18m4. \033[38;5;19m÷ \033[38;5;20mDividir     \n"
                    "\033[38;5;18m5. \033[38;5;19m⌃ \033[38;5;20mExponente   \n"
                    "\033[38;5;18m6. \033[38;5;19mlog \033[38;5;20mLogaritmo \n"
                    "\033[38;5;18m7. \033[38;5;19m√ \033[38;5;20mRaíz        \n"
                    "\033[38;5;18m8. \033[38;5;160m⊗ Salir       \033[0m\n";
        
        if (!(std::cin >> opcion)) {
            break;
        }
        if (opcion == eleccion_salir) {
            break;
        }
        if (opcion < eleccion_suma || opcion > eleccion_salir) {
            std::cout << "Opción no válida.\n";
            continue;
        }

        switch (opcion) {
            //Suma y Resta
            case eleccion_suma:
            case eleccion_resta:
                std::cout << "Ingrese su valor inicial (Puede usar e/pi): ";
                resultado_actual = verificador_constantes();
                
                while (true) {
                    std::cout << "\nAcumulado: " << std::fixed << std::setprecision(6) << resultado_actual << "\n";
                    std::cout << "Ingrese un siguiente número (o presione 's' para salir al menú): ";
                    std::cin >> cadena;

                    if (cadena == "s") {
                        break;
                    }
                    
                    double nuevo_valor;
                    if (cadena == "e") {
                        nuevo_valor = constante_e;
                    } else if (cadena == "pi") {
                        nuevo_valor = constante_pi;
                    } else {
                        nuevo_valor = std::stod(cadena);
                    }
                    
                    if (opcion == eleccion_suma) {
                        resultado_actual = sumar(resultado_actual, nuevo_valor);
                    } else {
                        resultado_actual = restar(resultado_actual, nuevo_valor);
                    }
                    verificador_infinito(resultado_actual);
                }
                break;
            
            //Potencia    
            case eleccion_potencia:
                std::cout << "Inserte la base: ";
                primer_valor = verificador_constantes();
                std::cout << "Inserte el exponente: ";
                segundo_valor = verificador_constantes();
                resultado_actual = potencia(primer_valor, segundo_valor);
                break;
            
            //Logaritmo
            case eleccion_logaritmo:
                std::cout << "Inserte la base: "; 
                primer_valor = verificador_constantes();
                std::cout << "Inserte argumento: "; 
                segundo_valor = verificador_constantes();
                if (primer_valor > 0 && primer_valor != 1 && segundo_valor > 0) {
                    resultado_actual = logaritmo(primer_valor, segundo_valor);
                } else { 
                    std::cout << "\nError: Dominio logaritmo inválido (Base > 0 y distinta de 1, Argumento > 0)\n"; 
                    continue; 
                }
                break;

            //Raiz
            case eleccion_raiz:
                std::cout << "Inserte el índice de la raíz: "; 
                primer_valor = verificador_constantes();
                if (primer_valor <= 0) {
                    std::cout << "\nEl índice no puede ser negativo o cero\n";
                    continue;
                }
                std::cout << "Inserte Radicando (lo que esta dentro de la raíz): "; 
                segundo_valor = verificador_constantes();
                if (segundo_valor < 0) {
                    int parte_entera_indice = (int)primer_valor;
                    if (primer_valor != parte_entera_indice || parte_entera_indice % 2 == 0) {
                        std::cout << "\nError: Radicando negativo requiere índice entero impar.\n";
                        continue;
                    }
                }
                resultado_actual = raiz_n(primer_valor, segundo_valor);
                break;

            //Multiplicar y Dividir
            case eleccion_multiplicar:
            case eleccion_dividir:
                std::cout << "Ingrese un primer número: "; 
                primer_valor = verificador_constantes();
                std::cout << "Ingrese un segundo número: "; 
                segundo_valor = verificador_constantes();
                
                if (opcion == eleccion_multiplicar) {
                    resultado_actual = multiplicar(primer_valor, segundo_valor);
                } else {
                    if (segundo_valor != 0) {
                        resultado_actual = dividir(primer_valor, segundo_valor);
                    } else { 
                        std::cout << "Error: División por cero.\n"; 
                        continue; 
                    }
                }
                break;
        }

        //Infinito
        if (opcion != eleccion_suma && opcion != eleccion_resta) {
            verificador_infinito(resultado_actual);
            std::cout << "\nResultados: " << std::fixed << std::setprecision(6) << resultado_actual << "\n";
        }
    }
}
