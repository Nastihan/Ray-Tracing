
set(SOURCES
    main.cpp
)

add_executable(RayTracer 
    ${SOURCES}
)

target_include_directories(RayTracer PRIVATE ${CMAKE_SOURCE_DIR}/include)