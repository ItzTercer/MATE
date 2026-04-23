<div align="center">
  <img src="logo2.png" width="300" alt="Logo MATE">
</div>

# MATE: Calculadora Dinámica para Estudiantes

## 1. Resumen de la problemática
Muchos estudiantes de nivel escolar presentan dificultades para comprender conceptos matemáticos de forma práctica y visual. Las calculadoras tradicionales suelen entregar resultados finales sin facilitar la comprensión del proceso o la visualización de funciones. **MATE** aborda esta carencia mediante un entorno interactivo en lenguaje C diseñado para fortalecer el aprendizaje matemático a través de la experimentación y el cálculo dinámico.

## 2. Objetivos del Proyecto
### Objetivo General
Desarrollar una calculadora en lenguaje C que permita resolver operaciones matemáticas y graficar funciones, con el fin de apoyar el aprendizaje en estudiantes de enseñanza escolar.

### Objetivos Específicos
- Implementar operaciones matemáticas básicas (suma, resta, multiplicación y división) con soporte para múltiples operandos acumulados.
- Implementar funciones avanzadas como exponenciación, logaritmos y raíces n-ésimas.
- Permitir el reconocimiento de constantes matemáticas universales (`e`, `pi`).
- Diseñar una arquitectura modular que facilite la escalabilidad y la transición a interfaces gráficas.
- Validar rigurosamente las entradas del usuario y los dominios matemáticos.

## 3. Roles del Equipo
| Integrante | Rol |
| :--- | :--- |
| **Allison** | Frontend |
| **Sibel** | Programador |
| **Alex** | Administrador |
| **Benjamin** | Programador |
| **Esteban** | Programador |


## 4. Requerimientos y Compilación
El software ha sido desarrollado siguiendo estándares de modularización para sistemas GNU/Linux.

### Requisitos del Sistema
- **Sistema Operativo**: Distribuciones GNU/Linux (Ubuntu, Linux Mint, Arch, etc.).
- **Compilador**: GCC (GNU Compiler Collection).
- **Librerías**: Biblioteca estándar de C y biblioteca matemática (`math.h`).

### Instrucciones de Instalación y Ejecución

Para descargar, compilar y ejecutar el proyecto localmente en un sistema GNU/Linux, ejecute los siguientes comandos secuencialmente en la terminal:

```bash
# 1. Clonar el repositorio localmente
git clone https://github.com/ItzTercer/MATE.git

# 2. Acceder al directorio raíz del proyecto
cd CountPlay

# 3. Compilar el código fuente enlazando la biblioteca matemática (NO OLVIDAR "-lm" DEL FINAL)
gcc src/main.c src/calc.c -o countplay -lm

# 4. Iniciar el programa
./countplay
```
## 5. Funcionalidades Implementadas y Pruebas
Esta versión funcional corresponde al **Hito 1**.

### Descripción de Funcionalidades
1. **Aritmética Acumulativa (N números)**: Implementación de suma y resta con visualización del acumulado en tiempo real. Permite el ingreso infinito de operandos hasta que el usuario utiliza el comando de escape 's'.
2. **Operaciones Binarias**: Multiplicación y división estándar. Incluye una validación lógica para evitar el error de ejecución por división por cero.
3. **Cálculos Avanzados**:
* **Exponenciación**: Cálculo de potencias mediante `pow()`.
* **Logaritmos**: Implementación con cambio de base y validación estricta de dominio (Base > 0, Base ≠ 1, Argumento > 0).
* **Raíz n-ésima**: Cálculo de raíces de cualquier índice mediante exponentes fraccionarios.
4. **Procesador de Símbolos**: La función `simbolos_unicos()` actúa como un analizador léxico básico que reconoce las constantes `e` y `pi` ingresadas como texto, convirtiéndolas a sus valores numéricos de alta precisión.

### Casos de Prueba (Validación)
| Operación | Entradas | Salida Esperada | Estado |
| :--- | :--- | :--- | :--- |
| Suma Acumulada | `pi`, `e`, `s` | `Resultado final: 5.859874` | Exitoso |
| División Inválida | `10`, `0` | `Error: División por cero.` | Exitoso |
| Logaritmo | Base: `10`, Arg: `100` | `Resultado final: 2.000000` | Exitoso |
| Raíz n-ésima | Índice: `3`, Radical: `27` | `Resultado final: 3.000000` | Exitoso |
| Logaritmo Inválido| Base: `-5`, Arg: `10` | `Error: Dominio logaritmo inválido.`| Exitoso |

## 6. Gestión del Proyecto en GitHub
La organización y el seguimiento del desarrollo se centralizan en las herramientas de gestión de GitHub:

- **Milestone Hito 1**: Registra un avance del 100% con 6 de 6 tareas cerradas satisfactoriamente.
- **Project Board**: El tablero "Gestión de Proyecto: CountPlay" organiza el flujo de trabajo mediante columnas *Not-Considered*, *In Progress* y *Done* .
- **Issues**: Se han documentado y asignado tareas específicas como la modularización (#3), lógica de funciones avanzadas (#4) e investigación de frontend (#5), todas en estado finalizado.
- **AI_USAGE.md**: Archivo incluido en la raíz para declarar el uso ético y técnico de herramientas de IA generativa durante la programación y documentación.

## 7. Avance y Próximos Pasos
### Logros Hito 1
* Implementación exitosa del motor matemático con soporte para $N$ números y constantes $e$/$pi$.
* Refactorización del código hacia una arquitectura modular en la carpeta `src/`.
* Configuración completa en un nuevo directorio, debido a error en la creacion de project.

### Objetivos Hito 2
- **Resolución de Bugs**: Corregir la falla de vinculación de señales en botones de la interfaz (Issue #6 en rama `front-end-test`).
- **Desarrollo de GUI**: Transicionar el sistema desde la consola hacia una Interfaz Gráfica de Usuario (GUI) funcional.
- **Motor Gráfico**: Implementar la lógica necesaria para la representación visual de funciones matemáticas.
- **Ampliar la Resolucion de problemas**: Implementar la lógica necesaria para la resolucion de ecuaciones con variables a despejar e implementación de mas funciones matematicas necesarias en la etapa escolar de enseñanza media.

## 8. Referencias
- **ISO/IEC 9899**: Estándar internacional para el lenguaje de programación C.
- **Documentación GCC**: Manuales de referencia para el compilador y la vinculación de la librería matemática `-lm`.
- **GitHub Guides**: Documentación oficial sobre la gestión de *Milestones*, *Projects* e *Issues*.
- **Instrucciones Hito 1**: Documento de requerimientos de la asignatura TEL20125: Seminario de Programación.