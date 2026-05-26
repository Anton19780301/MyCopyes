cmake_minimum_required(VERSION 3.16)
project(QtPluginSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем автоматическую генерацию мета-кода Qt (MOC)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Поиск Qt 6
find_package(Qt6 REQUIRED COMPONENTS Core)

# Подключаем папки проекта
add_subdirectory(interfaces)
add_subdirectory(plugins)
add_subdirectory(app)
