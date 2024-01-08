#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "../Common_Function.h"
#include "CH4_Function.h"

int strindex_EX4_1(char* s, char* t)
{
	int ret = NOT_FOUND;
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;

		if (t[k] == '\0') 
			ret = i;
	}
	return ret;
}

int EX4_1_main(char* main, char* sub)
{
	int find;

	printf("Main : %s\n", main);
	printf("Sub : %s\n", sub);

	find = strindex_EX4_1(main, sub);
	if (find != NOT_FOUND)
		printf("Result = FIND!, idx = %d\n", find);
	else
		printf("Result = NOT_FIND!\n");
}

double atof_EX4_2(char* s)
{
	if (s == NULL)
		return 0;

	double fragment_scale = 0.1;
	double cur_scale, exp_scale;
	int integar_scale = 10;
	int sign, exp_sign;
	double retval = 0;
	int exp = 0;
	int i = 0;

	// check white space
	while (str_IsWhiteSpace(s, i))
		i++;

	// check sign
	sign = str_GetSign(s, i);
	if (sign == NEGATIVE || sign == POSITIVE_PLUS)
		i++;

	// calculate the integer part.
	while (str_IsDigits(s, i)) {
		retval *= integar_scale;
		retval += (s[i++] - '0');
	}

	// Calculate the fractional part
	if (s[i] == '.') {
		i++;
		cur_scale = fragment_scale;
		while (str_IsDigits(s, i)) {
			retval += cur_scale * (s[i] - '0');
			i++;
			cur_scale *= fragment_scale;
		}
	}

	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		exp_sign = str_GetSign(s, i);

		if (exp_sign == NEGATIVE || exp_sign == POSITIVE_PLUS)
			i++;
		while (s[i] == '0')
			i++;

		while (str_IsDigits(s, i)) {
			exp *= integar_scale;
			exp += (s[i] - '0');
			i++;
		}

		if (exp_sign > 0)
			exp_scale = 10;
		else
			exp_scale = 0.1;

		while (exp > 0) {
			retval *= exp_scale;
			exp--;
		}
	}

	return retval;
}

int EX4_2_main(char** testCase)
{
	int i = 0;

	for (; i < EX4_2_UNIT_TEST_LEN; i++)
		printf("[%s , %g]\n", testCase[i], atof_EX4_2(testCase[i]));
}

int do_EX4_3(char* input, int* val) {
	if (input == NULL) {
		printf("No input detected!\n");
		return POINTER_NULL;
	}

	int a, b, ch, ret, cur_len;
	int i = 0;

	Stack_init();

	while ((ch = input[i]) != '\0') {
		switch (ch) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			{
				Stack_push(ch - '0');
				break;
			}//end of case '0'~'9'

			case '+':
			{
				if ((cur_len = Stack_getLength()) < 2)
					return FALSE;

				a = Stack_pop();
				b = Stack_pop();
				Stack_push(a + b);
				break;
			} //end of case '+'

			case '*':
			{
				if ((cur_len = Stack_getLength()) < 2)
					return FALSE;

				a = Stack_pop();
				b = Stack_pop();
				Stack_push(a * b);
				break;
			}//end of case '*'

			case '-':
			{
				if ((cur_len = Stack_getLength()) < 2)
					return FALSE;

				a = Stack_pop();
				b = Stack_pop();
				Stack_push(b - a);
				break;
			}//end of case '-'

			case '/':
			{
				if ((cur_len = Stack_getLength()) < 2)
					return FALSE;

				a = Stack_pop();
				b = Stack_pop();
				if(a!=0)
					Stack_push(b / a);
				break;
			}//end of case '/'

			case '%':
			{
				if ((cur_len = Stack_getLength()) < 2)
					return FALSE;

				a = Stack_pop();
				b = Stack_pop();
				if (a != 0)
					Stack_push(b % a);
				break;
			}

			case SIN:
			{
				if (Stack_isEmpty())
					return FALSE;

				int tmp = Stack_pop();
				Stack_push(sin(tmp));
				break;
			}
			case EXP:
			{
				if (Stack_isEmpty())
					return FALSE;

				int tmp = Stack_pop();
				Stack_push(exp(tmp));
				break;
			}
			case POW:
			{
				if ((cur_len = Stack_getLength()) < 2)
					return FALSE;

				a = Stack_pop();
				b = Stack_pop();
				
				int tmp = pow(b, a);
				if (INT_MIN < tmp < INT_MAX)
					Stack_push(tmp);
				else
					printf("pow overflow or underflow\n");
				break;
			}

			default:
				break;
		}
		i++;
	}

	*val = Stack_pop();

	return (Stack_isEmpty()) ? TRUE : FALSE;
}

void EX4_3_main(char* input)
{
	int val = 0;
	printf("[Input = %s]\n", input);

	if (!do_EX4_3(input, &val)) {
		printf("[ERROR] Invalid input!\n");
		return;
	}

	printf("[Result = % d]\n", val);
	Stack_clear();
}

void EX4_7_main(char* input, int Exer)
{
	int i = 0, c;

	if (Exer == EXERCISE_4_8) {
		if (sizeof(input) > 1)
			goto sizeInvalid;
	}

	Stack_init();

	/* EX4_9, we take EOF as a stop char */
	while (i < sizeof(input) && input[i] != '\0')
		Stack_push(input[i++]);

	printf("[Output] : ");

	while ((c = Stack_pop()) != INVALID)
		printf("%c", c);

	return;

sizeInvalid:
	printf("size of input isn't 1!\n");
	return;
}

void EX4_10_main(FILE** ptr, int mode)
{
	char input[LINE_MAX_LENGTH];
	int ch, len, ret;
	int i = 0;

	Stack_init();

	if (mode = MODE_GETLINE) {
		while ((len = getline_from_txt(ptr, input)) > 0) {
			i = 0;
			printf("Line Get : %s\n", input);

			/* Push */
			while (i < len && input[i] != '\0')
				Stack_push(input[i++]);

			/* Pop */
			while ((ch = Stack_pop()) != INVALID)
				printf("%c", ch);

			printf("------------------------------------------\n");
		}
	} else {
		while ((ret = getchar_from_txt(&ptr, &ch)) != 0)
			Stack_push(ch);

		while ((ch = Stack_pop()) != INVALID)
			printf("%c", ch);

		printf("------------------------------------------\n");
	}
}

void EX4_12_itoa(int n, char* s)
{
	if (n) {
		*s++ = abs(n % 10) + '0';
		*s = '\0';
		n /= 10;
		EX4_12_itoa(n, s);
	}

	return;
}

void EX4_12_main(int val)
{
	char res[IDX_MAX_LENGTH];
	char* ptr = res;
	int idx = 0;
	
	if (val < 0) {
		val *= -1;
		*ptr++ = '-';
	}

	EX4_12_itoa(val, ptr);
	str_reverse(ptr);

	printf("val in string is %s\n", res);
}

void str_reverse_EX4_13(char* s, int left, int right) {
	int tmp;

	if (left < right && (s != NULL)) {
		tmp = s[right];
		s[right] = s[left];
		s[left] = tmp;
		str_reverse_EX4_13(s, ++left, --right);
	}

	return;
}

void EX4_13_main(char* s)
{
	int length = strlen(s);

	str_reverse_EX4_13(s, 0, length - 1);
	printf("output = %s\n", s);

	return;
}