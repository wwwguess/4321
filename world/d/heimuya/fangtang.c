// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","·¹ÌÃ");
	set("long", @LONG
	Ò»¸ö´ó·¹ÌÃ,ÖÐ¼äÒ»ÕÅÆæ³¤ÎÞ±ÈµÄ³Ô·¹×À£¬ÉÏÃæ°ÚÖø¼¸ÅÌ²Ë
Ò»¿´¾ÍÊÇÆÕÍ¨½ÌÖÚ³Ô·¹(chifan)µÄµØ·½.¡
LONG
	);

	set("exits", ([
		"east"  :__DIR__"dingfeng5.c",
	]));

	setup();
}

void init()
{
        add_action("do_chifan", "chifan");

}

int do_chifan()
{
	this_player()->start_busy(5);
	write(YEL "Äã×øÏÂÀ´±¥±¥µØ´ó³ÔÁËÒ»¶Ù\n" NOR);
	write(YEL "Ö±³ÔµÃ¶Ç·Ê³¦Âú²ÅÐÄÂúÒâ×ãµØÕ¾ÆðÉíÀ´\n" NOR);	
	this_player()->set("food",350);
	this_player()->set("water",350);
	return 1;
}
