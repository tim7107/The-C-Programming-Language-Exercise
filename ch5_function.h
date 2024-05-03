#define _BIT_REVERSE_			0x01      /*bit 0*/
#define _BIT_FOLD_				0x02      /*bit 1*/
#define _BIT_DIRECTORY_ORDER_   0x04      /*bit 2*/


typedef enum {
	EXERCISE_5_1 = 1,
	EXERCISE_5_2,
	EXERCISE_5_3,
	EXERCISE_5_4,
	EXERCISE_5_5,
	EXERCISE_5_6,
	EXERCISE_5_7,
	EXERCISE_5_8,
	EXERCISE_5_9,
	EXERCISE_5_10,
	EXERCISE_5_11,
	EXERCISE_5_12,
	EXERCISE_5_13,
	EXERCISE_5_14,
	CH5_TOTAL_EXER,

	TEST,
} ch5_exer;

static char DAY_TABLE[2][13] = {
		{0,31,28,31,30,31,30,31,31,30,31,30,31},
		{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

/*
char s1[LINE_MAX_LENGTH];
char s2[LINE_MAX_LENGTH];
char s3[LINE_MAX_LENGTH];
*/

int EX5_1_main(char* input, int* val);
int EX5_2_main(char* input, double* sum);
int  Text_readlines_EX_5_7(FILE** pptr, char** lineptr, char* ls);
void writelines_EX_5_7(char** lineptr, int nlines);
int  Day_of_year_EX5_8(int year, int month, int day);
void Month_day_EX5_8(int y_day, int year, int* p_month, int* p_day);
int  Day_of_year_EX5_9(int year, int month, int day);
void Month_day_EX5_9(int y_day, int year, int* p_month, int* p_day);
int  EX5_10(int argc, char* argv[]);
int  EX5_13_readlines(FILE** pptr, char** lineptr, char* line, int* linelen);
void EX_5_13_writelines(char** lineptr, int nlines, int* linelen, int argc, char* argv[]);

// EX5_14_to_17
int  EX5_14_Check_valid(char* s);
int  Check_swap(char* s, int j, int high);
void EX_5_14_QuickSort_char(char* s, int low, int high);
void EX_5_14_QuickSort_Main(char* s, int low, int high, int argc, char** argv);
