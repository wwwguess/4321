#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "æäµÀ" NOR);
	set("long", @LONG
Ò»ÌõæäµÀ¾²¾²µÄÏòÔ¶·½ÑÓÉì£¬ºÃÏóÓÀÔ¶Ã»ÓĞ¾¡Í·¡£
Íù¶«ÄÏ¾ÍÊÇÍ¨ÍùÉ½¶«¼ÃÄÏ¸ µÄ¶É¿ÚÁË¡£®
LONG
	);
	set("exits", ([ 
  "northwest"  : __DIR__"cangzhou",
  "southeast" : __DIR__"rdktojd1",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

int is_road() {
	return(1);
}

