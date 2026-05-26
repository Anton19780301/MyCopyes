# Создаем динамический модуль
add_library(hello_plugin MODULE
    hello_plugin.h
    hello_plugin.cpp
)

# Линкуем с Qt и нашим интерфейсом
target_link_libraries(hello_plugin PRIVATE Qt6::Core plugin_interfaces)

# Автоматически копируем скомпилированный плагин в папку с приложением для удобства запуска
add_custom_command(TARGET hello_plugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:app>/plugins"
    COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:hello_plugin>" "$<TARGET_FILE_DIR:app>/plugins/"
)
