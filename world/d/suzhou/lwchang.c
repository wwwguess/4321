// Room: /d/suzhou/lwchang.c
// by dwolf
//97.11.4 
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"练武场"NOR);
	set("long", @LONG
这是镖局弟子练武的地方，几个镖局弟子正在练武，一个镖头在一旁指点。弟子的喊
声震天。对于你的到来，他们熟视无睹。你不由对他们的劲头感动了。
LONG
	);

	set("exits", ([
		"south" : __DIR__"biaoju",
		"north" : __DIR__"bjdting",
	]));

	set("objects", ([
		__DIR__"npc/fighter2" : 2,
		__DIR__"npc/biaotou" : 1,
	]));

	setup();
	replace_program(ROOM);
}

