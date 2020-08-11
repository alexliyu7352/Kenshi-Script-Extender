#pragma once
#include "game_structs.h"

DWORD64 RAX;
DWORD64 *RAXP = &RAX;

DWORD64 RBX;
DWORD64 *RBXP = &RBX;

DWORD64 RCX;
DWORD64 *RCXP = &RCX;

DWORD64 RDX;
DWORD64 *RDXP = &RDX;

DWORD64 RSI;
DWORD64 *RSIP = &RSI;

DWORD64 RDI;
DWORD64 *RDIP = &RDI;

DWORD64 RBP;
DWORD64 *RBPP = &RBP;

DWORD64 RSP;
DWORD64 *RSPP = &RSP;

DWORD64 R8;
DWORD64 *R8P = &R8;

DWORD64 R9;
DWORD64 *R9P = &R9;

DWORD64 R10;
DWORD64 *R10P = &R10;

DWORD64 R11;
DWORD64 *R11P = &R11;

DWORD64 R12;
DWORD64 *R12P = &R12;

DWORD64 R13;
DWORD64 *R13P = &R13;

char XMM0[32];
char *XMM0P = &XMM0[0];

char XMM1[32];
char *XMM1P = &XMM1[0];

char XMM2[32];
char *XMM2P = &XMM2[0];

char XMM3[32];
char *XMM3P = &XMM3[0];

char XMM4[32];
char *XMM4P = &XMM4[0];

char XMM5[32];
char *XMM5P = &XMM5[0];

char XMM6[32];
char *XMM6P = &XMM6[0];

char XMM7[32];
char *XMM7P = &XMM7[0];

char XMM8[32];
char *XMM8P = &XMM8[0];

char XMM9[32];
char *XMM9P = &XMM9[0];

char XMM10[32];
char *XMM10P = &XMM10[0];

char XMM11[32];
char *XMM11P = &XMM11[0];

char XMM12[32];
char *XMM12P = &XMM12[0];

char XMM13[32];
char *XMM13P = &XMM13[0];

char XMM14[32];
char *XMM14P = &XMM14[0];

char XMM15[32];
char *XMM15P = &XMM15[0];

void sellHookThread()
{
	int *moneyPointer = (int *)(RCX + 0x00000088);
	int money = *moneyPointer;
	int itemPrice = RDX;

	if (itemPrice <= money) {
		*moneyPointer = money - itemPrice;
		RAX = 1;
	}
	else 
	{
		RAX = 0;
	}

	std::cout << "Cat count start: " << money << std::endl;
	std::cout << "Item price: " << itemPrice << std::endl;
	std::cout << "Cat count end: " << *moneyPointer << std::endl;
}

void damageHookThread()
{
	DWORD64 *RSPPointer1 = (DWORD64*)(RSP + 0x08);
	DWORD64 *RSPPointer2 = (DWORD64*)(RSP + 0x10);
	DWORD64 *RSPPointer3 = (DWORD64*)(RSP + 0x18);

	memcpy(RSPPointer1, &RBX, sizeof(DWORD64));
	memcpy(RSPPointer2, &RBP, sizeof(DWORD64));
	memcpy(RSPPointer3, &RSI, sizeof(DWORD64));

	DWORD64 bloodPointer = RCX;
	DWORD64 victimLimbPointer = RDX;
	DWORD64 damageStructPointer = R8;

	damageStruct damageDone;
	damageDone.createFromAddress(damageStructPointer);

	Limb attackedLimb;
	attackedLimb.createFromAddress(victimLimbPointer);

	DWORD64 attackerAddress = damageDone.getAttackerCharacterAddress();
	DWORD64 victimAddress = attackedLimb.getCharacterAddress();

	if (attackerAddress)
	{
		Character victim;
		Character attacker;

		victim.createFromAddress(victimAddress);
		attacker.createFromAddress(attackerAddress);

		std::string victimName(victim.name);
		std::string attackerName(attacker.name);

		//God mode for Da-dek
		if (victimName == "Da-Dek") {
			std::cout << "Godmode active for Da-Dek" << std::endl;
			*damageDone.cutDamage = 0;
			*damageDone.bluntDamage = 0;
			*damageDone.bleedDamage = 0;
			*damageDone.bonusDamage = 0;
		}

		std::cout << victimName << " : " << victimAddress << " was hit by " << attackerName << " : " << attackerAddress << std::endl;
		std::cout << "Cut damage: " << *damageDone.cutDamage << std::endl;
		std::cout << "Blunt damage: " << *damageDone.bluntDamage << std::endl;
		std::cout << "Bonus damage: " << *damageDone.bonusDamage << std::endl;
		std::cout << "Bleed damage: " << *damageDone.bleedDamage << std::endl;
		std::cout << std::endl;
	}
}