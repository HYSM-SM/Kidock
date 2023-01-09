#pragma once

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <termios.h>
#include <vector>
#include <utility>
#include <string>
#include <iostream>

#define CLEAR_CHARACTER std::cout << '\b';

#define KEY_Q 'Q'
#define KEY_W 'W'
#define KEY_E 'E'
#define KEY_R 'R'
#define KEY_T 'T'
#define KEY_Y 'Y'
#define KEY_U 'U'
#define KEY_I 'I'
#define KEY_O 'O'
#define KEY_P 'P'
#define KEY_A 'A'
#define KEY_S 'S'
#define KEY_D 'D'
#define KEY_F 'F'
#define KEY_G 'G'
#define KEY_H 'H'
#define KEY_J 'J'
#define KEY_K 'K'
#define KEY_L 'L'
#define KEY_Z 'Z'
#define KEY_X 'X'
#define KEY_C 'C'
#define KEY_V 'V'
#define KEY_B 'B'
#define KEY_N 'N'
#define KEY_M 'M'
#define KEY_q 'q'
#define KEY_w 'w'
#define KEY_e 'e'
#define KEY_r 'r'
#define KEY_t 't'
#define KEY_y 'y'
#define KEY_u 'u'
#define KEY_i 'i'
#define KEY_o 'o'
#define KEY_p 'p'
#define KEY_a 'a'
#define KEY_s 's'
#define KEY_d 'd'
#define KEY_f 'f'
#define KEY_g 'g'
#define KEY_h 'h'
#define KEY_j 'j'
#define KEY_k 'k'
#define KEY_l 'l'
#define KEY_z 'z'
#define KEY_x 'x'
#define KEY_c 'c'
#define KEY_v 'v'
#define KEY_b 'b'
#define KEY_n 'n'
#define KEY_m 'm'
#define KEY_NUM_1 '1'
#define KEY_NUM_2 '2'
#define KEY_NUM_3 '3'
#define KEY_NUM_4 '4'
#define KEY_NUM_5 '5'
#define KEY_NUM_6 '6'
#define KEY_NUM_7 '7'
#define KEY_NUM_8 '8'
#define KEY_NUM_9 '9'
#define KEY_NUM_0 '0'
#define KEY_ESCAPE char(27)
#define KEY_ADD '+'
#define KEY_MUL '*'
#define KEY_SUB '-'
#define KEY_DIV char(47) // slash
#define KEY_EQUAL '='
#define KEY_SPACE ' '
#define KEY_ENTER '\n'
#define KEY_BACKSPACE char(127)
#define KEY_TAB '\t'
#define KEY_TILDE '~'
#define KEY_RIGHT_CURLY_BRACE '}'
#define KEY_LEFT_CURLY_BRACE '{'
#define KEY_VERTICAL_BAR '|'
#define KEY_GRAVE_ACCENT char(96) // `
#define KEY_UNDERSCORE '_'
#define KEY_CARET '^'
#define KEY_RIGHT_SQUARE_BRACKET ']'
#define KEY_LEFT_SQUARE_BRACKET '['
#define KEY_BACKSLASH '\\'
#define KEY_SIGN '@'
#define KEY_QUESTION '?'
#define KEY_GREATER_THAN '>'
#define KEY_LESS_THAN '<'
#define KEY_SEMICOLON ';'
#define KEY_COLON ':'
#define KEY_PERIOD '.'
#define KEY_COMMA ','
#define KEY_RIGHT_PARENTHESIS ')'
#define KEY_LEFT_PARENTHESIS '('
#define KEY_APOSTROPHE char(39) // '
#define KEY_AMPERSAND '&'
#define KEY_PRECENT '%'
#define KEY_DOLLAR '$'
#define KEY_NUMBER '#'
#define KEY_QUOTATION '"'
#define KEY_EXCLAMATION '!'

class Keyboard
{
    private:

    inline static std::vector<std::pair<int,std::string>> keyboard =
    {
        std::make_pair<int,std::string>(KEY_Q,std::string(1,KEY_Q)),
        std::make_pair<int,std::string>(KEY_W,std::string(1,KEY_W)),
        std::make_pair<int,std::string>(KEY_E,std::string(1,KEY_E)),
        std::make_pair<int,std::string>(KEY_R,std::string(1,KEY_R)),
        std::make_pair<int,std::string>(KEY_T,std::string(1,KEY_T)),
        std::make_pair<int,std::string>(KEY_Y,std::string(1,KEY_Y)),
        std::make_pair<int,std::string>(KEY_U,std::string(1,KEY_U)),
        std::make_pair<int,std::string>(KEY_I,std::string(1,KEY_I)),
        std::make_pair<int,std::string>(KEY_O,std::string(1,KEY_O)),
        std::make_pair<int,std::string>(KEY_P,std::string(1,KEY_P)),
        std::make_pair<int,std::string>(KEY_A,std::string(1,KEY_A)),
        std::make_pair<int,std::string>(KEY_S,std::string(1,KEY_S)),
        std::make_pair<int,std::string>(KEY_D,std::string(1,KEY_D)),
        std::make_pair<int,std::string>(KEY_F,std::string(1,KEY_F)),
        std::make_pair<int,std::string>(KEY_G,std::string(1,KEY_G)),
        std::make_pair<int,std::string>(KEY_H,std::string(1,KEY_H)),
        std::make_pair<int,std::string>(KEY_J,std::string(1,KEY_J)),
        std::make_pair<int,std::string>(KEY_K,std::string(1,KEY_K)),
        std::make_pair<int,std::string>(KEY_L,std::string(1,KEY_L)),
        std::make_pair<int,std::string>(KEY_Z,std::string(1,KEY_Z)),
        std::make_pair<int,std::string>(KEY_X,std::string(1,KEY_X)),
        std::make_pair<int,std::string>(KEY_C,std::string(1,KEY_C)),
        std::make_pair<int,std::string>(KEY_V,std::string(1,KEY_V)),
        std::make_pair<int,std::string>(KEY_B,std::string(1,KEY_B)),
        std::make_pair<int,std::string>(KEY_N,std::string(1,KEY_N)),
        std::make_pair<int,std::string>(KEY_M,std::string(1,KEY_M)),
        std::make_pair<int,std::string>(KEY_q,std::string(1,KEY_q)),
        std::make_pair<int,std::string>(KEY_w,std::string(1,KEY_w)),
        std::make_pair<int,std::string>(KEY_e,std::string(1,KEY_e)),
        std::make_pair<int,std::string>(KEY_r,std::string(1,KEY_r)),
        std::make_pair<int,std::string>(KEY_t,std::string(1,KEY_t)),
        std::make_pair<int,std::string>(KEY_y,std::string(1,KEY_y)),
        std::make_pair<int,std::string>(KEY_u,std::string(1,KEY_u)),
        std::make_pair<int,std::string>(KEY_i,std::string(1,KEY_i)),
        std::make_pair<int,std::string>(KEY_o,std::string(1,KEY_o)),
        std::make_pair<int,std::string>(KEY_p,std::string(1,KEY_p)),
        std::make_pair<int,std::string>(KEY_a,std::string(1,KEY_a)),
        std::make_pair<int,std::string>(KEY_s,std::string(1,KEY_s)),
        std::make_pair<int,std::string>(KEY_d,std::string(1,KEY_d)),
        std::make_pair<int,std::string>(KEY_f,std::string(1,KEY_f)),
        std::make_pair<int,std::string>(KEY_g,std::string(1,KEY_g)),
        std::make_pair<int,std::string>(KEY_h,std::string(1,KEY_h)),
        std::make_pair<int,std::string>(KEY_j,std::string(1,KEY_j)),
        std::make_pair<int,std::string>(KEY_k,std::string(1,KEY_k)),
        std::make_pair<int,std::string>(KEY_l,std::string(1,KEY_l)),
        std::make_pair<int,std::string>(KEY_z,std::string(1,KEY_z)),
        std::make_pair<int,std::string>(KEY_x,std::string(1,KEY_x)),
        std::make_pair<int,std::string>(KEY_c,std::string(1,KEY_c)),
        std::make_pair<int,std::string>(KEY_v,std::string(1,KEY_v)),
        std::make_pair<int,std::string>(KEY_b,std::string(1,KEY_b)),
        std::make_pair<int,std::string>(KEY_n,std::string(1,KEY_n)),
        std::make_pair<int,std::string>(KEY_m,std::string(1,KEY_m)),
        std::make_pair<int,std::string>(KEY_M,std::string(1,KEY_M)),
        std::make_pair<int,std::string>(KEY_NUM_0,std::string(1,KEY_NUM_0)),
        std::make_pair<int,std::string>(KEY_NUM_1,std::string(1,KEY_NUM_1)),
        std::make_pair<int,std::string>(KEY_NUM_2,std::string(1,KEY_NUM_2)),
        std::make_pair<int,std::string>(KEY_NUM_3,std::string(1,KEY_NUM_3)),
        std::make_pair<int,std::string>(KEY_NUM_4,std::string(1,KEY_NUM_4)),
        std::make_pair<int,std::string>(KEY_NUM_5,std::string(1,KEY_NUM_5)),
        std::make_pair<int,std::string>(KEY_NUM_6,std::string(1,KEY_NUM_6)),
        std::make_pair<int,std::string>(KEY_NUM_7,std::string(1,KEY_NUM_7)),
        std::make_pair<int,std::string>(KEY_NUM_8,std::string(1,KEY_NUM_8)),
        std::make_pair<int,std::string>(KEY_NUM_9,std::string(1,KEY_NUM_9)),
        std::make_pair<int,std::string>(KEY_ESCAPE,std::string(1,'?')),
        std::make_pair<int,std::string>(KEY_ADD,std::string(1,KEY_ADD)),
        std::make_pair<int,std::string>(KEY_SUB,std::string(1,KEY_SUB)),
        std::make_pair<int,std::string>(KEY_MUL,std::string(1,KEY_MUL)),
        std::make_pair<int,std::string>(KEY_DIV,std::string(1,KEY_DIV)),
        std::make_pair<int,std::string>(KEY_EQUAL,std::string(1,KEY_EQUAL)),
        std::make_pair<int,std::string>(KEY_ENTER,std::string(1,KEY_ENTER)),
        std::make_pair<int,std::string>(KEY_SPACE,std::string(1,KEY_SPACE)),
        std::make_pair<int,std::string>(KEY_BACKSPACE,std::string("\b \b")),
        std::make_pair<int,std::string>(KEY_TAB,std::string(1,KEY_TAB)),
        std::make_pair<int,std::string>(KEY_TILDE,std::string(1,KEY_TILDE)),
        std::make_pair<int,std::string>(KEY_RIGHT_CURLY_BRACE,std::string(1,KEY_RIGHT_CURLY_BRACE)),
        std::make_pair<int,std::string>(KEY_LEFT_CURLY_BRACE,std::string(1,KEY_LEFT_CURLY_BRACE)),
        std::make_pair<int,std::string>(KEY_VERTICAL_BAR,std::string(1,KEY_VERTICAL_BAR)),
        std::make_pair<int,std::string>(KEY_GRAVE_ACCENT,std::string(1,KEY_GRAVE_ACCENT)),
        std::make_pair<int,std::string>(KEY_UNDERSCORE,std::string(1,KEY_UNDERSCORE)),
        std::make_pair<int,std::string>(KEY_CARET,std::string(1,KEY_CARET)),
        std::make_pair<int,std::string>(KEY_RIGHT_SQUARE_BRACKET,std::string(1,KEY_RIGHT_SQUARE_BRACKET)),
        std::make_pair<int,std::string>(KEY_LEFT_SQUARE_BRACKET,std::string(1,KEY_LEFT_SQUARE_BRACKET)),
        std::make_pair<int,std::string>(KEY_BACKSLASH,std::string(1,KEY_BACKSLASH)),
        std::make_pair<int,std::string>(KEY_SIGN,std::string(1,KEY_SIGN)),
        std::make_pair<int,std::string>(KEY_QUESTION,std::string(1,KEY_QUESTION)),
        std::make_pair<int,std::string>(KEY_GREATER_THAN,std::string(1,KEY_GREATER_THAN)),
        std::make_pair<int,std::string>(KEY_LESS_THAN,std::string(1,KEY_LESS_THAN)),
        std::make_pair<int,std::string>(KEY_SEMICOLON,std::string(1,KEY_SEMICOLON)),
        std::make_pair<int,std::string>(KEY_COLON,std::string(1,KEY_COLON)),
        std::make_pair<int,std::string>(KEY_PERIOD,std::string(1,KEY_PERIOD)),
        std::make_pair<int,std::string>(KEY_COMMA,std::string(1,KEY_COMMA)),
        std::make_pair<int,std::string>(KEY_RIGHT_PARENTHESIS,std::string(1,KEY_RIGHT_PARENTHESIS)),
        std::make_pair<int,std::string>(KEY_LEFT_PARENTHESIS,std::string(1,KEY_LEFT_PARENTHESIS)),
        std::make_pair<int,std::string>(KEY_APOSTROPHE,std::string(1,KEY_APOSTROPHE)),
        std::make_pair<int,std::string>(KEY_AMPERSAND,std::string(1,KEY_AMPERSAND)),
        std::make_pair<int,std::string>(KEY_PRECENT,std::string(1,KEY_PRECENT)),
        std::make_pair<int,std::string>(KEY_DOLLAR,std::string(1,KEY_DOLLAR)),
        std::make_pair<int,std::string>(KEY_NUMBER,std::string(1,KEY_NUMBER)),
        std::make_pair<int,std::string>(KEY_QUOTATION,std::string(1,KEY_QUOTATION)),
        std::make_pair<int,std::string>(KEY_EXCLAMATION,std::string(1,KEY_EXCLAMATION))
    };
    inline static int key = 0;
    inline static bool keyboard_processing = true;
    inline static struct termios oldt;

    public:
    
    static void run();
    static bool pressedKeysIs(int k1,int k2);
    static bool pressedKeyIs(int k);
    static void clearKey();
    static bool kbhit();
    static std::pair<int,std::string> getKey(int index);
    static std::size_t getSize();
    static int getEnterKey();
    static void terminate();
};

#endif
