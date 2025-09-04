#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * a/A->4, e/E->3, o/O->0, t/T->7, l/L->1
 * @s: String pointer.
 *
 * Return: Pointer to s.
 */
char *leet(char *s)
{
	int i = 0, j;
	char low[] = "aeotl";
	char up[]  = "AEOTL";
	char num[] = "43071";

	while (s[i] != '\0')          /* loop #1 */
	{
		for (j = 0; j < 5; j++)    /* loop #2 */
		{
			if (s[i] == low[j] || s[i] == up[j]) /* single if */
			{
				s[i] = num[j];
				break;
			}
		}
		i++;
	}
	return (s);
}
