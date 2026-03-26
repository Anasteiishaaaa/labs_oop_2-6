#pragma once
#include <iostream>
using namespace std;

class IPrintable {
public: 
	virtual ~IPrintable() = default;
	virtual void printSummary() const = 0;
};