#include <room.h>

inherit ROOM;

void create()
{
   set("short", "����");
	set("long", @LONG
�����������ӭ�������������������������ȥ��̧ͷһ����
ֻ������ǽ�ڣ�������͸���ٽ��黭������ǽ�ϡ�����ɴ�֣����
��⣬������̤��ש�����Ǳ����仨����һ���飬��һ����������
�ǵ�յ���̴��ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"flower1",
    "east" :__DIR__"corridor8",
    "west" :__DIR__"corridor6",

]));
    create_door("south","������","north", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
