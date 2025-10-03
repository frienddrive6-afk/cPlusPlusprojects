#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <ncurses.h>

using namespace std;

struct Sounds
{
    string title;
    string author;
    int year;
    string source_filename;

};

enum ScreenState {
    MAIN_MENU,
    CREATESOUND, 
    PRINTSOUND,
    DELATESONG,
    EDITSONG,
    FINDBYAUTHOR,
    FINDBYWORD,
    TEXTONDISPLAY,
    SAVETOFILE,
    CHANGE_LANGUAGE,      
    EXIT_PROGRAM
};

enum Language_pack_IDs {
    // Головний цикл програми
    PROMPT_INTERFACE_TYPE,
    TITLE_MAIN_MENU,
    PROMPT_MAIN_MENU,
    PROMPT_YOUR_CHOICE,

    // Пункти головного меню
    MENU_ADD_SONG,
    MENU_SHOW_ALL,
    MENU_DELETE_SONG,
    MENU_EDIT_SONG,
    MENU_FIND_AUTHOR,
    MENU_FIND_WORD,
    MENU_DISPLAY_FULL,
    MENU_SAVE_TO_FILE,
    MENU_CHANGE_LANGUAGE,
    MENU_EXIT,

    // Функція loadSongs
    MSG_DB_NOT_FOUND,
    PROMPT_ENTER_FULL_PATH,
    MSG_FOLDER_CREATED,
    MSG_NO_SONGS_YET,

    // Функція createSound
    PROMPT_ENTER_TITLE,
    PROMPT_ENTER_AUTHOR,
    PROMPT_ENTER_YEAR,
    TITLE_ADD_TEXT_MENU,
    MENU_ADD_TEXT_MANUALLY,
    MENU_ADD_TEXT_FROM_FILE,
    PROMPT_ADD_TEXT_MANUAL_STOP,
    PROMPT_ADD_TEXT_FILE_PATH,
    ERROR_FILE_OPEN,

    // Загальні запити до користувача
    PROMPT_CHOOSE_SONG_TO_DELETE,
    PROMPT_CHOOSE_SONG_TO_EDIT,
    PROMPT_CHOOSE_SONG_TO_DISPLAY,
    PROMPT_CHOOSE_SONG_TO_SAVE,
    ERROR_INVALID_SONG_NUMBER,

    // Функція editSong
    PROMPT_EDIT_CHOICE,
    MENU_EDIT_TITLE,
    MENU_EDIT_AUTHOR,
    MENU_EDIT_YEAR,
    MENU_EDIT_LYRICS,

    // Функція findSongsByAuthor
    PROMPT_FIND_BY_AUTHOR,
    MSG_AUTHOR_SONGS_ARE,
    MSG_AUTHOR_SONGS_NOT_FOUND,

    // Функція findSongsByWord
    PROMPT_FIND_BY_WORD,
    MSG_SEARCH_RESULTS_FOR_WORD,
    MSG_WORD_FOUND_IN,
    MSG_AUTHOR_SUFFIX,
    MSG_WORD_NOT_FOUND,

    // Функція displayFullSong
    TITLE_DISPLAY_MODE_MENU,
    MENU_DISPLAY_TERMINAL,
    MENU_DISPLAY_EDITOR,
    HEADER_LYRICS,
    FOOTER_LYRICS,

    // Заголовки та форматування виводу
    HEADER_ALL_SONGS,
    SONG_NUMBER_PREFIX,
    SONG_TITLE_PREFIX,
    SONG_AUTHOR_PREFIX,
    SONG_YEAR_PREFIX,
    MSG_YEAR_SUFFIX,
    FOOTER_ALL_SONGS,
    
    // Додаткові рядки для ncurses
    PROMPT_PRESS_ANY_KEY,
    PROMPT_ENTER_LYRICS_CTRL_D,
    
    STRING_COUNT 
};


extern vector<string> lang;//тут хранится текст интерфейса

//===================NCURSES ФУНКЦИИ=========================
int show_menu(const string& title, const vector<string>& items);

string get_string_from_user(int y, int x, const string& prompt);

void show_song_list_screen(const vector<Sounds>& song_catalog,ScreenState &screen_state );

vector<string> get_lyrics_from_user(int start_y, int start_x);

void printLyricWithncurses(const Sounds& sound,const vector<string>& lyric);




//=========================ОСНОВНЫЕ ФУНКЦИИ===========================

void saveSongToFile(const Sounds& song, const vector<string>& lyrics,const int choice);

void parseSongFile(string &db_dir_path,vector<Sounds> &song_catalog);

void loadSongs(string &db_dir_path,vector<Sounds> &song_catalog);

string format_string(const string& format, const string& value);

string zamenaSpasNa_(string &start_name);

void createSound(string &db_dir_path,vector<Sounds> &song_catalog,const int choice, ScreenState* screen_state_ptr = nullptr);

void displayAllSongs(vector<Sounds> &song_catalog);

void deleteSong(vector<Sounds> &song_catalog,const int choice,ScreenState* screen_state = nullptr);

void updateAndRenameSong(Sounds &song_to_edit,const vector<string> &soung_text,const int choice);

vector<string> readTextFromFile(string &path_to_file);

void writeTextToFile(string &path_to_file,const vector<string> &soung_text);

void editSong(vector<Sounds> &song_catalog,const int choice,ScreenState* screen_state = nullptr);

void findSongsByAuthor(vector<Sounds> &song_catalog,const int choice,ScreenState* screen_state = nullptr);

void findSongsByWord(vector<Sounds> &song_catalog,const int choice,ScreenState* screen_state = nullptr);

void displayFullSong(vector<Sounds> &song_catalog,const int choice,ScreenState* screen_state = nullptr);

void saveTextSongToFile(vector<Sounds> &song_catalog,const int choice,ScreenState* screen_state = nullptr);

// ФУНКЦИИ ДЛЯ СМЕНЫ ЯЗЫКА
bool loadLanguagePack(const string& lang_code);
void changeLanguage(const int choice, ScreenState* screen_state_ptr = nullptr);
