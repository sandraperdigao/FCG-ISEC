cmake_minimum_required(VERSION 3.20)
project(trb)

set(CMAKE_CXX_STANDARD 14)

add_executable(trb main.cpp
        cmake-build-debug/Edificio.h
        cmake-build-debug/Edificio.cpp
        cmake-build-debug/Edificios/Bateria.h
        cmake-build-debug/Edificios/Bateria.cpp
        cmake-build-debug/Edificios/Centraleletrica.h
        cmake-build-debug/Edificios/Centraleletrica.cpp
        cmake-build-debug/Edificios/Edificiox.h
        cmake-build-debug/Edificios/Edificiox.cpp
        cmake-build-debug/Edificios/Fundicao.h
        cmake-build-debug/Edificios/Fundicao.cpp
        cmake-build-debug/Edificios/Minacarvao.h
        cmake-build-debug/Edificios/Minacarvao.cpp
        cmake-build-debug/Edificios/Minaferro.h
        cmake-build-debug/Edificios/Minaferro.cpp
        cmake-build-debug/Trabalhadores/Mineiro.cpp
        cmake-build-debug/Trabalhadores/Mineiro.h
        cmake-build-debug/Trabalhadores/Lenhador.cpp
        cmake-build-debug/Trabalhadores/Lenhador.h
        cmake-build-debug/Trabalhadores/Operario.cpp
        cmake-build-debug/Trabalhadores/Operario.h
        cmake-build-debug/Trabalhadores.h
        cmake-build-debug/Trabalhadores.cpp
        cmake-build-debug/Recursos.cpp
        cmake-build-debug/Recursos.h
        cmake-build-debug/Recursos/Aco.cpp
        cmake-build-debug/Recursos/Aco.h
        cmake-build-debug/Recursos/Carvao.cpp
        cmake-build-debug/Recursos/Carvao.h
        cmake-build-debug/Recursos/Eletricidade.cpp
        cmake-build-debug/Recursos/Eletricidade.h
        cmake-build-debug/Recursos/Ferro.cpp
        cmake-build-debug/Recursos/Ferro.h
        cmake-build-debug/Recursos/Madeira.cpp
        cmake-build-debug/Recursos/Madeira.h
        cmake-build-debug/Recursos/VigasMadeira.cpp
        cmake-build-debug/Recursos/VigasMadeira.h
        cmake-build-debug/Zona.cpp
        cmake-build-debug/Zona.h
        cmake-build-debug/Zonas/Deserto.cpp
        cmake-build-debug/Zonas/Deserto.h
        cmake-build-debug/Ilha.cpp
        cmake-build-debug/Ilha.h
        cmake-build-debug/Interacao.cpp
        cmake-build-debug/Interacao.h)
