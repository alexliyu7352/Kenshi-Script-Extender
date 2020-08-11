#pragma once

struct Squad 
{
	std::string name;
};

struct Faction
{
	char *name;
};

struct Limb
{
	DWORD64 address;

	bool *gender;
	float *hp;

	DWORD64 getCharacterAddress() 
	{
		DWORD64 characterAddress = *(DWORD64*)(address + 0x18);
		return characterAddress;
	}

	void createFromAddress(DWORD64 limbAddress) 
	{
		address = limbAddress;
	}
};

struct LimbStruct 
{
	Limb limb1;
	Limb limb2;
	Limb limb3;
	Limb limb4;
	Limb limb5;
	Limb limb6;
	Limb limb7;
};

struct damageStruct
{
	DWORD64 address;

	float *cutDamage;
	float *bluntDamage;
	float *bonusDamage;

	float *bleedDamage;

	bool isValid() 
	{
		DWORD64 characterPointerValid = *(DWORD64*)(address + 0x38);

		if (characterPointerValid != 0xf)
		{
			return true;
		}
		return false;
	}

	DWORD64 getAttackerCharacterAddress()
	{
		if (isValid()) 
		{
			DWORD64 *characterPointerValid = (DWORD64*)(address + 0x38);
			DWORD64 attackerAddress = *(DWORD64*)(*characterPointerValid + 0x8);

			return attackerAddress;
		}
		return 0;
	}

	void createFromAddress(DWORD64 damageAddress)
	{
		address = damageAddress;

		cutDamage = (float*)(damageAddress);
		bluntDamage = (float*)(damageAddress + 0x4);
		bonusDamage = (float*)(damageAddress + 0x8);

		bleedDamage = (float *)(damageAddress + 0x10);
	}
};

struct Character
{
	DWORD64 address;

	char *name;
	Faction faction;
	Squad squad;

	LimbStruct limbStruct;

	void createFromAddress(DWORD64 characterAddress) 
	{
		DWORD64 *characterName = (DWORD64*)(characterAddress + 0x18);
		bool isNamePointer = (*(char*)(characterAddress + 0x30) != 0xF) ? true : false;

		name = (char*)characterName;

		if (isNamePointer) {
			name = (char*)(*characterName);
		}
	}
};