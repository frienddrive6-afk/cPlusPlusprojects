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
    EXIT_PROGRAM
};

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
