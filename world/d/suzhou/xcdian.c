//ROOM: d/suzhou/xcdian.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"С�Ե�"NOR);
	set("long", @LONG
	  ������С�Ե꣬С������ӭ������������в��ٿ�����Ʒ���ŷ�ζ�����С�ԡ�
LONG
	);
	set("no_sleep_room", 1);
	set("outdoors","suzhou"); 
	set("exits", ([
		"north" : __DIR__"wroad3",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
]));
	setup();
}





