#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//declarations
void TownFunc();
bool Hook(void* addr, void* func, int len = 5);
//expressions
int packet_retn = 0x4784DB;
int case_0x050A = 0x478F8D;
int effect_retn = 0x473170;
int effect_jump = 0x47469F;
int effect_fail = 0x47468A;
int type_retn = 0x49DDC8;
int type_jump = 0x49DEB5;
//ps_game functions
int ItemUseNSend = 0x4728E0;
int SConnectionSend = 0x4ED0E0;
int PSendViewCombat = 0x4D56D0;
