//by dwolf
//97.118

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"雪峰绝地"NOR);
	set("long", @LONG
	  你进入了一个绝地，到处是白雪，远处是万丈深渊，一头全身纯白的小狐
狸正在那儿打洞，看见你来时，不由用两只圆溜溜的眼珠上下打量你。近处有一棵很
大的雪松，松树下有一起小屋，你竞看不清它的轮廓，只因屋在雪中，本身也是雪。
有个少年在旁边看着这一切。
LONG	
);
	set("objects", ([
		__DIR__"npc/hufei.c" : 1,
		__DIR__"npc/feihu.c" : 1,
	]));  
	set("exits", ([
		"south" : __DIR__"halfhole.c",
	]));
	setup();
}
