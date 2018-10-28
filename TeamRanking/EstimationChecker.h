#pragma once
class EstimationChecker
{
public:
	EstimationChecker();
	~EstimationChecker();
	float computeAccuracy(Census& census);
};

