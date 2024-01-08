#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "CH4_Function.h"
#include "../Common_Function.h"

static exercise_info ch4_exercise_infos[CH4_TOTAL_EXER] = {
	EXERCISE("", ""),
	EXERCISE("EXERCISE_4_1", NULL),
	EXERCISE("EXERCISE_4_2", NULL),
	EXERCISE("EXERCISE_4_3", NULL),
	EXERCISE("EXERCISE_4_4", NULL),
	EXERCISE("EXERCISE_4_5", NULL),
	EXERCISE("EXERCISE_4_6", NULL),
	EXERCISE("EXERCISE_4_7", NULL),
	EXERCISE("EXERCISE_4_8", NULL),
	EXERCISE("EXERCISE_4_9", NULL),
	EXERCISE("EXERCISE_4_10", "C:/Users/wan29/OneDrive/орн▒/The C Programming/EXEXCISE_TXT/EX4_10.txt"),
	EXERCISE("EXERCISE_4_11", NULL),
	EXERCISE("EXERCISE_4_12", NULL),
	EXERCISE("EXERCISE_4_13", NULL),
};

int main()
{
	CH4_EXER exNum = EXERCISE_4_12;
	exercise_info exer = ch4_exercise_infos[exNum];
	FILE* ptr;

	if (!fileOpen(&exer, &ptr))
		goto FileNotFound;

	printf("Start %s...\n", exer.exer_name);

	switch (exNum)
	{
		case EXERCISE_4_1:
			char main[LINE_MAX_LENGTH] = "apppppple";
			char sub[LINE_MAX_LENGTH] = "p";

			EX4_1_main(main, sub);
			break;

		case EXERCISE_4_2:
			char* unit_test[EX4_2_UNIT_TEST_LEN] =
			{
				"123.45e-6",
				"-1.2e-3",
				"-1.2E3",
				"-1.2e03",
			};

			EX4_2_main(&unit_test);
			break;

		case EXERCISE_4_3:
		case EXERCISE_4_4:
		case EXERCISE_4_5:
		case EXERCISE_4_6:
			char sInput_EX3To6[LINE_MAX_LENGTH] = "12+4*6*";

			EX4_3_main(sInput_EX3To6);
			break;

		case EXERCISE_4_7:
		case EXERCISE_4_8:
		case EXERCISE_4_9:
			char sInput_EX7To9[LINE_MAX_LENGTH];

			printf("Plz enter str input\n");
			scanf("%s", sInput_EX7To9);

			EX4_7_main(sInput_EX7To9, exNum);
			break;

		case EXERCISE_4_10:
			EX4_10_INPUT_MODE mode;

			printf("Choose mode:\n");
			printf("\t* getch   : 1\n");
			printf("\t* getline : 2\n");
			scanf("%d", &mode);

			EX4_10_main(&ptr, mode);
			break;
		
		case EXERCISE_4_12:
			int val;

			printf("Plz enter int input \n");
			scanf("%d", &val);

			if (!IsOverflow(val))
				goto Overflow;

			EX4_12_main(val);
			break;

		case EXERCISE_4_13:
			char input[IDX_MAX_LENGTH];
			
			printf("Plz enter str input \n");
			scanf("%s", input);

			EX4_13_main(input);
			break;

		default:
			break;
	}

	return 0;

FileNotFound:
	printf("[ERROR] Open file fail!\n");
	return 0;

Overflow:
	printf("[ERROR] Input Overflow!\n");
	return 0;
}