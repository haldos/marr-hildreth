# Copyright (C) 2011-2012, Haldo Spontón <haldos@fing.edu.uy>
# Copyright (C) 2011-2012, Juan Cardelino <juanc@fing.edu.uy>

PROJECT(test_marr_hildreth)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(CMAKE_C_FLAGS "-std=c99")
SET(PROJECT_SOURCE_DIR source)
SET(PROJECT_BINARY_DIR bin)
 
FIND_PACKAGE(TIFF)
IF(TIFF_FOUND)
   include_directories(${TIFF_INCLUDE_DIR})
   #  link_directories(${TIFF_LIBRARY})
   SET( LIBS ${LIBS} ${TIFF_LIBRARIES})
ENDIF()

FIND_PACKAGE(JPEG)
if(JPEG_FOUND)
   include_directories(${JPEG_INCLUDE_DIR})
   # link_directories(${JPEG_LIBRARY})
   SET( LIBS ${LIBS} ${JPEG_LIBRARIES})
ENDIF()

FIND_PACKAGE(PNG)
IF(PNG_FOUND)
   include_directories(${PNG_INCLUDE_DIR})
   #  link_directories(${PNG_LIBRARY})
   SET( LIBS ${LIBS} ${PNG_LIBRARIES})
ENDIF()

FIND_PACKAGE(PNG)
IF(PNG_FOUND)
   include_directories(${PNG_INCLUDE_DIR})
   # link_directories(${PNG_LIBRARY})
   SET( LIBS ${LIBS} ${PNG_LIBRARIES})
ENDIF()

MESSAGE("libraries: ${LIBS}")

ADD_SUBDIRECTORY(source)
MESSAGE("standard libraries: ${LIBS}")
MESSAGE("custom libraries: ${E_LIBS}")

SET(SRC ${PROJECT_SOURCE_DIR}/test_mh.c)
SET(SRC2 ${PROJECT_SOURCE_DIR}/test_mh_log.c)
ADD_EXECUTABLE(${PROJECT_BINARY_DIR}/test_mh ${SRC})
ADD_EXECUTABLE(${PROJECT_BINARY_DIR}/test_mh_log ${SRC2})
TARGET_LINK_LIBRARIES(${PROJECT_BINARY_DIR}/test_mh ${E_LIBS} ${LIBS})
TARGET_LINK_LIBRARIES(${PROJECT_BINARY_DIR}/test_mh_log ${E_LIBS} ${LIBS})

INSTALL(TARGETS ${PROJECT_BINARY_DIR}/test_mh RUNTIME DESTINATION bin)
INSTALL(TARGETS ${PROJECT_BINARY_DIR}/test_mh_log RUNTIME DESTINATION bin)
