// Room: /d/waterfog/easthall.c

inherit ROOM;

void create()
{
	set("short", "ˮ�̸󶫲໨��");
	set("long", @LONG
������ˮ�̸����Ŷ��ߵĻ��������ߺ��ϱ�Χ��һȦ��ʯ���ˣ���
�����������軨��������ˮ�̸�����ţ��������Ƕ���Ĳ���������
����Կ���ͨ����¥�Ľ��ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"eaststair",
		"west" : __DIR__"entrance",
]));

	setup();
	replace_program(ROOM);
}
