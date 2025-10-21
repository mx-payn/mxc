#ifndef ANSI_H_
#define ANSI_H_

#define ANSI_ESC "\x1b["
#define ANSI_FIN "m"
#define ANSI_SEP ";"
#define ANSI_RESET ANSI_ESC "0" ANSI_FIN

#define ANSI_BOLD "1"
#define ANSI_DIM "2"
#define ANSI_ITALIC "3"
#define ANSI_UNDERLINE "4"
#define ANSI_STRIKETHROUGH "9"

#define ANSI_RESET_BOLD "22"
#define ANSI_RESET_DIM "22"
#define ANSI_RESET_ITALIC "23"
#define ANSI_RESET_UNDERLINE "24"
#define ANSI_RESET_STRIKETHROUGH "29"

#define ANSI_FG_BLACK "30"
#define ANSI_FG_RED "31"
#define ANSI_FG_GREEN "32"
#define ANSI_FG_YELLOW "33"
#define ANSI_FG_BLUE "34"
#define ANSI_FG_MAGENTA "35"
#define ANSI_FG_CYAN "36"
#define ANSI_FG_WHITE "37"
#define ANSI_FG_DEFAULT "39"

#define ANSI_BG_BLACK "40"
#define ANSI_BG_RED "41"
#define ANSI_BG_GREEN "42"
#define ANSI_BG_YELLOW "43"
#define ANSI_BG_BLUE "44"
#define ANSI_BG_MAGENTA "45"
#define ANSI_BG_CYAN "46"
#define ANSI_BG_WHITE "47"
#define ANSI_BG_DEFAULT "49"

#endif  // ANSI_H_
