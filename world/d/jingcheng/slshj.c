#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"三联书局"NOR);
	set("long", @LONG
这是一家新开张不久的书局。书架上整整齐齐地放着一些手抄的卷
轴。雕板印刷书到了唐朝已日趋成熟，因此这里的书架上也放着不
少印制精美图文并茂的图书。
LONG         
	);        
	set("objects", ([
		__DIR__"npc/he.c" : 1,
]));

	set("exits", ([ 
 "south":__DIR__"xchjie5", 
 
	]));
	setup();
	
}

