// Room: /d/suzhou/yinzhang.c
//by dwolf
//97.11.4 

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"营帐"NOR);
	set("long", @LONG
	这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操练，
有的独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不动声色地寻视
着四周。看到你进来，他们全都向你包围了过来，形势看来不太妙。南边有一个
布帘(bulian)。
LONG
	);

	set("item_desc", ([
		"bulian" : "这是一块极厚的布帘子，后面仿佛有什么在动。\n",
	]));
	set("exits", ([
		"south" : __DIR__"zhuyin",
		"north" : __DIR__"bingyin", 
	]));

	set("objects", ([
                 __DIR__"npc/ypfeng" : 1,
                "/obj/npc/wujiang1"+random(3) : 1,
                "/obj/npc/wujiang1"+random(3) : 1,
		__DIR__"npc/bing" : 6,
	]));

	create_door("south", "bulian", "north", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail(RED"官兵拦住了你的去路。\n"NOR);
	return ::valid_leave(me, dir);
}

