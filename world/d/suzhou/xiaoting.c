//ROOM: d/suzhou/xiaoting.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"Сͤ"NOR);
	set("long", @LONG
	   ����һ����������Ϣ��ͤ�ӡ�һ��С���ڴ���ߺ���š�
LONG
	);
	set("no_sleep_room",1);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"szroad4",
	]));
	set("objects", ([
		__DIR__"npc/ren2" : 1,
		__DIR__"npc/xiaofan" : 1,
	]));
	setup();
}





