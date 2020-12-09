CMAKE_MINIMUM_REQUIRED(VERSION 3.12.0)

string(TIMESTAMP timeStart "%Y-%m-%d %H:%M:%S")

SET(CMAKE_OSX_DEPLOYMENT_TARGET "10.12" CACHE STRING "Minimum OS X deployment version")
SET(CMAKE_CXX_STANDARD 11)

PROJECT(SparkleDemo C CXX)

FIND_PACKAGE(Qt5 COMPONENTS Core Widgets Gui REQUIRED)  

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)

################################################################################
# sources and headers
FILE(GLOB APP "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h*") 
FILE(GLOB FORMS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.ui")     
SET(RESOURCES  ${CMAKE_CURRENT_SOURCE_DIR}/resource/demo.qrc)  
qt5_wrap_ui(UI_HEADERS ${FORMS})

SET(ALL_SOURCE_FILES  
	${UI_HEADERS}
	${APP}  
	${RESOURCES}
	${FORMS}
)

IF (APPLE)
  FILE(GLOB MAC "${CMAKE_CURRENT_SOURCE_DIR}/src/mac/*")
  LIST(APPEND ALL_SOURCE_FILES ${MAC})
ENDIF()

#################################################################################
# Compile target 
ADD_EXECUTABLE (${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${ALL_SOURCE_FILES}) 

#################################################################################
# external libs and headers
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}/
  ${CMAKE_CURRENT_SOURCE_DIR}/src/
)  
	
IF(WIN32)
  SET(DEPENDENCY_LIBS
	WinSparkle.lib
  )
  TARGET_LINK_DIRECTORIES(${PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/win/bin
  )
  TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/win/include
  )
ELSE() 
  FIND_LIBRARY(FOUNDATION Foundation)
  FIND_LIBRARY(SPARKLE Sparkle)
  FIND_LIBRARY(APPKIT AppKit)
  SET(DEPENDENCY_LIBS 
	${FOUNDATION} 
  ${APPKIT}
  ${SPARKLE}
  )
ENDIF()

TARGET_LINK_LIBRARIES(${PROJECT_NAME} PRIVATE
  Qt5::Widgets
  Qt5::Core
  Qt5::Gui
  ${DEPENDENCY_LIBS}
)

string(TIMESTAMP time "%Y-%m-%d %H:%M:%S")
message(STATUS "Configure started at ${timeStart} and ended at ${time}")
