
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "������ǰ");
	set("long", @LONG
������ׯԺ��¥�ķ�����ǰ��������ŵ�һ��Ũ����̴����Ϣ��
������������һ��ׯ���ྲ�ĸо�������Ͼ֮����������������
��ʱ��ȥ����ķ������£��ݷ���Էſ�һ�С ����ʱ�ն���ֹ��
������ľ��������㿴��һ��̴��ľ�š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"uproom",
    "north" :__DIR__"upstar1",
    "south" :__DIR__"upstar2",

]));

    create_door("west","̴��ľ��","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
