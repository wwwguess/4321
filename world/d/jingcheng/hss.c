#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"化生寺"NOR);
	set("long", @LONG
化生寺是长安城里规模最大的一家丛林了。整日里香烟袅绕，颂
经声不绝于耳。来这里上香还愿的善男信女也特别多，若到了皇
道吉日，更是人山人海。
LONG         
	);

	set("exits", ([ 
 "north" :__DIR__"xchjie2", 
 
	]));
	setup();
}

