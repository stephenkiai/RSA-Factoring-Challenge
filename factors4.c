#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * factorize_number- Factorizes a number into pairs of smaller numbers.
 *
 * @n: The number to factorize.
 */
void factorize_number(long long n)
{
	long long least_factor = n; /* Initialize the least factor to n */

	for (long long i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			least_factor = i; /* Update the least factor */
			break; /* Exit loop after the least factor is found */
		}
	}

	if (least_factor == n)
	{ /* Print the number is prime */
		printf("%lld is prime\n", n);
	}
	else
	{ /* Print the factorization */
		printf("%lld=%lld*%lld\n", n, n / least_factor, least_factor);
	}
}

/**
 * readfile_numbers- Reads numbers from a file and factorizes them.
 *
 * @filename: The name of the file containing the numbers.
 * @Return: 0 if the file was read successfully, 1 if there was an error.
 */
int readfile_numbers(const char *filename)
{
	FILE *file = fopen(filename, "r");
	long long n;

	if (file == NULL)
	{
		printf("Error opening file.\n");
		return (1);
	}

	while (fscanf(file, "%lld", &n) == 1)
	{
		factorize_number(n);
	}

	fclose(file);
	return (0);
}

/**
 * main- Entry point of the program.
 * Reads a file containing numbers.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 if the program executed successfully, 1 otherwise.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./factors <file>\n");
		return (1);
	}

	const char *filename = argv[1];
	int result = readfile_numbers(filename);

	return (result);
}
