// Room: /d/waterfog/kitchen.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ˮ�̸�ĳ���������һ�������߶���������ͣ�������
һ�ŷ��������Ϲ���ư��һӦ��ȫ����������һ���������Ͽ��Իص�
���С�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"eaststair",
]));

	setup();
	replace_program(ROOM);
}
