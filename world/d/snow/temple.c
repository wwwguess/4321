#include <obj.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʮ���Ͼɵĳ�����������ǰ�������Ϲ�����һ������ĳ�
�������Ͼɣ������������ѱ����޹���ںڵ���ɫ����ʾ����ض���
���ܵ���ͽ�ľ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : "/d/snow/eroad1",
		"west" : "/d/snow/square",
	]));
	set("no_fight", "1");
	set("objects", ([ /* sizeof() == 2 */
		OBJ_PAPER_SEAL : 2,
		__DIR__"npc/keeper" : 1,
		__DIR__"obj/denotation" : 1
	]));

	setup();
	replace_program(ROOM);
}
