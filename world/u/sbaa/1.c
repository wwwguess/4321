// Room: /d/snow/inn_3f.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�����ջ��¥");
	set("long", @LONG
�����������������ջ����¥������������������ס�ĵط���ÿ�춼�������
������һ����������ĵķ�ɣ�ǽ����һ����������è�ı�ī��

           �������־��£��ջ��ף����̷׷ɡ�
               б���⣬��ѻ���㣬��ˮ�ƹ´塣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	//	"west" : __DIR__"w_room",
	//	"north" : __DIR__"n_room",
		"down" :"/d/snow/inn_2f",
	//	"east" : __DIR__"e_room",
	]));
	
	set("objects", ([
		"/obj/sbaa/mengzhu":	1,
		]));

	//create_door("north", "����", "south", DOOR_CLOSED);
//	create_door("east", "����", "west", DOOR_CLOSED);
	//create_door("west", "����", "east", DOOR_CLOSED);

	setup();
}
