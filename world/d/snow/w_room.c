// Room: /d/snow/w_room.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
����һ���ɨ���൱Ǭ���Ŀͷ�����Ȼ���еļҾ㿴�������൱��
�أ��Ȳ����س��Ｘ�������Ĵ�ƹݣ���������һ�ֶغ����еĸо���
�����������ſ��԰��ĵ���Ϣ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"inn_2f",
	]));

	create_door("east", "����", "west", DOOR_CLOSED);
	
	setup();
}
