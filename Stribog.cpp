#include "Stribog.h"
#include "constsInerProj.h"

#define puint64 *(unsigned __int64*)

void Stribog::form_signature(unsigned __int8* message,unsigned __int8* signature, unsigned __int8* key)
{
	unsigned __int8 h[0x40];
	//step 1.2:N=0
	unsigned __int8 N[0x40] = { 0 };
	//step 1.3: Esumm=0
	unsigned __int8 Esumm[0x40] = { 0 };

	unsigned __int8 m[0x40];

	//step 1.1: h=IV
	{
		puint64(h) = puint64(IV);
		puint64(h + 0x10) = puint64(IV + 0x10);
		puint64(h + 0x20) = puint64(IV + 0x20);
		puint64(h + 0x30) = puint64(IV + 0x30);
		puint64(h + 0x40) = puint64(IV + 0x40);
		puint64(h + 0x50) = puint64(IV + 0x50);
		puint64(h + 0x60) = puint64(IV + 0x60);
		puint64(h + 0x70) = puint64(IV + 0x70);
	}
	
	//step 2.1:
	// TODO check length of message
	
	//if length >=512 bits
	//step 2.2: cut piece of M, length piece(m) =512 bits
	
	//step 2.3: h=gN(h,m)
	gN(h, m);
	//TODO

}

bool Stribog::verification_signature(unsigned __int8* message, unsigned __int8* signature, unsigned __int8* key)
{
	//TODO
	
	if ("not accept signature")
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

Stribog::Stribog(unsigned __int16* size_bits )
{
	if (*size_bits == 0x100)
	{
		IV = new unsigned __int8[0x100]{ 0 };//0x200
		IV[0] = 0x1;
		IV[0x40] = 0x1;
		IV[0x80] = 0x1;
		IV[0xc0] = 0x1;
		/*IV[0x100] = 0x1;
		IV[0x140] = 0x1;
		IV[0x180] = 0x1;
		IV[0x1c0] = 0x1;*/
	}
	else
	{
		IV = new unsigned __int8[0x200]{ 0 };
	}
}

Stribog::Stribog() 
{
	IV = new unsigned __int8[0x200]{ 0 };
}

Stribog::~Stribog()
{
	delete[] IV;
}

unsigned __int64 Stribog::multiplicate(unsigned __int64* b)
{
	unsigned __int64 summ = 0;

	for (unsigned __int8 k = 0; k < 0x40; ++k)
		if ((*b >> k & 1) == 0x1)
			summ ^= strb_const::A[k];

	return summ;
}

void Stribog::X(unsigned __int8* key, unsigned __int8* block)
{
	puint64(block) ^= puint64(key);
	puint64(block + 0x10) ^= puint64(key + 0x10);
	puint64(block + 0x20) ^= puint64(key + 0x20);
	puint64(block + 0x30) ^= puint64(key + 0x30);
	puint64(block + 0x40) ^= puint64(key + 0x40);
	puint64(block + 0x50) ^= puint64(key + 0x50);
	puint64(block + 0x60) ^= puint64(key + 0x60);
	puint64(block + 0x70) ^= puint64(key + 0x70);
}

void Stribog::S(unsigned __int8* block)
{
	for (unsigned __int8 k = 0; k < 0x40; ++k)
	{
		block[k] = IPconst::pi[block[k]];
	}
}

void Stribog::P(unsigned __int8* block)
{
	unsigned __int8 substitution[0x80];

	puint64(substitution) = puint64(block);
	puint64(substitution + 0x10) = puint64(block + 0x10);
	puint64(substitution + 0x20) = puint64(block + 0x20);
	puint64(substitution + 0x30) = puint64(block + 0x30);
	puint64(substitution + 0x40) = puint64(block + 0x40);
	puint64(substitution + 0x50) = puint64(block + 0x50);
	puint64(substitution + 0x60) = puint64(block + 0x60);
	puint64(substitution + 0x70) = puint64(block + 0x70);
		
	for (unsigned __int8 k = 0; k < 0x8; ++k)
	{
		block[0x8*k] = substitution[k];
		block[0x8 * k + 0x1] = substitution[k + 0x8];
		block[0x8 * k + 0x2] = substitution[k + 0x10];
		block[0x8 * k + 0x3] = substitution[k + 0x18];
		block[0x8 * k + 0x4] = substitution[k + 0x20];
		block[0x8 * k + 0x5] = substitution[k + 0x28];
		block[0x8 * k + 0x6] = substitution[k + 0x30];
		block[0x8 * k + 0x7] = substitution[k + 0x38];
	}
}

void Stribog::gN(unsigned __int8* h, unsigned __int8* m)//length m or h =512 bit or 0x40 byte 
{

	// E(LPS(h ^ N), m) ^ h ^ m, 
}

