#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{

	/* A file pointer is declared using the FILE type */
	FILE *f_ptr;
	char ch;
	int numOfWords = 1;
	int numOfLines = 0;
	int currLet = 0;
	int syllableCount = 0;
	int preLet = 0;
	char preCh = 'd';
	float index;

	/* The file is opened using open */
	f_ptr = fopen("testing.txt", "r");

	/* If file opened successfully, then write the string into the file */
	if (f_ptr)
	{
		ch = fgetc(f_ptr);
		while (ch != EOF)
		{
			/*printf("ch value: %c\n", ch);*/
			/*	printf("test syll: %d\n", syllableCount);*/
			/*	printf("%c", ch);*/

			/* Count the number of words in a file */
			if (ch == ' ' || ch == '\n')
			{
				numOfWords++;
			}

			/*	Count all syllables in every word */
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y')
			{
				syllableCount = syllableCount + 1;
				currLet = 1;
				/*printf("vowel: %c\n", ch);*/
				/*printf("syllable: %d\n", syllableCount);*/
			}
			/*	printf("current let: %d\n", currLet);
				printf("pre let: %d\n", preLet); */

			if ((currLet == 1) && (preLet == 1))
			{
				syllableCount = syllableCount - 1;
				/*printf("im here %d\n", syllableCount);*/
			}

			if ((ch == ' ' || ch == '\n' || ch == '.') && (preCh == 'e'))
			{
				syllableCount = syllableCount - 1;
				/*printf("my ch %d\n", syllableCount);*/
				/*printf("TempCount: %d\n", tempCount);*/
			}

			preLet = currLet;
			currLet = 0;
			preCh = ch;

			/* Count the number of sentences in a file */
			if (ch == '.' || ch == ':' || ch == ';' || ch == '?' || ch == '!')
			{
				numOfLines++;
			}

			ch = fgetc(f_ptr);
		}

		/* Calculate the flesch index */
		index = 206.835 - 84.6 * (syllableCount / numOfWords) - 1.015 * (numOfWords / numOfLines);
		index = round(index);

		/* Print the following */
		printf("Flesch Index = %.0f\n", index);
		printf("Syllable Count = %d\n", syllableCount);
		printf("Word Count = %d\n", numOfWords);
		printf("Sentence Count = %d\n", numOfLines);
	}
	else
	{
		/* The file is not found */
		printf("File not found");
	}

	/* Close the file when finshed reading or writing it */
	fclose(f_ptr);

	return 0;
}
