<div align="center">
  <img src="logo2.png" width="300" alt="Logo MATE">
</div>

# MATE: Calculadora Dinámica para Estudiantes

## 1. Resumen de la problemática
Muchos estudiantes de nivel escolar presentan dificultades para comprender conceptos matemáticos de forma práctica y visual. Las calculadoras tradicionales suelen entregar resultados finales sin facilitar la comprensión del proceso o la visualización de funciones. **MATE** aborda esta carencia mediante un entorno interactivo diseñado para fortalecer el aprendizaje matemático a través de la experimentación y una mejor visualización.

## 2. Objetivos del Proyecto
### Objetivo General
Desarrollar una calculadora en C++ que permita resolver operaciones matemáticas, entregar información a modo de formulario para el aprendizaje y que pueda graficar funciones en un entorno visual, con el fin de apoyar el aprendizaje en estudiantes de enseñanza media.

### Objetivos Específicos (Hito 2)

- Migrar la totalidad del código fuente desde el lenguaje estructurado C hacia C++ , adoptando un diseño guiado por los principios de la Programación Orientada a Objetos (POO).  
- Aplicar de forma justificada el concepto de composición estructural , integrando el objeto de aprendizaje dentro de la entidad matemática para segmentar las responsabilidades del sistema.  
- Modularización de Archivos: Separar rigurosamente el desarrollo en archivos de cabecera (`.h` o `.hpp`) para la declaración de estructuras y archivos de implementación (.cpp).  
- Optimización y Control de Errores: Incorporar una función de control de desbordamiento mediante el uso de herramientas de la biblioteca estándar (`<cmath>`) para interceptar y advertir al usuario sobre magnitudes numéricas que tiendan al infinito.  
- Corregir las observaciones de la entrega anterior, modificando la nomenclatura de las variables y documentando los bloques lógicos con comentarios para maximizar la legibilidad.  
- Diseño de Interfaz en Consola: Implementar códigos de escape ANSI para incorporar colores en el entorno de la terminal, mejorando la experiencia visual del usuario y la jerarquía de los mensajes de error.
- Proyección Arquitectónica: Desarrollar un apartado de "Formulario y Aprendizaje" de manera desacoplada , sentando las bases estructurales y lógicas necesarias para facilitar la posterior migración hacia un entorno gráfico (GUI) en el Hito 3. 

## 3. Roles del Equipo
| Integrante | Rol |
| :--- | :--- |
| **Allison** | Frontend / Programadora |
| **Sibel** | Programadora / Editora |
| **Alex** | Administrador de Proyecto |
| **Benjamin** | Programador Backend |
| **Esteban** | Programador Backend |

## 4. Requerimientos y Compilación
El software ha sido desarrollado siguiendo estándares para sistemas GNU/Linux, utilizando herramientas nativas de C++.

### Requisitos del Sistema
- **Sistema Operativo**: Distribuciones GNU/Linux (Ubuntu, Linux Mint, Arch, etc.).
- **Compilador**: G++ (GNU Compiler Collection para C++).
- **Librerías**: Biblioteca estándar de C++ (`<iostream>`, `<cmath>`, `<string>`, `<vector>`, `<iomanip>`).

### Instrucciones de Instalación y Ejecución
Ejecutar los siguientes comandos secuencialmente en la terminal:

```bash
# 1. Clonar el repositorio localmente
git clone https://github.com/ItzTercer/MATE.git

# 2. Acceder al directorio raíz del proyecto
cd MATE

# 3. Compilar el código fuente enlazando todos los archivos .cpp
g++ src/main.cpp src/calc.cpp src/visual.cpp src/formulario.cpp -o mate

# 4. Iniciar el programa
./mate
```

## 5. Migración Estructural y Diseño Orientado a Objetos (Interno - Hito 2)
El proyecto fue reescrito de C a C++ implementando los pilares de la Programación Orientada a Objetos para separar responsabilidades lógicas y visuales.

### Modelado de Clases y Responsabilidades   
- Clase `calc_mate`: Entidad principal encargada de procesar las operaciones aritméticas. Utiliza encapsulamiento estricto declarando variables de estado (resultado_actual, primer_valor, segundo_valor) como atributos privados. Expone métodos públicos para operaciones y controla la validación de constantes matemáticas e infinitos.

- Clase `formulario_aprendizaje`: Entidad independiente diseñada para manejar la visualización teórica (fórmulas y propiedades). Su creación aísla el contenido de aprendizaje del motor de cálculo bruto.

  Se implementó Composición para estructurar el programa. La clase `calc_mate` posee un objeto privado de tipo `formulario_aprendizaje` (`formulario_aprendizaje formulario;`). Esto justifica que la calculadora "tiene un" módulo de aprendizaje que puede invocar cuando el usuario lo requiera a través de la interfaz, manteniendo la separación de conceptos.

## 6. Funcionalidades Implementadas y Pruebas

### Funcionalidades Implementadas
- **Operaciones Matemáticas Conservadas:** Mantenimiento íntegro de la lógica aritmética básica (suma, resta, multiplicación, división) y avanzada (potencias, logaritmos, raíces n-ésimas) desarrollada en el Hito 1.
- **Diseño de Interfaz en Consola mediante Colores:** Implementación de códigos de escape ANSI en el entorno de la terminal para dotar al programa de una jerarquía visual clara. Se asignaron colores específicos para diferenciar de forma intuitiva los títulos de los menús, los acumulados numéricos, las opciones disponibles y las alertas.
- **Control de Desbordamiento:** Implementación de un verificador de magnitud (`verificador_infinito`) que despliega una advertencia visual estructurada al detectar resultados que exceden el límite de procesamiento y tienden a infinito. El control de desbordamiento se implementó utilizando la función `std::isinf` perteneciente a la biblioteca matemática estándar de C++ `cmath`.
- **Refactorización y Legibilidad:** Modificación de la nomenclatura de variables para estandarizar el código. Segmentación de bloques lógicos mediante comentarios descriptivos para facilitar la lectura, auditoría y el mantenimiento.
- **Reconocimiento de Constantes:** Procesamiento continuo de entradas de texto para conversión automática de constantes universales (`e`, `pi`) a valores numéricos de alta precisión.
- **Estructura Base para Interfaz Visual:** Incorporación de la clase `formulario_aprendizaje` que proyecta la visualización teórica de propiedades matemáticas para la fase posterior del proyecto.

### Casos de Prueba (Validación)
| Operación | Entradas | Salida Esperada | Estado |
| :--- | :--- | :--- | :--- |
| Suma Acumulada | `pi`, `e`, `s` | `Acumulado: 5.859874` | Exitoso |
| División por Cero | `10`, `0` | `Error: División por cero.` | Exitoso |
| Logaritmo Válido | Base: `10`, Arg: `100` | `Resultados: 2.000000` | Exitoso |
| Raíz n-ésima Negativa | Índice: `3`, Radical: `-27` | `Resultados: -3.000000` | Exitoso |
| Desbordamiento (Infinito) | Opción: `5`, Base: `1000`, Exp: `500` | `[ADVERTENCIA] Magnitud máxima excedida... Resultados: ∞ Infinito` | Exitoso |
| Formulario Visual | Opción `8` | `[ MENSAJE IMPORTANTE ] Esta sección se encuentra en desarrollo...` | Exitoso |

## 7. Dificultades y Próximos Pasos

### Principales Dificultades
- **Reestructuración del Código:** Cambiar el paradigma de programación estructurada en C del Hito 1 hacia un diseño de Programación Orientada a Objetos (POO) en C++.
- **Equilibrio entre Requerimientos Actuales y Escalabilidad Futura:** Diseñar el software cumpliendo de forma estricta las exigencias del Hito 2 (como la composición y la modularización en archivos de cabecera) , manteniendo al mismo tiempo una visión arquitectónica hacia el Hito 3.

### Próximos Pasos (Hito 3)
- **Desarrollo de la Interfaz Gráfica de Usuario (GUI):** Transicionar por completo el proyecto desde el entorno de terminal basado en texto hacia una aplicación de escritorio visual e interactiva, utilizando el framework Qt como herramienta principal de desarrollo.
- **Migración del Menú y Flujo de Control:** Reemplazar el bucle secuencial (`while`) y las capturas de teclado por consola del menú actual por un sistema dirigido por eventos, donde las opciones se desplieguen mediante una botonera gráfica y contenedores visuales.
- **Implementación Definitiva del Módulo de Aprendizaje:** Evolucionar la clase `formulario_aprendizaje` creada en este hito hacia una interfaz interactiva dentro de la GUI, permitiendo el despliegue dinámico y legible de propiedades, identidades trigonométricas y productos notables.
- **Incorporación de Motor de Graficación:** Diseñar y añadir un módulo completamente nuevo dentro de la aplicación para el renderizado visual de funciones matemáticas simples en un plano cartesiano.
- **Consolidación Estética y Funcional:** Dotar al proyecto de un sentido de software profesional y unificado, logrando que el motor de cálculo matemático se integre de forma natural con los componentes visuales de la interfaz de usuario.

## 8. Gestión del Proyecto en GitHub
- Milestone Hito 2: Activo y configurado con la fecha de entrega y objetivos del ciclo. 
- Project Board: Flujo de trabajo segmentado en To-Do, Doing y Done. Se evidencia el desplazamiento de issues completadas. El project board, es el mismo del hito 1, pero posee una segmentacion que indica las tareas según hito.
- Issues: Documentación de tareas individuales asignadas a los integrantes con etiquetas correspondientes.  
- AI_USAGE.md: Registro actualizado de prompts, herramientas utilizadas y limitaciones identificadas durante la migración a C++.

## 9. Anexos y Referencias

### Enlaces Oficiales del Proyecto
- **Repositorio de GitHub:** https://github.com/ItzTercer/MATE

### Documentación Adicional
- **`AI_USAGE.md`**: Registro detallado de herramientas, prompts, observaciones y limitaciones de los modelos de inteligencia artificial generativa empleados durante la migración del código.

### Referencias Técnicas y Bibliográficas
* Documentación de la biblioteca estándar de C++ (`cppreference.com`) utilizada para la implementación de métodos matemáticos y el control de desbordamiento de memoria (`std::isinf`).
* Documentación sobre secuencias de escape ANSI para la manipulación de colores.