// /d/city/wumen
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǿ�ʦ�����š����Ž����Ͻ��ǵ�Ҫ����������ׯ�ϵĴ���
(gate)����������ص��Ͻ��ǡ����ŵ��������һ��ʯʨ(statue)��
��������ض�����������Ⱥ������������ѡ��״Ԫ��У�䳡��Ҳ��֪
������û���ˡ�������Ľֵ�Χ�����Ͻ��ǡ�
LONG
        );

        set("exits", ([
		"east":		__DIR__"street3",
		"west" :	__DIR__"street4",
		"south" :	__DIR__"jiaowu",
//		"north":	__DIR__"zijincheng",
		]));
        set("outdoors", "city");

//	create_door("north", "����", "south", DOOR_CLOSED);

        setup();
        replace_program(ROOM);
}

