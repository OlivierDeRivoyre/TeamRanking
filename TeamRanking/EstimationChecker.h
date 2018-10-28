#pragma once
class EstimationChecker
{
public:
	EstimationChecker();
	~EstimationChecker();
	float computePronostic(Census& census);
};

