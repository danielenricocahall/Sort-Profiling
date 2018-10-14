#pragma once
#include "Sorter.h"

class GnomeSorter : public Sorter
{
public:
	GnomeSorter();
	virtual ~GnomeSorter();
	virtual void sort();
};
