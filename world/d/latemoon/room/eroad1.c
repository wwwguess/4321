#include <room.h>
inherit ROOM;

void create()
{
   set("short", "���᷿�ߵ�");
	set("long", @LONG
ͨ�������ߵ����������߽����᷿�ߵ������˳������ߵ��У�
һ�������Ĺ���! �ߵ����԰���������滨��ݣ����и�����ɫ��
��̬������������һ�ֵ����������������㿴��һ�����š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "east"  :__DIR__"eastroom",
    "west" :__DIR__"corridor7",
    "north" :__DIR__"eroad2",

]));

   create_door("east","��������","west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
