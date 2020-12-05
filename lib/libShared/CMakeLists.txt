# Проверка версии CMake
cmake_minimum_required( VERSION 3.4.0 )
# Если версия установленой программы ниже, то ошибка выполнения

# Название проекта и проверка доступности компиляторя с++
project( shared_lib CXX )			

# Установка переменной со списком исходников
set( SOURCE_LIB example.cpp )		

# Включение экспорта всех символов для создания динамической библиотеки
set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

# Создание динамической библиотеки с именем example
add_library( example SHARED ${SOURCE_LIB} )