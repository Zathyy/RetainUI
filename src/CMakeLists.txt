option(BUILD_SHARED_LIBS "Build shared libraries" ON)

if(BUILD_SHARED_LIBS)
    add_library(RetainUI SHARED)
else()
    add_library(RetainUI STATIC)
endif()

file(GLOB_RECURSE CORE_SOURCES Core/*.cpp Core/*.h)
target_sources(RetainUI PRIVATE ${CORE_SOURCES})

file(GLOB_RECURSE WIDGETS_SOURCES Widgets/*.cpp Widgets/*.h)
target_sources(RetainUI PRIVATE ${WIDGETS_SOURCES})

file(GLOB_RECURSE MATH_SOURCES Math/*.cpp Math/*.h)
target_sources(RetainUI PRIVATE ${MATH_SOURCES})

target_include_directories(RetainUI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(RetainUI PUBLIC cxx_std_20)

target_compile_definitions(RetainUI
        PUBLIC $<$<BOOL:${BUILD_SHARED_LIBS}>:RUI_SHARED>
        PRIVATE RUI_BUILD
)


