// Room: /d/snow/inn_3f.c

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����ջ��¥");
	set("long", @LONG
�����������������ջ����¥�������ǺӺ����ɵ��Ĵ�������è�ľ��ҡ�
ǽ����һ����������è�ı�ī��

           �������־��£��ջ��ף����̷׷ɡ�
               б���⣬��ѻ���㣬��ˮ�ƹ´塣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" :"/d/snow/inn_2f",
		"east" : __DIR__"e3_room",
	]));
	
	set("objects", ([
		"/u/sbaa/sb2":	1,
		]));

	//create_door("north", "����", "south", DOOR_CLOSED);
	create_door("east", "����", "west", DOOR_CLOSED);
	//create_door("west", "����", "east", DOOR_CLOSED);

	setup();
}
void init()
{ //add_action ("do_paiming","paiming");
}

