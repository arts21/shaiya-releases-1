#include "pch.h"

/*
memory addresses
0090D1D4 - gm status
11 = status 0
5 = status 80
4 = status 64
3 = status 48
2 = status 32
1 = status 16
009144E4 - window id
0091AD40 - npc type id
0091AD44 - npc type
009144F0 - npc icon
022AB7B8 - npc name
*/

//hooks user commands
__declspec(naked) void cmd_hook()
{
	_asm
	{
		push 0x6 //command length
		push szClose //command string
		push edi
		call cmd_input
		add esp,0xC
		test eax,eax
		jne _market
		//gives them the option to close window
		mov dword ptr ds:[0x9144E4],0x0 //close
		jmp cmd_jump
		
		_market:
		push 0x9
		push szMarket
		push edi
		call cmd_input
		add esp,0xC
		test eax,eax
		jne _keeper
		//fails if a window is already open
		cmp dword ptr ds:[0x9144E4],0x0
		jne _fail
		//uses a market npc without items
		mov dword ptr ds:[0x91AD44],0x1 //type
		mov dword ptr ds:[0x91AD40],0x12C //type id
		mov dword ptr ds:[0x9144F0],-0x1 //icon
		mov dword ptr ds:[0x22AB7B8],0x0 //name
		mov dword ptr ds:[0x9144E4],0x65 //market
		jmp cmd_jump
		
		_keeper:
		push 0xA
		push szKeeper
		push edi
		call cmd_input
		add esp,0xC
		test eax,eax
		jne _repair
		cmp dword ptr ds:[0x9144E4],0x0
		jne _fail
		mov dword ptr ds:[0x91AD44],0x6 //type	
		mov dword ptr ds:[0x91AD40],0x1D //type id
		mov dword ptr ds:[0x9144F0],-0x1 //icon
		mov dword ptr ds:[0x22AB7B8],0x0 //name
		mov dword ptr ds:[0x9144E4],0x67 //warehouse
		jmp cmd_jump
			
		_repair:
		push 0xB
		push szRepair
		push edi
		call cmd_input
		add esp,0xC
		test eax,eax
		jne _reroll
		cmp dword ptr ds:[0x9144E4],0x0
		jne _fail
		mov dword ptr ds:[0x91AD44],0x3 //type
		mov dword ptr ds:[0x91AD40],0x28 //type id
		mov dword ptr ds:[0x9144F0],-0x1 //icon
		mov dword ptr ds:[0x22AB7B8],0x0 //name
		mov dword ptr ds:[0x9144E4],0x66 //blacksmith
		jmp cmd_jump

		_reroll:
		push 0xB
		push szReroll
		push edi
		call cmd_input
		add esp,0xC
		test eax,eax
		jne _original
		cmp dword ptr ds:[0x9144E4],0x0
		jne _fail
		mov dword ptr ds:[0x91AD44],0x1 //type
		mov dword ptr ds:[0x91AD40],0xF8 //type id
		mov dword ptr ds:[0x9144F0],-0x1 //icon
		mov dword ptr ds:[0x22AB7B8],0x0 //name
		mov dword ptr ds:[0x9144E4],0x79 //recreation
		jmp cmd_jump
		//original code
		_original:
		push 0x13D4
		jmp cmd_retn

		_fail:
		push 0xC
		push 0x326 //sysmsg-uni.txt line
		push 0x1F //message color or type
		call sysmsg_uni //send the notice
		add esp,0xC
		jmp cmd_jump
	}
}

//main function
void CMDFunc() {
	Hook((void*)0x4867A1, cmd_hook, 5);
	//overwrites CustomGame.dll help menu npcs
	memcpy((void*)0x522160, (void*)help_menu, sizeof(help_menu));
	//maxes the item count when selling to an npc
	memcpy((void*)0x42E131, max_sell, sizeof(max_sell));
	//ignores an npc function result (bug workaround)
	memcpy((void*)0x444129, npc_jmp, sizeof(npc_jmp));
}
