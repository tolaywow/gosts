#include "GrassHopper.h"
#include"constsInerProj.h"

#define puint64 *(unsigned __int64*)

GrassHopper::GrassHopper(unsigned __int8* key)
{
	key_reNew(key);
}

void GrassHopper::generation_of_keys()
{
	puint64(keys + 0x10) = puint64(key);
	puint64(keys + 0x18) = puint64(key + 0x8);
	puint64(keys) = puint64(key+0x10);
	puint64(keys + 0x8) = puint64(key+0x18);
	

	for (unsigned __int8 k = 0; k < 0x04; ++k)
	{
		puint64(keys+0x20*(k+0x1)) = puint64(keys+0x20 * k);
		puint64(keys + 0x8 + 0x20 * (k + 0x1)) = puint64(keys + 0x8 + 0x20 * k);
		puint64(keys + 0x10 + 0x20 * (k + 0x1)) = puint64(keys + 0x10 + 0x20 * k);
		puint64(keys + 0x18 + 0x20 * (k + 0x1)) = puint64(keys + 0x18 + 0x20 * k);

		for (unsigned __int8 j = 0; j < 0x8; ++j)
		{
			unsigned __int64 varmas[2];
			varmas[0] = puint64(keys + 0x20 * (k + 0x1));
			varmas[1] = puint64(keys + 0x20 * (k + 0x1)+0x8);

			X(const_cast<unsigned __int8*>(IPconst::C) + 0x10 * j + 0x80 * k, keys + 0x20 * (k + 0x1));
			S(keys + 0x20 * (k + 0x01));
			L(keys + 0x20 * (k + 0x01));
			X(keys + 0x20 * (k + 0x1) + 0x10, keys + 0x20 * (k + 0x1));

			puint64(keys + 0x20 * (k + 0x01) + 0x10) = varmas[0];
			puint64(keys + 0x20 * (k + 0x01) + 0x18) = varmas[1];
		}
	}
}

void GrassHopper::key_reNew(unsigned __int8* key)
{
	this->key = key;
	if(this->key!=0)
		generation_of_keys();
}

unsigned __int8 GrassHopper::l(unsigned __int8* block)
{
	unsigned __int32 var = 0;

	for (int k = 0; k < 0x10; ++k)
		for (int j = 0; j < 0x8; ++j)
			if ((IPconst::l[k] ^ 1 << j) < IPconst::l[k])
				var ^= (block[k] << j);

	for (int k = 0x7; k > 0; --k)
		if ((var ^ (1 << (k + 0x7))) < var)
			var ^= (0x1c3 << (k - 1));

	return static_cast<unsigned __int8>(var);
}

void GrassHopper::S(unsigned __int8* block)
{
	for (unsigned __int8 k = 0; k < 0x10; ++k)
		block[k] = IPconst::pi[block[k]];
}

void GrassHopper::notS(unsigned __int8* block)
{
	for (unsigned __int8 k = 0; k < 0x10; ++k)
		block[k] = IPconst::pish[block[k]];
}

void GrassHopper::L(unsigned __int8* block)
{
	for (unsigned __int8 k = 0; k < 0x10; ++k)
	{		
		unsigned __int8 var = l(block);

		puint64(block)>>=0x8;
		block[0x7] = block[0x8];
		puint64(block + 0x8) >>= 0x8;
		block[0xf] = var;
	}
}

void GrassHopper::notL(unsigned __int8* block)
{
	for (unsigned __int8 k = 0; k < 0x10; ++k)
	{
		unsigned __int8 var = block[0xf];

		puint64(block+0x8) <<= 8;
		block[0x8] = block[0x7];
		puint64(block) <<= 0x8;
		*block= var;
		*block = l(block);
	}
}

void GrassHopper::X(unsigned __int8* key, unsigned __int8* block)//XOR int128
{
	puint64(block) ^= puint64(key);
	puint64(block + 0x8) ^= puint64(key + 0x8);
}

void GrassHopper::Encrypt(unsigned __int8* block)
{
	if (key != 0)
	{
		for (unsigned __int8 k = 0; k < 0x9; ++k)
		{
			X(keys + 0x10 * k, block);
			S(block);
			L(block);
		}

		X(keys + 0x90, block);
	}
}

void GrassHopper::Decrypt(unsigned __int8* block)
{
	if (key != 0)
	{
		for (unsigned __int8 k = 0x9; k > 0; --k)
		{
			X(keys + 0x10 * k, block);
			notL(block);
			notS(block);
		}

		X(keys, block);
	}
}

GrassHopper::~GrassHopper() 
{
	//key = 0;
}