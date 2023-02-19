#pragma once
#include "Sorter.h"

class GnomeSorter : public Sorter
{
public:
	GnomeSorter();
	~GnomeSorter() override;
	virtual void sort();
};
