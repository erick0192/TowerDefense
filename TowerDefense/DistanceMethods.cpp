#include "stdafx.h"
#include "DistanceMethods.h"
//	</added pragmas>
#include <cmath>
//	</added pragmas>
DistanceMethods::DistanceMethods(void)
{
}


DistanceMethods::~DistanceMethods(void)
{
}


double DistanceMethods::distance(CPoint a, CPoint b)
{
	
	return sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));
}


bool DistanceMethods::withinRange(CPoint a, CPoint b, int range)
{
	return (distance(a,b) <= (double)range);
}