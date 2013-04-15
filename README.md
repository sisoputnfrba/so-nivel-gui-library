Este repositorio contiene:

- El codigo fuente de la biblioteca para graficar el nivel (libnivel-gui.so)
- El programa de ejemplo (nivel-gui-test)


Para usarlo:

-------------------------------
Build & Run desde Consola
-------------------------------

1) Bajarlo en un directorio<br>
2) En ese mismo directorio compilar ejecutando: make ; make install<br>
3) Ir a el directorio testnivel: cd testnivel<br>
4) Ejecutar el codigo de ejemplo: ./nivel<br>
5) Mover un personaje con las flechas y el otro con WASD. Salir con Q<br>




-------------------------------
Build & Run desde Eclipse
-------------------------------

Hay al menos dos formas de armar los proyectos en eclipse:

1- Eclipse full managed: crear los dos C Projects desde cero, copiar los archivos y configurar desde el eclipse (linkeos, parametros, etc). De esta forma eclipse crea sus makefiles y los usa para buildear.

2- Eclipse half-managed:  y la otra opcion es crearlos medio "crudos" y hacer que usen los makefiles existentes.


Se explica la opción 2:

Eclipse half-manager (with git included!):

- Esta opcion no usa la LD_LIBRARY_PATH, por lo tanto compila y tira la library en /lib. Ergo, hay que hacer "sudo chmod o+w /lib" para tener permisos de escritura. 
- Desde el eclipse, clonarse el repo completo (Git Repository Exploring > Clone Git Repository...)
- Luego, Import > C/C++ > Existing Code as Makefile Project
	- Destildar C++ y elegir Linux GCC para "indexer settings". Indicar la location del  proyecto de la library
- Deberia haberse creado el proyecto, suceptible de ser buildeado. Deberia usar el makefile nuestro y no el del eclipse. Compilar y buildear para ver que todo esta bien.
- Repetir lo de importar para el segundo proyecto.
- Luego, borrar los proyectos haciendo "Delete", pero SIN ELEGIR "Delete project contents on disk..."
- Import > Git > Projects from Git > Local > so-nivel-gui-lbrary > "Import existing projects" (y aca abrir el arbol y elegir uno de los dos proyectos > Finish
- Repetir el paso anterior para el otro proyecto.
- Agregar al proyecto de test la referencia al proyecto de la library (es para que el eclipse no realice sus validaciones, dado que compilar compila igual por el makefile)





