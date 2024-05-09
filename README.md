# Programacion 2
Por Lucas Fabiani

## Configuracion
```bash
alias test='./test.sh'
```

## Ejecutar el proyecto
Ejecutar un archivo con todas las librerias
```bash
test ./ruta_del_archivo/archivo.cpp
# test ./main.cpp para ejecutar el principal
```
**chache/last-test-name se utiliza para almacenar la ruta del ultimo archivo ejecutado y poder reemplazarlo cuando se ejecute otro

## Crear librerias o modificarlas

- En **/custom-libs** crear una carpeta nueva y añadirla a **/custom-libs/CMakeLists.txt**
- Configurar el CMakeLists.txt de esa libreria (guiarse de **/custom-libs/mates/CMakeLists.txt)**
- Ejecuta el archivo con **test**

## Herramientas
### Para compilar y ejecutar un archivo .cpp a secas
Configurar
```bash
chmod +x ./gpp.sh
alias gpp='./gpp.sh'
```
Ejecutar un archivo
```bash
gpp archivo.cpp
```

### Comandos de utilidad
```bash
tree -I 'build|samples' -L 4 . # imprimir arbol excluyendo carpeta build y con profundidad de 3
```