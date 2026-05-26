add_library(plugin_interfaces SHARED plugin_interface.h)
target_link_libraries(plugin_interfaces PUBLIC Qt6::Core)
target_include_directories(plugin_interfaces INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
