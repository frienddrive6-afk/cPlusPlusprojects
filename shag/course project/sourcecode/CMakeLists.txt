# Указываем минимальную требуемую версию CMake.
cmake_minimum_required(VERSION 3.20)

# Даем нашему проекту имя.
project(MusicPlayer VERSION 1.0)

# Создаем исполняемый файл с именем "main"
add_executable(main
    main.cpp
    ncurses_interface.cpp
    song_logistic.cpp
)

# --- ВИПРАВЛЕННЯ ДЛЯ КИРИЛИЦІ (Силовий метод) ---
# Замість find_package і target_include_directories,
# ми просто напряму лінкуємо потрібну нам бібліотеку.
# CMake достатньо розумний, щоб знайти її в системі за іменем.
target_link_libraries(main PRIVATE ncursesw)
# --------------------------------------------------