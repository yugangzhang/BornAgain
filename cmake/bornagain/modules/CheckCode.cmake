set(SRC_LEN_LIM 100) # maximum line length of code written by MLZ-SCG

if(NOT MSVC)

file(GLOB_RECURSE SRC1 "Core/*.cpp")
file(GLOB_RECURSE SRC2 "Core/*.h")

add_test(NAME "CodeLineLength"
    COMMAND  ${PYTHON_EXECUTABLE}
    ${CMAKE_SOURCE_DIR}/dev-tools/analyze/count-line-length.py ${SRC_LEN_LIM}
    ${SRC1} ${SRC2})
endif()