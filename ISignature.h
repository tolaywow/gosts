#pragma once
#include"ifndefwin32.h"

template<class T>
class ISignature
{
public:
	virtual void form_signature(T message, T result_signature, T key) = 0;
	virtual bool verification_signature(T message, T input_signature, T key) = 0;
};

