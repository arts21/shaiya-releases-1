#pragma once

#define WIN32_LEAN_AND_MEAN 
#include <windows.h>
//declarations
void CMDFunc();
bool Hook(void* addr, void* func, int len);
//expressions
int cmd_input = 0x632D07;
int cmd_retn = 0x4867A6;
int cmd_jump = 0x487532;
int sysmsg_uni = 0x423150;
const char* close_str = "/close";
const char* market_str = "/merchant";
const char* keeper_str = "/warehouse";
const char* repair_str = "/blacksmith";
const char* reroll_str = "/recreation";
unsigned char npc_jmp[] = { 0xEB, 0x05 };
unsigned char max_sell[] = { 0x90, 0x90 };
unsigned char help_menu[] = { 0xE8, 0x0B, 0x9F, 0xFF, 0xFF };
