#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * is_prime- Checks if a number is prime.
 *
 * @n: The number to check.
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime(long long n)
{
	if (n <= 1)
	{
		return (0);
	}
	for (long long i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return (0);
		}
	}
	return (1);
}

/**
 * factorize_number- Factorizes a number into pairs of smaller numbers.
 *
 * @n: The number to factorize.
 */
void factorize_number(long long n)
{
	long long i;
	long long least_factor = n; /* Initialize the least factor to n */

	for (i = 2; i <= (long long)sqrt(n); i++)
	{
		if (n % i == 0)
		{
			least_factor = i; /* Update the least factor */
			break; /* Exit loop after the least factor is found */
		}
	}
	if (least_factor == i)
	{                         /* Print the factorization */
		printf("%lld=%lld*%lld\n", n, n / least_factor, least_factor);
	}
	else
	{
		printf("%lld is prime\n", n); /* Print the number is prime */
	}
}

/**
 * readfile_numbers- Reads numbers from a file and factorizes them.
 *
 * @filename: The name of the file containing the numbers.
 */
void readfile_numbers(const char *filename)
{
	FILE *file = fopen(filename, "r");
	long long n;

	if (file == NULL)
	{
		printf("Error opening file.\n");
		return;
	}

	while (fscanf(file, "%lld", &n) == 1)
	{
		factorize_number(n);
	}

	fclose(file);
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

	readfile_numbers(filename);

	return (0);
}
