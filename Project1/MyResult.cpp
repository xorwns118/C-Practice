#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "MyArray.h"

int mainTest()
{
	tMyArr arr = { };
	InitMyArr(&arr);

	/*for (int i = 0; i < 10; i++)
	{
		PushMyArr(&arr, i);
	}*/

	for (int i = 10; i >= 0; i--)
	{
		PushMyArr(&arr, i);
	}

	BubbleSort(&arr);

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr.pInt[i]);
	}

	ReleaseMemory(&arr);

	return 0;
}