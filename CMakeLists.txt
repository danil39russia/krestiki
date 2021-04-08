cmake_minimum_required(VERSION 3.10.0)

project(Homework CXX)
set(CMAKE_CXX_STANDARD 17) # CMAKE_CXX_STANDARD = 17
include(cmake/StandardProjectSettings.cmake)
# Link this 'library' to set the c++ standard / compile-time options requested
add_library(default INTERFACE)
target_compile_features(default INTERFACE cxx_std_17)
cmake_policy(SET CMP0079 NEW)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(default)
include(cmake/conan.cmake)
get_property(languages GLOBAL PROPERTY ENABLED_LANGUAGES)
set(ENV_FOR_C CC)
set(ENV_FOR_CXX CXX)
set(ENV_FOR_Fortran FC)
foreach(language ${languages})
  if(ENV_FOR_${language})
    list(APPEND ENV "${ENV_FOR_${language}}=${CMAKE_${language}_COMPILER}")
  else()
    list(APPEND ENV "${language}=${CMAKE_${language}_COMPILER}")
  endif()
endforeach()
conan_cmake_run(
  CONANFILE conanfile.txt
  BASIC_SETUP CMAKE_TARGETS BUILD missing
  ENV CONAN_CMAKE_PROGRAM="${CMAKE_COMMAND}" ${ENV}
  )
set(MSVC_USE_STATIC_RUNTIME OFF CACHE INTERNAL "Set to ON to build nana with the /MT(d) option.")

enable_testing()
add_subdirectory(external/doctest)
add_subdirectory(external/nana EXCLUDE_FROM_ALL)
target_compile_definitions(nana PUBLIC NANA_ENABLE_PNG NANA_ENABLE_JPEG)
target_link_libraries(nana PUBLIC CONAN_PKG::libpng CONAN_PKG::libjpeg)
include(external/doctest/doctest.cmake)
add_subdirectory(src)

# Так как VSCode любит при запуске неправильно указывать текущий каталог,
# мы создаём ссылку на каталог resources рядом с исполняемыми файлами
file(CREATE_LINK "${CMAKE_CURRENT_SOURCE_DIR}/resources" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources" COPY_ON_ERROR SYMBOLIC)