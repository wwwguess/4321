// Room: /d/waterfog/eaststair.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ˮ�̸󶫱ߵĲ��������߸������˾�������׵���ȣ���
�������������������Ը��ܵ�ˮ�̸�����ڶ���֮�ϣ�����Ⱥɽ������
��������һ������ͨ����¥�������ǳ����봢������Ĳֿ⡣
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"up" : __DIR__"east_2f",
		"south" : __DIR__"easthall",
		"north" : __DIR__"kitchen",
]));

	setup();
	replace_program(ROOM);
}
