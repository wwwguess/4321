// Room: /d/snow/w_room.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
����һ���ɨ���൱Ǭ���ķ��䣬��Ȼ���еļҾ㿴�������൱��
�ء����й��߱Ƚϰ���һΪ��ò����ͨͨ���������ڷ���������档
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"xx",
	]));
//	set("objects" , ([
//		"/d/zhang/boss":1,
//	]));
//	create_door("east", "����", "west", DOOR_CLOSED);
	
	setup();
}
