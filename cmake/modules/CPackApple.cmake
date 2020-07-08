# BornAgain Mac packaging

set(SELECTED_PYTHON_VERSION "python${Python_VERSION_MAJOR}.${Python_VERSION_MINOR}")

set(CPACK_PACKAGE_FILE_NAME
    "${CMAKE_PROJECT_NAME}-${CMAKE_PROJECT_VERSION}-${SELECTED_PYTHON_VERSION}-${BORNAGAIN_ARCHITECTURE}-10.13+")

set(CPACK_BINARY_DRAGNDROP ON)
set(CPACK_GENERATOR "DragNDrop")
