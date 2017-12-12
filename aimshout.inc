#if defined _aimshout_included
	#endinput
#endif
#define _aimshout_included

#include <YSI\y_hooks>
#include <tick-difference>
#include <modio>

#define MAX_AIMSHOUT_TEXT (128)

static
	aimshout_Text[MAX_PLAYERS][MAX_AIMSHOUT_TEXT],
	aimshout_Tick[MAX_PLAYERS];

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if(IsPlayerInAnyVehicle(playerid)) {
		if( (newkeys & 320) && (newkeys & 1) ) {
			if(GetTickCountDifference(GetTickCount(), aimshout_Tick[playerid]) > 750) {
				new string[128];

				strcat(string, aimshout_Text[playerid], 128);
				PlayerSendChat(playerid, string, 0.0);

				aimshout_Tick[playerid] = GetTickCount();
			}
		}
	} else {
		if( (newkeys & 128) && (newkeys & 512) ) {
			if(GetTickCountDifference(GetTickCount(), aimshout_Tick[playerid]) > 750) {
				new string[128];

				strcat(string, aimshout_Text[playerid], 128);
				PlayerSendChat(playerid, string, 0.0);

				aimshout_Tick[playerid] = GetTickCount();
			}
		}
	}

	return 1;
}

stock GetPlayerAimShoutText(playerid, string[]) {
	if(!IsValidPlayerID(playerid))
		return 0;

	string[0] = EOS;
	strcat(string, aimshout_Text[playerid], 128);

	return 1;
}

stock SetPlayerAimShoutText(playerid, string[]) {
	if(!IsPlayerConnected(playerid))
		return 0;

	aimshout_Text[playerid][0] = EOS;
	strcat(aimshout_Text[playerid], string, 128);

	return 1;
}

hook OnPlayerSave(playerid, filename[]) {
	modio_push(filename, _T<S,H,O,U>, strlen(aimshout_Text[playerid]), aimshout_Text[playerid]);
}

hook OnPlayerLoad(playerid, filename[]) {
	modio_read(filename, _T<S,H,O,U>, 128, aimshout_Text[playerid]);
}
