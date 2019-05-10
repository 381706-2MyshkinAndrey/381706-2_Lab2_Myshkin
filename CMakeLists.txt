cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-2_Labs_Myshkin) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(vector vector) #Переменная с именем библиотеки
set(vectorlib vectorlib)
set(vectortest vectortest)
set(matrixtest matrixtest)
set(matrixlib matrixlib)
set(exeptionlib exeptionlib)

set(stacklib stacklib)
set(stacktest stacktest)
set(stack stack)

set(queue queue)
set(queuelib queuelib)
set(queuetest queuetest)

set(multistack multistack)
set(multistacklib multistacklib)
set(multistacktest multistacktest)

set(datlink datlink)
set(datlist datlist)
set(datlistlib datlistlib)
set(datlisttest datlisttest)

set(arrlist arrlist)
set(arrlistlib arrlistlib)
set(arrlisttest arrlisttest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/vectorlib ${CMAKE_CURRENT_SOURCE_DIR}/matrixlib ${CMAKE_CURRENT_SOURCE_DIR}/exeptionlib ${CMAKE_CURRENT_SOURCE_DIR}/gtest ${CMAKE_CURRENT_SOURCE_DIR}/stacklib ${CMAKE_CURRENT_SOURCE_DIR}/queuelib ${CMAKE_CURRENT_SOURCE_DIR}/multistacklib ${CMAKE_CURRENT_SOURCE_DIR}/datlistlib ${CMAKE_CURRENT_SOURCE_DIR}/datlink ${CMAKE_CURRENT_SOURCE_DIR}/arrlistlib)

add_subdirectory(vector)
add_subdirectory(vectorlib)
add_subdirectory(vectortest)
add_subdirectory(gtest)
add_subdirectory(matrixtest)
add_subdirectory(matrixlib)
add_subdirectory(exeptionlib)

add_subdirectory(stack)
add_subdirectory(stacklib)
add_subdirectory(stacktest)

add_subdirectory(queue)
add_subdirectory(queuelib)
add_subdirectory(queuetest)

add_subdirectory(multistack)
add_subdirectory(multistacklib)
add_subdirectory(multistacktest)

add_subdirectory(datlink)
add_subdirectory(datlist)
add_subdirectory(datlistlib)
add_subdirectory(datlisttest)

add_subdirectory(arrlist)
add_subdirectory(arrlistlib)
add_subdirectory(arrlisttest)


#file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
#file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .cpp


#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}


#add_subdirectory(lib1) #Собираем проект в поддиректории lib1
#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}