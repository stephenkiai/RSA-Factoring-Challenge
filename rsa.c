#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * is_prime- Checks if a number is prime.
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
 * factorize_number- Factorizes a number into prime factors.
 *
 * @n: The number to factorize.
 */
void factorize_number(long long n)
{
	long long p = -1;
	long long q = -1;

	for (long long i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (is_prime(i) && is_prime(n / i))
			{
				p = i;
				q = n / i;
				break;
			}
		}
	}

	if (p != -1 && q != -1)
	{ /* Print the factorization */
		printf("%lld=%lld*%lld\n", n, q, p);
	}
	else
	{
		printf("%lld is not factorizable into prime numbers.\n", n);
	}
}

/**
 * readfile_number- Reads a number from a file and factorizes it.
 *
 * @filename: The name of the file containing the number.
 */
void readfile_number(const char *filename)
{
	FILE *file = fopen(filename, "r");
	long long n;

	if (file == NULL)
	{
		printf("Error opening file.\n");
		return;
	}

	if (fscanf(file, "%lld", &n) == 1)
	{
		factorize_number(n);
	}
	else
	{
		printf("Invalid number in the file.\n");
	}

	fclose(file);
}

/**
 * main- Entry point of the program.
 * Reads a file containing a number and factorizes it.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 if the program executed successfully, 1 otherwise.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./factorize <file>\n");
		return (1);
	}

	const char *filename = argv[1];

	readfile_number(filename);

	return (0);
}
