// Room: /d/waterfog/weststair.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ˮ�̸��������Ժ��һ����ʯ�ݴ�����ͨ����¥����������
�۵��Է����񷿣��ϱ��ǳ�ˮ�̸�Ĳ��ţ���������һ����������ɽ��
����̨��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"up" : __DIR__"west_2f",
		"north" : __DIR__"storage",
		"south" : __DIR__"westhall",
]));

	setup();
	replace_program(ROOM);
}
