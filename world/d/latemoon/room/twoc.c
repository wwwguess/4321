
#include <room.h>
inherit ROOM;

void create()
{
   set("short", "����");
	set("long", @LONG
�����ں�����Ժ�����ţ�������ׯ������Ժ�����ߵ������·
�ڡ������������ŷ��ļе��������ǳ��ȼе��������ǵ�����������
����߳�����ǰ��ǰԺ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" : "/d/latemoon/latemoon4",
    "south" :__DIR__"lcenter",
    "east" :__DIR__"eat1",
    "west" :__DIR__"two1",

]));

    create_door("south","��������","north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
