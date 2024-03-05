cmake_minimum_required(VERSION 3.26.3 FATAL_ERROR)

set(PROJECT_NAME TemplateArray)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
		src/main.cpp 		 
		src/templateArray.h)       

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)		