# Programacion 2
Por Lucas Fabiani

## Configuracion
```bash
chmod +x setup # permitir ejecucion
./setup 
```

## Ejecutar el proyecto
Ejecutar un archivo con todas las librerias
```bash
test ./ruta_del_archivo/archivo.cpp
# test ./main.cpp para ejecutar el principal
```
**chache/last-test-name se utiliza para almacenar la ruta del ultimo archivo ejecutado y poder reemplazarlo cuando se ejecute otro

## Crear librerias o modificarlas

- En /modules crear una carpeta nueva y añadirla a /modules/CMakeLists.txt
- Configurar el CMakeLists.txt de esa libreria (guiarse de /modules/mates/CMakeLists.txt)
- Ejecuta el proyecto
