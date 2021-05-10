# Algoritmos y Estructuras de Datos UCV. EJERCICIOS

Conjunto de ejercicios planteados y resueltos de el curso "Algoritmos y Estructuras de Datos, Semestre 1-2021, Escuela de Computacion. Universidad Central de Venezuela"

## Tabla de contenidos

- [Set Up](#instalacion)
- [Uso](#uso)
- [Estructura](#estructura)
- [Contribucion](#contribucion)

## Instalacion

Clona el repositorio de git usando el comando.

```sh
git clone "LINK DEL REPOSITORIO"
```

Luego crea el archivo binario y ejecutalo.

Linux:
```sh
g++ main.cpp && ./a.out
```

Windows:
```sh
g++ main.cpp
a.exe
```

## Uso

Unicamente para uso educativo, varios problemas y ejercicios del curso son planteados y resueltos en el repositorio. Los temas abordados son:
 
- Apuntadores (en progreso)
- Pilas y Colas (en progreso)
- Arboles (en progreso)
- Recursion (en progreso)
- Backtracking 

## Estructura

La estructura del proyecto esta definida de la siguiente manera:

```
project
│   README.md
│   file001.txt    
│
└───exercises // Aqui se agregan los ejercicios
│   └───exercise1
│   │    │   main.cpp // Clase que resuelve el ejercicio
│   │    │   README.md // Explicacion del ejercicio
│   │    └── testCases.txt // Casos de prueba
│   │
│   └───exercise2
│       │   main.cpp
│       │   README.md
│       └── testCases.txt
│  			....
│ 			....
│   
└───utils
    │   exercise.h  // Clase base para los ejercicios
    │   fileReader.cpp  // Lector de archivos automatico (en progreso)
```

- Cada ejercicio agregado debe ser una clase (ver ejemplo mouseLaberinth). Esa clase debe implementar un metodo llamado 'init' donde empezara a resolver el ejercicio.

- Cada clase de un ejercicio debe heredar de forma publica a la clase 'Exercise' (Ruta: utils/exercise.h).

- Al agregar un ejercicio se debe implementar en exercises/main.cpp. La clase ExercicesStarter contiene un arreglo donde se inician todos los ejercicios. En el constructor de la clase se debe agregar (en el arreglo) el nuevo ejercicio implementado.

Esta metodologia es en beneficio de aquellos que necesiten estudiar/revisar la solucion a un determinado problema. Porfavor agregar un README.md en cada ejercicio (carpeta), explicando el enunciado del problema.

## Contribucion

Porfavor contribuir usando [Github Flow](https://www.atlassian.com/es/git/tutorials/comparing-workflows/gitflow-workflow). Crea una rama, agrega commits y luego crea un pull request [open a pull request](https://github.com/Rcontre360/algorithm_viewer/compare/).

Cada ejercicio es un 'feature' en gitflow. Es decir, una nueva rama. Cada rama debe tener el siguiente formato: feature/'nombre_del_ejercicio'.

### Recomendaciones
	
- Agregar un README.md a cada ejercicio agregado dentro de su carpeta.

- Agregar un testCases.txt para los casos de prueba del ejercicio.

- Utilizar ifstream (#include < fstream >) para leer el testCases.txt. IMPORTANTE: usar la ruta del archivo testCases.txt desde main.cpp en el archivo raiz. Eg: ver exercises/mouseMaze/main.cpp linea 13.