##########
# blabla #
##########

set(EXAMPLE_FOLDER ${CMAKE_SOURCE_DIR}/src/)

find_package(OpenGL)

include_directories ( ${OPENGL_INCLUDE_DIR})

file(GLOB EXAMPLE_SRC ${EXAMPLE_FOLDER}[A-Za-z0-9]*.cpp)
file(GLOB EXAMPLE_HEAD ${EXAMPLE_FOLDER}[A-Za-z0-9]*.h)

source_group(Source FILES ${EXAMPLE_SRC})
source_group(Header FILES ${EXAMPLE_HEAD})
source_group(Other FILES ${CMAKE_SOURCE_DIR}/Rule/AllExample.cmake ${CMAKE_SOURCE_DIR}/Rule/CMakeLists.txt)

IF (CPP_COMPILER MATCHES "MSVC")

	set(ALL_LIB ${OPENGL_LIBRARIES} SDL SDLmain RetroEngineList RetroEngine2D PortableThread RetroEnginephysique)

ELSE (CPP_COMPILER MATCHES "MSVC")
	IF (CPP_COMPILER MATCHES "CLANG")

		IF (USE_SDL_FRAMEWORKS)

			SET(ALL_LIB "-lRetroEngineList -lRetroEngine2D -lPortableThread -lRetroEnginephysique -framework OpenGL -framework Cocoa -framework AudioUnit -framework Carbon -framework IOKit -F\"${CMAKE_SOURCE_DIR}/externs/frameworks\" -framework SDL")

		ELSE (USE_SDL_FRAMEWORKS)

			SET(ALL_LIB "-lSDL -lSDLmain -lRetroEngineList -lRetroEngine2D -lPortableThread -lRetroEnginephysique -framework OpenGL -framework Cocoa -framework AudioUnit -framework Carbon -framework IOKit")

		ENDIF (USE_SDL_FRAMEWORKS)
ELSE (CPP_COMPILER MATCHES "CLANG")

		set(ALL_LIB ${OPENGL_LIBRARIES} -lSDL -lSDLmain -L"${CUSTOM_LIB_FOLDER}" -lRetroEngineList -lRetroEngine2D -lPortableThread -lRetroEnginephysique -lpthread)

	ENDIF(CPP_COMPILER MATCHES "CLANG")
ENDIF(CPP_COMPILER MATCHES "MSVC")

IF (USE_SDL_FRAMEWORKS)

add_executable(allExample ${EXAMPLE_FOLDER}/SDLMain.m ${EXAMPLE_FOLDER}/SDLMain.h ${EXAMPLE_SRC} ${EXAMPLE_HEAD} ${CMAKE_SOURCE_DIR}/Rule/AllExample.cmake ../Rule/CMakeLists.txt)

ELSE (USE_SDL_FRAMEWORKS)

	add_executable(allExample ${EXAMPLE_SRC} ${EXAMPLE_HEAD} ${CMAKE_SOURCE_DIR}/Rule/AllExample.cmake ../Rule/CMakeLists.txt)

ENDIF (USE_SDL_FRAMEWORKS)

target_link_libraries(allExample ${ALL_LIB})
set_target_properties(allExample PROPERTIES COMPILE_FLAGS "${COMPILE_FLAGS} -DCUSTOM_MAIN_FUNC")