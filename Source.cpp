#include "magma.h"
#include "GrassHopper.h"
#include "Gamming.h"
#include<iostream>

template<class T>
void Out(Icrypto<T>* x, T z)
{

	x->Encrypt(z);
	std::cout <<*z<<std::endl;
}


int main()
{
	unsigned __int64 z = 0xfedcba9876543210;
	Magma x;
	x.Encrypt(&z);
	x.Decrypt(&z);
	Out(&x, &z);

	unsigned __int8 key[] =
	{
		0xef, 0xcd, 0xab, 0x89,
		0x67, 0x45, 0x23, 0x01,
		0x10, 0x32, 0x54, 0x76,
		0x98, 0xba, 0xdc, 0xfe,
		0x77, 0x66, 0x55, 0x44,
		0x33, 0x22, 0x11, 0x00,
		0xff, 0xee, 0xdd, 0xcc,
		0xbb, 0xaa, 0x99, 0x88
	};


	GrassHopper y(key);


	unsigned __int8 a[] =
	{
		0x88, 0x99, 0xaa, 0xbb, 
		0xcc, 0xdd, 0xee, 0xff,
		0x00, 0x77, 0x66, 0x55,
		0x44, 0x33, 0x22, 0x11,
	};

	y.Encrypt(a);	
	y.Decrypt(a);

	Out(&y, a);

	return 0;
}