#pragma once
#include "Icrypto.h"

template<class T>
class IGamming :public Icrypto<T>
{
public:
	virtual void gamming(T blocks, T init_val) = 0;
protected:
	virtual void Ts() = 0;
	virtual void X(T init_val_after_Ts, T block) = 0;
	virtual void add_IV(T init_val) = 0;

};


