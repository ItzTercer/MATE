#include "calc.h"


void calc_mate::iniciar() {
    int opcion;
    std::string cadena;

    while (true) {
        //menu
        std::cout << "\n\033[1m\033[38;5;18m====\033[38;5;19m====\033[38;5;20m====\033[38;5;21m=======\033[38;5;20m====\033[38;5;19m====\033[38;5;18m=====\033[0m\n"
                    "  \033[1m\033[38;5;45m■══════════ MATE ══════════■\033[0m\n"            
                    "\033[1m\033[38;5;18m====\033[38;5;19m====\033[38;5;20m====\033[38;5;21m=======\033[38;5;20m====\033[38;5;19m====\033[38;5;18m=====\033[0m\n"
                    "\033[38;5;69m1. \033[38;5;69m+ \033[38;5;69mSumar\n"
                    "\033[38;5;69m2. \033[38;5;69m- \033[38;5;69mRestar \n"
                    "\033[38;5;69m3. \033[38;5;69m× \033[38;5;69mMultiplicar \n"
                    "\033[38;5;69m4. \033[38;5;69m÷ \033[38;5;69mDividir     \n"
                    "\033[38;5;69m5. \033[38;5;69m⌃ \033[38;5;69mExponente   \n"
                    "\033[38;5;69m6. \033[38;5;69mlog \033[38;5;69mLogaritmo \n"
                    "\033[38;5;69m7. \033[38;5;69m√ \033[38;5;69mRaíz        \n"
                    "\033[38;5;220m8. \033[38;5;220m≡ Formulario y Aprendizaje \n"
                    "\033[38;5;9m9. \033[38;5;9m⊗ Salir       \033[0m\n";
        
        //entrada
        if (!(std::cin >> opcion)) {
            break;
        }
        if (opcion == eleccion_salir) {
            break;
        }
        if (opcion < eleccion_suma || opcion > eleccion_salir) {
            std::cout << "\n\033[38;5;124mOpción no válida.\033[0m\n";
            continue;
        }

        //casos
        switch (opcion) {
            
            //suma y resta
            case eleccion_suma:
            case eleccion_resta:
                std::cout << "Ingrese su valor inicial (Puede usar e/pi): ";
                resultado_actual = verificador_constantes();
                while (true) {
                    std::cout << "\nAcumulado: ";
                    if (std::isinf(resultado_actual)) {
                        std::cout << "\033[1m\033[38;5;82m" << "\u221E Infinito" << "\033[0m\n";
                    } else {
                        std::cout << "\033[1m\033[38;5;82m" << std::fixed << std::setprecision(6) << resultado_actual << "\033[0m\n";
                    }
                    std::cout << "Ingrese un siguiente número (o presione '\033[1m\033[38;5;124ms\033[0m' para salir al menú): ";
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
            
            //potencia
            case eleccion_potencia:
                std::cout << "Inserte la base: ";
                primer_valor = verificador_constantes();
                std::cout << "Inserte el exponente: ";
                segundo_valor = verificador_constantes();
                resultado_actual = potencia(primer_valor, segundo_valor);
                break;
            
            //log
            case eleccion_logaritmo:
                std::cout << "Inserte la base: "; 
                primer_valor = verificador_constantes();
                std::cout << "Inserte argumento: "; 
                segundo_valor = verificador_constantes();
                if (primer_valor > 0 && primer_valor != 1 && segundo_valor > 0) {
                    resultado_actual = logaritmo(primer_valor, segundo_valor);
                } else { 
                    std::cout << "\n\033[38;5;124mError: Dominio logaritmo inválido (Base > 0 y distinta de 1, Argumento > 0)\033[0m\n"; 
                    continue; 
                }
                break;

            //raiz
            case eleccion_raiz:
                std::cout << "Inserte el índice de la raíz: "; 
                primer_valor = verificador_constantes();
                if (primer_valor <= 0) {
                    std::cout << "\n\033[38;5;124mEl índice no puede ser negativo o cero\033[0m\n";
                    continue;
                }
                std::cout << "Inserte Radicando (lo que esta dentro de la raíz): "; 
                segundo_valor = verificador_constantes();
                if (segundo_valor < 0) {
                    int parte_entera_indice = (int)primer_valor;
                    if (primer_valor != parte_entera_indice || parte_entera_indice % 2 == 0) {
                        std::cout << "\n\033[38;5;124mError: Radicando negativo requiere índice entero impar.\033[0m\n";
                        continue;
                    }
                }
                resultado_actual = raiz_n(primer_valor, segundo_valor);
                break;

            //multi y divición
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
                        std::cout << "\033[38;5;124mError: División por cero.\033[0m\n"; 
                        continue; 
                    }
                }
                break;

            //Hito 3
            case eleccion_formulario:
                formulario.formulario_visual();
                break;
        }

        if (opcion != eleccion_suma && opcion != eleccion_resta && opcion != eleccion_formulario) {
            verificador_infinito(resultado_actual);
            std::cout << "\nResultados: ";
            if (std::isinf(resultado_actual)) {
                std::cout << "\033[1m\033[38;5;82m" << "\u221E Infinito" << "\033[0m\n";
            } else {
                std::cout << "\033[1m\033[38;5;82m" << std::fixed << std::setprecision(6) << resultado_actual << "\033[0m\n";
            }
        }
    }
}