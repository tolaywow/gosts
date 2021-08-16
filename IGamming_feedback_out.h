#pragma once
#include"Icrypto.h"

template<class T>
class IGamming_feedback_out :public Icrypto<T>
{
public:
	virtual void gfo(T init_val, T blocks) = 0;
protected:
	virtual void R_IV() = 0;
	virtual void split_IV() = 0;
	virtual void Ts() = 0;
	virtual void X(T init_val_after_Ts, T block) = 0;
};

