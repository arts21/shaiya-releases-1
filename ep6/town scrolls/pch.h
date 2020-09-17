#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//declarations
void TownFunc();
bool Hook(void* addr, void* func, int len);
//expressions
int packet_retn = 0x4784DB;
int case_0x050A = 0x478F8D;
int effect_retn = 0x473170;
int effect_jump = 0x47469F;
int effect_fail = 0x47468A;
int cancel_retn = 0x49AE66;
int cancel_fail = 0x49AEBA;
//ps_game functions
int ItemUseNSend = 0x4728E0;
int SConnectionSend = 0x4ED0E0;
int PSendViewCombat = 0x4D56D0;
//packet buffer
unsigned char tele_packet[8];
