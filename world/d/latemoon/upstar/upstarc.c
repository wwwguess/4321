
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "ǰ��¥");
	set("long", @LONG
������ׯԺ��¥��ǰ��¥��������ͳ�Ĺ�ʽ����������Ϻõ�        
��ľ�����, ����һ��ҫ�۵ĵİ׹������ȳ�������ش��������
����ӳ��һ�������ľ��ĸ�֡�����¥�ų�ȥ����һ��ׯԺ�����ɽ
����ɫ���������������ۡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "east" :__DIR__"uplook",
    "north" :__DIR__"upstar4",
    "south" :__DIR__"upstar3",

]));

    create_door("east","¥��","west", DOOR_CLOSED);
    setup();
	replace_program(ROOM);
}
