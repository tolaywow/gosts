#include "Stribog.h"
#include "constsInerProj.h"

#define puint64 *(unsigned __int64*)


void Stribog::form_signature(unsigned __int8* message,unsigned __int8* signature, unsigned __int8* key)
{
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

Stribog::Stribog(unsigned __int16* size = 0)
{
	if (*size == 0x100)
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

