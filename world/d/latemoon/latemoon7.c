
#include <room.h>
inherit ROOM;

void create()
{
     set("short","��Ժ�ߵ�");
	set("long", @LONG
������һ�������ϣ����Զ���̨ͥ���У�����������һ��
��������Ϣ�����������������ȥ�������Ǻ���Ժ�ӣ�����
��һ���鷿��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"latemoon8",
    "east" :__DIR__"latemoonc",
    "west" :__DIR__"latebook",

]));

   create_door("south","ʯ��","north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
