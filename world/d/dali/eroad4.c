#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "ÅÌÉ½Ğ¡Â·" NOR);
	set("long", @LONG
ÖÜÎ§¶¼ÊÇ¹ÖÊ¯Á×Á×µÄÊ¯Í·É½£¬Å¼¶ûÔ¶·½´«À´Ò»Á½ÉùÃ¨Í·Ó¥½Ğ£¬
½ĞÈËÍ·Æ¤·¢Âé¡ ºÃÁË£¬Ç°Ãæ¾ÍÊÇ¹óÑô³ÇÁË¡£
LONG
	);
	set("exits", ([ 
  "northwest"  : __DIR__"eroad3",
  "northeast" : "/d/road/guiyang",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

