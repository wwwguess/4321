// Room: /d/suzhou/bingyin.c
// by dwolf
//97.11.4 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"兵营大门"NOR);
	set("long", @LONG
	你正站在兵营的门口，面对着一排简陋的营房，可以看到穿着制服的官兵
正在操练，不时地传来呐喊声。老百姓是不允许在此观看的，你最好赶快走开。
LONG
	);

	set("exits", ([
		"south" : __DIR__"yinzhang",
		"north" : __DIR__"eroad2",
	]));

	set("objects", ([
		__DIR__"npc/bing" : 4,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && me->query("family/family_name")!="朝廷" && objectp(present("guan bing", environment(me))) && dir == "south")
		return notify_fail(RED"官兵拦住了你的去路。\n"NOR);
	return ::valid_leave(me, dir);
}

