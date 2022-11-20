file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .cpp

#include_directories(lib1)
add_executable(${arithmeticName} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}


 #Собираем проект в поддиректории lib1
target_link_libraries(${arithmeticName} ${arithmeticLibName}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}