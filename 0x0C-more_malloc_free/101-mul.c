#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * is_digit - verifie que la chaine est un nombre
 * @s: chaine à tester
 *
 * Return: 0 si c'est pas un digit sinon 1
 */
int is_digit(char *s)
{
	int i = 0;

	for (; s[i]; i++)
		if (s[i] < '0' || s[i] > '9')
			return (0);
	return (1);
}

/**
 * _strlen - retourne la longueur de la chaine
 * @s: chaine à tester
 *
 * Return: la longeur de la chaine
 */
int _strlen(char *s)
{
	int i = 0;

	for (; s[i] != '\0'; i++)
	;
	return (i);
}

/**
 * errors - gestion d'erreur du main
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiplies deux nombre positif
 * @argc: argument = nombre
 * @argv: tableau d' arguments
 *
 * Return: toujour 0 en cas de succés
 */
int main(int argc, char *argv[])
{
	char *string1, *string2;
	int len_digit1, len_digit2, len_digit, i, calculate, digit1, digit2, *result, a = 0;

	string1 = argv[1], string2 = argv[2];
	if (argc != 3 || !is_digit(string1) || !is_digit(string2))
		errors();

	len_digit1 = _strlen(string1), len_digit2 = _strlen(string2);
	len_digit = len_digit1 + len_digit2 + 1;
	result = malloc(sizeof(int) * len_digit);
	if (!result)
		return (1);
	for (i = 0; i <= len_digit1 + len_digit2; i++)
		result[i] = 0;
	/* calcul result*/
	for (len_digit1 -= 1; len_digit1 >= 0; len_digit1--)
	{
		digit1 = string1[len_digit1] - '0';
		calculate = 0;
		for (len_digit2 = _strlen(string2) - 1; len_digit2 >= 0; len_digit2--)
		{
			digit2 = string2[len_digit2] - '0';
			calculate += result[len_digit1 + len_digit2 + 1] + (digit1 * digit2);
			result[len_digit1 + len_digit2 + 1] = calculate % 10;
			calculate /= 10;
		}
		if (calculate > 0)
			result[len_digit1 + len_digit2 + 1] += calculate;
	}
	/* print result */
	for (i = 0; i < len_digit - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
