#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//declarations
void TownFunc();
BOOL Hook(void * pAddr, void * pNAddr, int len);
//expressions
DWORD packet_retn = 0x4784DB;
DWORD case_0x050A = 0x478F8D;
DWORD effect_retn = 0x47316A;
DWORD effect_jump = 0x47469F;
DWORD effect_fail = 0x47468A;
DWORD cancel_retn = 0x49AE66;
DWORD cancel_fail = 0x49AEBA;
//ps_game functions
DWORD ItemUseNSend = 0x4728E0;
DWORD SConnectionSend = 0x4ED0E0;
DWORD PSendViewCombat = 0x4D56D0;
//packet buffer
unsigned char tele_packet[8];
