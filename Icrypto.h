#pragma once
#include"ifndefwin32.h"

template<class T>
class Icrypto
{
public:
	virtual void Encrypt(T) = 0;
	virtual void Decrypt(T) = 0;
	//virtual ~Icrypto() {};
};

