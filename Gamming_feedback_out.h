#pragma once
#include"Icrypto.h"

template<class T>
class Gamming_feedback_out:public Icrypto<T>
{
	virtual void gfo(T init_val,T blocks) = 0;
	virtual void R_IV() = 0;
	virtual void split_IV()=0;
	virtual void Ts()=0;
};

