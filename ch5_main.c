#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ch5_function.h"
#include "../Common_Function.h"

static exercise_info ch5_exercise_infos[CH5_TOTAL_EXER] = {
	EXERCISE("", ""),
	EXERCISE("EXERCISE_5_1", NULL),
	EXERCISE("EXERCISE_5_2", NULL),
	EXERCISE("EXERCISE_5_3", NULL),
	EXERCISE("EXERCISE_5_4", NULL),
	EXERCISE("EXERCISE_5_5", NULL),
	EXERCISE("EXERCISE_5_6", NULL),
	EXERCISE("EXERCISE_5_7", "C:/Users/wan29/OneDrive/орн▒/The C Programming/EXEXCISE_TXT/EX5_7.txt"),
	EXERCISE("EXERCISE_5_8", NULL),
	EXERCISE("EXERCISE_5_9", NULL),
	EXERCISE("EXERCISE_5_10", NULL),
	EXERCISE("EXERCISE_5_11", NULL),
	EXERCISE("EXERCISE_5_12", NULL),
	EXERCISE("EXERCISE_5_13", "C:/Users/wan29/OneDrive/орн▒/The C Programming/EXEXCISE_TXT/EX5_13.txt"),
};

int main()
{
	ch5_exer exNum = EXERCISE_5_1;
	exercise_info exer = ch5_exercise_infos[exNum];
	FILE* ptr;
	double fval;
	int ret;
	int val;

	if (!fileOpen(&exer, &ptr))
		goto FileNotFound;

	printf("Start %s...\n", exer.exer_name);

	switch (exNum)
	{
		case EXERCISE_5_1:
			char sInput_EX1[LINE_MAX_LENGTH] = " -1211155";
			
			ret = EX5_1_main(sInput_EX1, &val);
			if (ret)
				goto InvalidInput;

			printf("Val = %d\n", val);
			break;

		case EXERCISE_5_2:
			char sInput_EX2[LINE_MAX_LENGTH] = " -55422.5410";

			ret = EX5_2_main(sInput_EX2, &fval);
			if (ret)
				goto InvalidInput;

			printf("Input = %f\n", fval);
			break;

		case EXERCISE_5_3:
			char sInput0_EX3[LINE_MAX_LENGTH] = "GGGG132";
			char sInput1_EX3[LINE_MAX_LENGTH] = "TTTT321";

			EX5_3_main(sInput0_EX3, sInput1_EX3);
			printf("Output: %s\n", sInput0_EX3);

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

InvalidInput:
	printf("[ERROR] Input Invalid!\n");
	return 0;
}