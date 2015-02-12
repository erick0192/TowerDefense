#pragma once
class DistanceMethods
{
public:
	DistanceMethods(void);
	~DistanceMethods(void);
public:
	static double distance(CPoint a, CPoint b);
	static bool withinRange(CPoint a, CPoint b, int range);
};

