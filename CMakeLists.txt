cmake_minimum_required(VERSION 3.10)
project(Proyecto_1)

set(CMAKE_CXX_STANDARD 17)

# Configura la ruta base del proyecto
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR})

# Verifica explícitamente la existencia del archivo
set(TINYFD_SOURCE "${PROJECT_SOURCE_DIR}/lib/utils/tinyfiledialogs.cpp")
set(TINYFD_HEADER "${PROJECT_SOURCE_DIR}/lib/utils/tinyfiledialogs.h")

if(NOT EXISTS ${TINYFD_SOURCE})
    message(FATAL_ERROR "Archivo tinyfiledialogs.cpp no encontrado en: ${TINYFD_SOURCE}")
endif()

# Incluye directorios
include_directories(
        ${PROJECT_SOURCE_DIR}/include/utils
        ${PROJECT_SOURCE_DIR}/include/objeto
        ${PROJECT_SOURCE_DIR}/include/
        ${PROJECT_SOURCE_DIR}/lib/utils
        ${PROJECT_SOURCE_DIR}/lib/objeto
)

# Añade tinyfiledialogs como biblioteca
add_library(tinyfiledialogs STATIC ${TINYFD_SOURCE})

# Archivos fuente (mejor especificar manualmente)
set(SOURCES
        src/main.cpp
        lib/Jugar.cpp
        include/objeto/Util.h
        # Añade aquí otros .cpp cuando los tengas
        # src/OtraClase.cpp
)

# Ejecutable principal
add_executable(Proyecto_1 ${SOURCES})
target_link_libraries(Proyecto_1 PRIVATE tinyfiledialogs)