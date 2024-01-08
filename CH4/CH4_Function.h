#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CH4_TOTAL_EXER		14
#define CUR_LEVEL			C_DEBUG
#define SIN					'~'
#define EXP					'^'
#define POW					'$'
#define EX4_2_UNIT_TEST_LEN	4

typedef enum {
	MODE_GETCH,
	MODE_GETLINE,
} EX4_10_INPUT_MODE;

typedef enum {
	EXERCISE_4_1 = 1,
	EXERCISE_4_2,
	EXERCISE_4_3,
	EXERCISE_4_4,
	EXERCISE_4_5,
	EXERCISE_4_6,
	EXERCISE_4_7,
	EXERCISE_4_8,
	EXERCISE_4_9,
	EXERCISE_4_10,
	EXERCISE_4_11,
	EXERCISE_4_12,
	EXERCISE_4_13,
	EXERCISE_4_14,
	TEST,
} CH4_EXER;

int EX4_1_main(char* main, char* sub);
int EX4_2_main(char** testCase);
void EX4_3_main(char* input);
void EX4_7_main(char* input, int Exer);
void EX4_10_main(FILE** ptr, int mode);
void EX4_12_main(void);
void EX4_13_main(char* s);