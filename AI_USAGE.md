# Uso de Inteligencia Artificial - Proyecto MATE

Este documento registra el uso de herramientas de Inteligencia Artificial Generativa durante el ciclo de desarrollo del proyecto.

## Herramientas Utilizadas
* **Hito 3:** Gemini 3.1 Flash (Pensamiento Avanzado)
* **Hito 2:** Gemini Pro 3.1
* **Hito 1:** Gemini Pro 3.1

---

## Aplicación en el Desarrollo (Hito 3)

**1. Soporte e Integración de Imágenes SVG en Qt**
* **Descripción:** Recomendación técnica para la utilización del módulo `QtSvg` y la correcta declaración de vectores dentro del archivo de recursos `Font.qrc` para desplegar las ecuaciones matemáticas sin pérdida de resolución.
* **Prompt:** *"¿Cómo puedo insertar y renderizar imágenes en formato SVG dentro de un entorno de Qt Widgets usando C++ para evitar que las fórmulas pierdan definición?"*

**2. Formateo de Colores y Estilos de Texto en la Interfaz**
* **Descripción:** Definición de la paleta de colores oscura y estructuración de código CSS adaptado a Qt (QSS) para homogeneizar el color de los textos, displays y alertas de error.
* **Prompt:** *"Dame ejemplos de hojas de estilo (QSS) para cambiar el color de texto de etiquetas y pantallas en un entorno Qt con fondo oscuro, manteniendo alto contraste."*

**3. Diseño y Estructuración de la Interfaz Principal**
* **Descripción:** Asistencia en la organización espacial de la ventana de la calculadora, recomendando la distribución de un menú lateral fijo mediante layouts y botones de tipo herramienta.
* **Prompt:** *"¿Cuál es la mejor estructura de layouts en Qt para diseñar una calculadora con una barra lateral de navegación izquierda y un panel numérico central?"*

**4. Alineación de Elementos SVG en Pantalla**
* **Descripción:** Guía para aplicar políticas de tamaño y alineación geométrica sobre los componentes vectoriales dentro de los layouts contenedores del formulario educativo.
* **Prompt:** *"¿Cómo logro alinear vertical y horizontalmente al centro un QSvgWidget dentro de un layout para que coincida simétricamente con el resto del texto?"*

**5. Desacoplamiento de Módulos en Ventanas Independientes**
* **Descripción:** Refactorización arquitectónica para separar los componentes de la graficadora animada y el formulario interactivo del contenedor principal, transformándolos en ventanas flotantes autónomas.
* **Prompt:** *"Tengo un widget integrado en el layout principal. ¿Cómo modifico el código en C++ y Qt para que al pulsar un botón este componente se abra en una ventana nueva e independiente?"*

---

## Aplicación en el Desarrollo (Hito 2)

**1. Control de Desbordamiento de Magnitud**
* **Descripción:** Identificación de funciones dentro de la biblioteca matemática estándar de C++ para resolver el desbordamiento de memoria al calcular magnitudes excesivas, implementando `std::isinf` para interceptar resultados infinitos.
* **Prompt:** *"¿Qué función o librería de la biblioteca estándar de C++ puedo usar para detectar si el resultado de una operación matemática excede el límite físico de un double y arroja infinito?"*

**2. Implementación de Interfaz Visual en Consola (Códigos ANSI)**
* **Descripción:** Asistencia para seleccionar e incorporar códigos de escape ANSI (`\033[...]`) en los flujos de salida de la terminal, logrando diferenciar menús, resultados y mensajes de error.
* **Prompt:** *"¿Cuáles son los códigos de escape ANSI para imprimir texto con colores en la consola de Linux usando C++? Dame la sintaxis exacta para implementarlos con std::cout y ejemplos para los colores rojo, verde y amarillo."*

**3. Control de Precisión Decimal**
* **Descripción:** Sugerencia y aplicación técnica de la librería `<iomanip>` mediante `std::fixed` y `std::setprecision(6)` para estandarizar la salida de números decimales y evadir notaciones científicas automáticas.
* **Prompt:** *"¿Cómo puedo limitar y fijar la cantidad de decimales que se imprimen en consola con std::cout en C++ para que siempre muestre exactamente 6 dígitos?"*

**4. Corrección de Estilo y Ortografía**
* **Descripción:** Revisión de sintaxis, ortografía y estructura de formato Markdown para los documentos del repositorio (`README.md` y `AI_USAGE.md`), optimizando su redacción técnica.
* **Prompt:** *"Revisa el siguiente texto destinado a la documentación en GitHub. Corrige los errores ortográficos y asegúrate de que el formato Markdown sea estéticamente ordenado."*

**5. Proyección de Contenido para el Formulario**
* **Descripción:** Estructuración teórica y jerarquizada de contenidos de enseñanza media (productos notables, logaritmos, identidades trigonométricas) para validar la base de datos estática del formulario educativo.
* **Prompt:** *"Pensando en desarrollar un software educativo interactivo, sugiere una lista jerarquizada de temas matemáticos, fórmulas y propiedades útiles para estudiantes de enseñanza media que pueda integrar en un apartado visual llamado 'Formulario y Aprendizaje'."*

---

## Historial de Uso (Hito 1)

**1. Formateo de Documentación**
* **Descripción:** Definición y aplicación del formato de bloques de código tipo `bash` en el archivo `README.md` para clarificar las instrucciones de instalación y compilación.
* **Prompt:** *"Cómo aplicar formato bash a las instrucciones de ejecución en GitHub para mejorar su legibilidad."*

**2. Lógica para Raíces con Radicales Negativos**
* **Descripción:** Asistencia en la implementación de la función de radicación para manejar radicales negativos con índices impares, evadiendo las limitaciones analíticas de la función nativa `pow()`.
* **Prompt:** *"Lógica en lenguaje C para calcular raíces de números negativos mediante la extracción del signo y el cálculo sobre su valor absoluto, evadiendo el error de la biblioteca matemática."*

**3. Procesamiento de Strings**
* **Descripción:** Sugerencia técnica para la conversión de cadenas de caracteres a valores numéricos de tipo `double`, facilitando la interpretación de las constantes literales (`e`, `pi`) ingresadas por consola.
* **Prompt:** *"Cómo transformar un string numérico leído por scanf a un número de punto flotante. Alternativas para interpretar números ingresados como texto en C."*