LittlerootTown_DavidsLab_MapScripts::
	.byte 0


DavidsLab_EventScript_Presentation::
	lockall
	msgbox DavidsLab_EventScript_Presentation_Text_0
	msgbox DavidsLab_EventScript_Presentation_Text_1
	releaseall
	return


DavidsLab_EventScript_Pokeball::
	lockall
	showmonpic SPECIES_MARSHADOW, 10, 3
	msgbox DavidsLab_EventScript_Pokeball_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DavidsLab_EventScript_Pokeball_2
	hidemonpic
	msgbox DavidsLab_NotChosen
DavidsLab_EventScript_Pokeball_1:
	waitmessage
	releaseall
	end

DavidsLab_EventScript_Pokeball_2:
	givemon SPECIES_MARSHADOW, 50, ITEM_MASTER_BALL
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq DavidsLab_EventScript_Pokeball_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq DavidsLab_EventScript_Pokeball_6
	hidemonpic
	msgbox DavidsLab_EventScript_Pokeball_Text_3
	goto DavidsLab_EventScript_Pokeball_1

DavidsLab_EventScript_Pokeball_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox DavidsLab_EventScript_Pokeball_Text_1
	removeobject 2
	setflag FLAG_UNUSED_0x493
	call NicknamePartyMon
	goto DavidsLab_EventScript_Pokeball_1

DavidsLab_EventScript_Pokeball_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox DavidsLab_EventScript_Pokeball_Text_2
	removeobject 2
	setflag FLAG_UNUSED_0x493
	call NicknameBoxMon
	goto DavidsLab_EventScript_Pokeball_1


NicknamePartyMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
	call Common_EventScript_TransferredToPC
	return

NicknameBoxMon_2:
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


DavidsLab_EventScript_Presentation_Text_0:
	.string "Olá, é um prazer em conhece-lo, eu sou\n"
	.string "David o criador dessa hackrom, eu ainda\l"
	.string "estou aprendendo a fazer as coisas\l"
	.string "entao nao se incomode com a bagunça.\l"
	.string "Eu deixei um presente para voce,\l"
	.string "escolha um dos pokémons ao lado$"

DavidsLab_EventScript_Presentation_Text_1:
	.string "Alem disso, eu acho que eu deveria criar\n"
	.string "alguma coisa nao?$"

DavidsLab_EventScript_Pokeball_Text_0:
	.string "Do you want to choose Marshadow?$"

DavidsLab_EventScript_Pokeball_Text_1:
	.string "Recieved Marshadow!$"

DavidsLab_EventScript_Pokeball_Text_2:
	.string "Recieved Marshadow$"

DavidsLab_EventScript_Pokeball_Text_3:
	.string "No More Room$"

NicknamePartyMon_Text_0:
	.string "Give it a nickname?$"

DavidsLab_NotChosen::
	.string "You did not choose the Pokemon$"
