cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp src/map.cpp src/map.h  src/Loot.cpp  src/Loot.h  src/Personnage.cpp  src/Personnage.h src/Ennemi.cpp  src/Ennemi.h  src/Joueur.cpp   src/Joueur.h src/Kamikaze.h src/Kamikaze.cpp  src/Boss.h src/Boss.cpp  src/Epeiste.h src/Epeiste.cpp  src/Game.h src/Game.cpp "src/explosion.h" "src/explosion.cpp")
target_compile_features(main PRIVATE cxx_std_20)
target_link_libraries(main PRIVATE SFML::Graphics)