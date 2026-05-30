# Uso de Inteligencia Artificial - Proyecto MATE

Este documento registra el uso de herramientas de Inteligencia Artificial Generativa durante el ciclo de desarrollo del proyecto.

## Herramienta Utilizada
* **Modelo de IA:** Gemini Pro 3.1

---

## Aplicación en el Desarrollo (Hito 2)

**1. Control de Desbordamiento de Magnitud**
* **Descripción:** Se utilizó la IA para identificar una función dentro de la biblioteca matemática estándar de C++ capaz de resolver el problema de desbordamiento de memoria al calcular magnitudes muy grandes. Esto derivó en la implementación de `std::isinf` para interceptar resultados que tienden a infinito.
* **Prompt** *"¿Qué función o librería de la biblioteca estándar de C++ puedo usar para detectar si el resultado de una operación matemática excede el límite físico de un double y arroja infinito?"*

**2. Implementación de Interfaz Visual en Consola (Códigos ANSI)**
* **Descripción:** Asistencia para seleccionar e incorporar colores en el entorno de la terminal. La IA informó sobre la sintaxis exacta de los códigos de escape ANSI (`\033[...]`) y la metodología para integrarlos en los flujos de salida, logrando diferenciar menús, resultados y mensajes de error.
* **Prompt** *"¿Cuáles son los códigos de escape ANSI para imprimir texto con colores en la consola de Linux usando C++? Dame la sintaxis exacta para implementarlos con std::cout y ejemplos para los colores rojo, verde y amarillo."*

**3. Control de Precisión Decimal**
* **Descripción:** Sugerencia y aplicación técnica de la librería `<iomanip>`. Se utilizó para estandarizar la salida de los números decimales mediante `std::fixed` y `std::setprecision(6)`, evitando notaciones científicas automáticas en la lectura del acumulado.
* **Prompt** *"¿Cómo puedo limitar y fijar la cantidad de decimales que se imprimen en consola con std::cout en C++ para que siempre muestre exactamente 6 dígitos?"*

**4. Corrección de Estilo y Ortografía**
* **Descripción:** Revisión general de sintaxis, ortografía y estructura de formato Markdown para los documentos del repositorio (`README.md` y `AI_USAGE.md`). La IA optimizó la redacción para dotar a la entrega de una presentación estética y profesional.
* **Prompt** *"Revisa el siguiente texto destinado a la documentación en GitHub. Corrige los errores ortográficos y asegúrate de que el formato Markdown sea estéticamente ordenado."*

**5. Proyección de Contenido para el Formulario (Hito 3)**
* **Descripción:** Búsqueda de sugerencias teóricas y estructuración de conceptos matemáticos (productos notables, propiedades de logaritmos, identidades trigonométricas). Estas ideas se validaron y almacenaron como base de datos estática para su futura implementación en el entorno gráfico del Hito 3.
* **Prompt** *"Pensando en desarrollar un software educativo interactivo, sugiere una lista jerarquizada de temas matemáticos, fórmulas y propiedades útiles para estudiantes de enseñanza media que pueda integrar en un apartado visual llamado 'Formulario y Aprendizaje'."*

---

## Historial de Uso (Hito 1)

**1. Formateo de documentación**
* **Descripción:** Definición y aplicación del formato de bloques de código tipo `bash` en el archivo `README.md` para clarificar las instrucciones de instalación y compilación.
* **Prompt** *"Cómo aplicar formato bash a las instrucciones de ejecución en GitHub para mejorar su legibilidad."*

**2. Lógica para Raíces con Radicales Negativos**
* **Descripción:** Asistencia en la implementación de la función matemática para calcular raíces. La IA ayudó a estructurar la lógica necesaria para manejar radicales negativos con índices impares, evadiendo la limitación de la función nativa `pow()`.
* **Prompt** *"Lógica en lenguaje C para calcular raíces de números negativos mediante la extracción del signo y el cálculo sobre su valor absoluto, evadiendo el error de la biblioteca matemática."*

**3. Procesamiento de strings**
* **Descripción:** Sugerencia técnica para la conversión de cadenas de caracteres a valores de tipo `double`, facilitando la interpretación de constantes literales (`e`, `pi`) ingresadas por el usuario.
* **Prompt** *"Cómo transformar un string numérico leído por scanf a un número de punto flotante. Alternativas para interpretar números ingresados como texto en C."*