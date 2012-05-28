#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define PROGRAM    "randi"
#define AUTHOR     "V. Silvansky"
#define MAIL       "<v.silvansky@gmail.com>"
#define YEARS      "2012"
#define VERSION    "1.0"

#define MOD        100000000

void printUsage()
{
	printf(
"Usage: %s [lower, upper]\n"
"  [lower] and [upper] are both integer values.\n"
"Prints random integer number between [lower] and [upper]\n"
"If no bounds provided, %s prints a random number in range [0:100).\n"
"Author: %s %s, %s\n"
"Version: %s\n",
		   PROGRAM, PROGRAM, AUTHOR, MAIL, YEARS, VERSION);
}

void seed()
{
	srandomdev();
}

long getValue(long lower, long upper)
{
	return lower + random() % (upper - lower);
}

int main(int argc, char *argv[])
{
	if (argc == 2 || argc > 3)
	{
		printUsage();
		return 0;
	}
	
	long lower, upper, value;
	
	if (argc == 1)
	{
		lower = 0;
		upper = 100;
	}
	else
	{
		if (sscanf(argv[1], "%ld", &lower) + sscanf(argv[2], "%ld", &upper) < 2)
		{
			printUsage();
			return 1;
		}
	}
	
	if (lower == upper)
		value = lower;
	else
	{
		if (lower > upper)
		{
			value = upper; upper = lower; lower = value;
		}
		seed();
		value = getValue(lower, upper);
	}
	
	printf("%ld\n", value);
	
	return 0;
}
