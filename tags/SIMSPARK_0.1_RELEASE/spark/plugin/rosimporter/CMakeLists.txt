########### next target ###############

set(rosimporter_LIB_SRCS
   export.cpp
   roselements.cpp
   roselements.h
   rosimporter.cpp
   rosimporter.h
   rosimporter_c.cpp
)

add_library(rosimporter MODULE ${rosimporter_LIB_SRCS})

target_link_libraries(rosimporter tinyxml_ex)

set_target_properties(rosimporter PROPERTIES VERSION 0.0.0 SOVERSION 0)
install(TARGETS rosimporter DESTINATION ${LIBDIR}/${CMAKE_PROJECT_NAME})
