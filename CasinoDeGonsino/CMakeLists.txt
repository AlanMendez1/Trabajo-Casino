cmake_minimum_required(VERSION 3.19)
project(CASINO-Polimorfismo)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        #Nombre del ejecutable
        casino
        #Lista de archivos a compilar
        main.cpp
        Model/Usuario.cpp
        Model/Usuario.h
        Model/Casino.cpp
        Model/Casino.h
        Model/DosColores.cpp
        Model/DosColores.h
        Model/ElMayorDe13.cpp
        Model/ElMayorDe13.h
        Model/Juego.cpp
        Model/Juego.h
        View/View.h
        View/View.cpp
        Model/DosColores.cpp
        Model/AdivinaAdivinador.h
        Model/AdivinaAdivinador.cpp)
