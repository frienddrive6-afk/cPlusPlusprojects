# Указываем минимальную требуемую версию CMake.
# У вас 3.20, так что это значение подходит.
cmake_minimum_required(VERSION 3.20)

# Даем нашему проекту имя. Назовем его, например, MusicPlayer.
project(MusicPlayer VERSION 1.0)

# Создаем исполняемый файл с именем "main"
# и перечисляем все .cpp файлы, из которых он состоит.
add_executable(main
    main.cpp
    ncurses_interface.cpp
    song_logistic.cpp
)

# Находим библиотеку ncurses. Это "правильный" способ подключения библиотек.
# CMake сам найдет, где лежат заголовочные файлы и сама библиотека.
find_package(Curses REQUIRED)

# Добавляем пути к заголовочным файлам ncurses
target_include_directories(main PRIVATE ${CURSES_INCLUDE_DIRS})

# Линкуем саму библиотеку ncurses
target_link_libraries(main PRIVATE ${CURSES_LIBRARIES})