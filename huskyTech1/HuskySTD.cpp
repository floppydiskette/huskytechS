#include "HuskySTD.h"

bool HuskySTD::copyArrayINT(int* array1[], int* array2[])
{
	if (sizeof(array1) != sizeof(array2)) {
		//arrays are of different size, not very pogchamp ):<
		return false;
	}
	else {
		for (int i = 0; i < sizeof(array1); i++) {
			array2[i] = array1[i];
		}
		return true;
	}
}
