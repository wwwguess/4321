// Room: /d/snow/sroad3.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��������ʵ����");
	set("long", @LONG
��������������ʵ���ң�
�����������ż�������ݽ��и���յ�����һ������ܣ���
һ��ͶӰ��Ļ������ǰ�����Ա߻�����һ���绰��������
У�������û���ͨ��Ϣ��鰵�����Ҳ���������ѯ���й�
��������.
LONG
	);
	set("exits",([ /* sizeof() ==2 */
	"north": __DIR__"roadtocenter1",
	"up": __DIR__"center_2f",
]));
	set("objects", ([
		__DIR__"npc/yanjiusheng": 1 ]) );

        create_door("north","������","south",DOOR_CLOSED);
	setup();
}
