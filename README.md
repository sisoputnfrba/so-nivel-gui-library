# so-nivel-gui-library

Este repositorio contiene:

- El codigo fuente de la biblioteca para graficar el nivel (libnivel-gui.so)
- El programa de ejemplo (nivel-gui-test)

## Dependencias

- [so-commons-library](https://github.com/sisoputnfrba/so-commons-library): Para instalarla, seguir los pasos mencionados en el readme del repositorio linkeado.
- `ncurses`: Para instalarla, abrir una consola y ejecutar `sudo apt-get install libncurses5-dev`

## Instalación

Para instalar la library se deberán ejecutar los siguientes comandos:

```
git clone https://github.com/sisoputnfrba/so-nivel-gui-library/
cd so-nivel-gui-library
make install
```

Para desinstalar, ejecutar `make uninstall`

## Uso

Para usarlo, desde el proyecto que se quiera usar la biblioteca se debe configurar lo siguiente:

- En el linker: `-lnivel-gui -lncurses`
- En el archivo que se necesite usar la biblioteca:
```
#include <nivel-gui/nivel-gui.h>
#include <nivel-gui/tad_nivel.h>
```

### Desde eclipse

1) Ir a las Properties del proyecto (en el Project Explorer - la columna de la izquierda - la opción aparece dándole click derecho al proyecto), y dentro de la categoría C/C++ Build entrar a Settings, y ahí a Tool Settings.
2) Buscar GCC Linker > Libraries > Libraries. Notar que entre paréntesis dice -l, el parámetro de gcc que estamos buscando.
3) Darle click en el botón de +, y poner el nombre de la biblioteca sin el -l (en este caso, nivel-gui y ncurses).
4) Aceptar y buildear el proyecto.

## Build & Run desde Consola

Para compilar y ejecutar el código de ejemplo sin necesidad de instalar la biblioteca:

1) Bajarlo en un directorio
2) En el directorio padre compilar y ejecutar con `make test`.
3) Mover un personaje con las flechas y el otro con WASD. Salir con Q.

En caso de que arroje un error, asegúrese de agrandar el tamaño de la terminal y vuelva a ejecutar.

Nota: se puede ejecutar con Valgrind memcheck haciendo `make valgrind`.

## Build & Run desde Eclipse

Hay al menos dos formas de armar los proyectos en eclipse:

1- Eclipse full managed: crear los dos C Projects desde cero, copiar los archivos y configurar desde el eclipse (linkeos, parametros, etc). De esta forma eclipse crea sus makefiles y los usa para buildear.

2- Eclipse half-managed: [crear los dos C Projects haciendo que usen los makefiles existentes](https://www.youtube.com/watch?v=PgrORWmUxkI).

### Aclaración importante

La consola de Eclipse no es interactiva, por lo que NO es posible ejecutar la aplicación desde ahí. Sin embargo, es posible hacerlo desde consola y [debugear remotamente con Eclipse](https://www.youtube.com/watch?v=MNd8KZlDQUk).
