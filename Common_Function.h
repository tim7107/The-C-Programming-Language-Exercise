#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include "of_bit.h"

/* success/fail flag */
#define SUCCESS			1
#define FAIL			0

#define _CRT_SECURE_NO_WARNINGS
#define NOT_FOUND        -1
#define INVALID          0
#define POINTER_NULL     0
#define FALSE            0
#define VALID			 1
#define TRUE             1
#define BYTE_TO_BIT 	 8 
#define NEGATIVE         -1
#define POSITIVE         1
#define POSITIVE_EMPTY   1
#define POSITIVE_PLUS    2
#define PI               3.1415926

#define LINE_MAX_LENGTH  1000
#define IDX_MAX_LENGTH   1000

#define SPACE        	 ' '
#define TAB          	 '\t'
#define NEW_LINE     	 '\n'
#define QUOTE		 	 '"'
#define SLASH        	 '/'
#define STAR         	 '*'
#define EXIT         	 "EXIT"

#define CUR_LEVEL   3

#define EXERCISE(_exer, _file) \
{	\
	.exer_name = _exer, \
	.file_name = _file \
}

typedef struct {
	char* exer_name;
	char* file_name;
} exercise_info;

typedef enum {
	C_FATAL    = 0,
	C_ERROR    = 1,
	C_WARNING  = 2,
	C_INFO     = 3,
	C_DEBUG    = 4,
}PRINTF_LEVEL;

#define C_PRINTF(CUR_LEVEL, level, fmt, ...) do{\
	if(CUR_LEVEL >= level){                      \
		switch(level){                           \
			case C_FATAL:                        \
				printf("[C_FATAL]" fmt, __VA_ARGS__); \
				break;                           \
			case C_ERROR:                        \
				printf("[C_ERROR]" fmt, __VA_ARGS__); \
				break;                           \
			case C_WARNING:                        \
				printf("[C_WARNING]" fmt, __VA_ARGS__); \
				break;                           \
			case C_INFO:                         \
				printf("[C_INFO]" fmt, __VA_ARGS__);  \
				break;                           \
			case C_DEBUG:                        \
				printf("[C_DEBUG]" fmt, __VA_ARGS__); \
				break;                           \
		}										 \
	}											 \
}while(0);

int   Stack_idx;
int   Stack[IDX_MAX_LENGTH];
char  INPUT_LINE[LINE_MAX_LENGTH];
char  OUTPUT_LINE[LINE_MAX_LENGTH];

// Useful functions
int   IsOverflow(int val);
int   Is_Digits(int s);
int   Is_Letters(int s);
int   Is_WhiteSpace(int s);

int   User_Array_Input(int* s);
int   getline_from_txt(FILE** pptr, char* input);
int   getchar_from_txt(FILE** pptr, char* ch);
int   getline_from_txt_v1(FILE* ptr, char* input, const int of_mode);
int   getword_from_txt(FILE** pptr, char* word);
int   GetLineLength(char* pArray);


// String Related 
void  printf_array(char* array);
void  Show_int_array(int s[], int n);
void  str_swap(char* a, char* b);
void  str_reverse(char s[]);
int   str_Cmp(char* s1, char* s2);
int   str_IsWhiteSpace(char* s, int idx);
int   str_GetSign(char* s, int idx);
int   str_IsDigits(char* s, int i);
void  str_Cat(char* s, char* t);
int   str_EndCompare(char* s, char* t);
void  str_ncpy(char* s, char* t, int n);
void  str_nCat(char* s, char* t, int n);
int   str_nCmp(char* s, char* t, int n);
int   str_find_index(char* s, char* tar);
void  str_swap_element(char* s, int i, int j);

//Stack Related
void  Stack_init(void);
void  Stack_push(int data);
int   Stack_pop(void);
int   Stack_top(void);
int   Stack_isEmpty(void);
int   Stack_getLength(void);
void  Stack_print(void);
void  Stack_show_top(void);
void  Stack_clear(void);
void  Stack_swap_top_two_ele(void);
void  Stack_duplicate(void);

//Others
char* Decimal2Binary(int decimal);
int   Char_IsDigits(char* c);
int   Char_IsWhiteSpace(char* c);
int   atoi_pointer_ver(char* s);
void  itoa_pointer_ver(int x);
void  str_reverse_pointer_ver(char* s);
void  int_swap(char* s, int i, int j);
void  swap_array_char(void* v[], int i, int j);