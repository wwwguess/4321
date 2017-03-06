//by dwolf
//lou.c /
   
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"吹雪楼"NOR);
	set("long", @LONG
	   "万物中雪为纯净，故世人多爱赏雪，而赏雪的最高境界为吹雪，雪花满
天，独行雪中，思接千载，视通万里，呼一丝热气，吹漫天飞雪，领略高手那一种寂
寞，以及那一种对生命的深层感触。吹雪楼的隅意，大概就在于此吧。"这是吹雪山庄
最大的一 幢楼。风景非常美丽。
LONG
	); 
	set("exits", ([
		"up" : __DIR__"lou2.c",
		"east" : __DIR__"guarden2",
]));
	setup();
	replace_program(ROOM);
}
