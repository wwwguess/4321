
#include <room.h>
inherit ROOM;

void create()
{
    set("short","��������");
	set("long", @LONG
��Ӻ������������������봩�á���������Ժ��һ�����������  
������һ�����ʹ�Ӱ�ڣ�����һ����ţ�СС��һ��ͥ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" :__DIR__"latemoonc",
		"south" : "/d/latemoon/room/twoc",
		"east" : "/d/latemoon/latemoon2",
	]));


	create_door("east","����","west", DOOR_CLOSED);
	setup();
}
