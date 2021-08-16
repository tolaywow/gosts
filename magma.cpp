#include "magma.h"

Magma::Magma(unsigned __int32* new_keys, unsigned __int8* substitutions)
{
	init(new_keys, substitutions);
}

void Magma::init(unsigned __int32* new_keys, unsigned __int8* substitutions)
{
	static unsigned __int8 default_substitutions[] =
	{
		12, 4, 6, 2, 10, 5, 11, 9, 14, 8, 13, 7, 0, 3, 15, 1,
		6, 8, 2, 3, 9, 10, 5, 12, 1, 14, 4, 7, 11, 13, 0, 15,
		11, 3, 5, 8, 2, 15, 10, 13, 14, 1, 7, 4, 12, 9, 6, 0,
		12, 8, 2, 1, 13, 4, 15, 6, 7, 0, 10, 5, 3, 14, 9, 11,
		7, 15, 5, 10, 8, 1, 6, 13, 0, 9, 3, 14, 11, 4, 2, 12,
		5, 13, 15, 6, 9, 2, 12, 10, 11, 7, 8, 1, 4, 3, 14, 0,
		8, 14, 2, 5, 6, 9, 1, 12, 15, 4, 11, 0, 13, 10, 3, 7,
		1, 7, 14, 13, 0, 5, 8, 3, 4, 15, 10, 6, 9, 12, 11, 2
	};

	static  unsigned __int32 default_keys[] =
	{
		0xffeeddcc,
		0xbbaa9988,
		0x77665544,
		0x33221100,
		0xf0f1f2f3,
		0xf4f5f6f7,
		0xf8f9fafb,
		0xfcfdfeff
	};

	//condition?true:false
	substitutions == 0 ?  subst = static_cast<unsigned __int8*>(default_substitutions): subst = substitutions;
	new_keys == 0 ? keys = static_cast<unsigned __int32*>(default_keys) : keys = new_keys;
}

void Magma::substitutions_reNew(unsigned __int8* substitutions)
{
	subst = substitutions;
}

void Magma::keys_reNew(unsigned __int32* new_keys)
{
	keys = new_keys;
}

void Magma::t(unsigned __int32* block)
{
	for (unsigned __int8 k = 0; k < 0x8; ++k)
	{
		*block = *block & ~(0xf << 0x4 * k) ^ subst[((*block >> (0x4 * k)) & 0xf) + 0x10 * k] << 0x4 * k;
	}
}

void Magma::g(unsigned __int32* block, unsigned __int32* key)
{
	*block += *key;
	t(block);
	*block = *block << 0xb | *block >> 0x15;
}

void Magma::G(unsigned __int32* blocks, unsigned __int32* key)
{
	unsigned __int32 var = *blocks;
	g(blocks, key);
	*blocks ^= *(blocks + 0x1);
	*(blocks + 0x1) = var;
}

void Magma::Gx(unsigned __int64* block, unsigned __int32* key)
{
	G((unsigned __int32*)block, key);
	*block = *block << 0x20 ^ *block >> 0x20;
}

void Magma::Encrypt(unsigned __int64* block)
{
	for (unsigned __int8 k = 0; k < 0x18; ++k)
	{
		G((unsigned __int32*)(block), &keys[k % 0x8]);
	}

	for (unsigned __int8 k = 0x7; k > 0; --k)
	{
		G((unsigned __int32*)(block), &keys[k]);
	}

	Gx(block,keys);
}

void Magma::Decrypt(unsigned __int64* block)
{
	for (unsigned __int8 k = 0; k < 8; ++k) 
	{
		G((unsigned __int32*)(block), &keys[k]);
	}

	for (unsigned __int8 k = 0x17; k > 0; --k)
	{
		G((unsigned __int32*)(block), &keys[k % 0x8]);
	}

	Gx(block, keys);
}