// Room: /d/waterfog/westhall.c

inherit ROOM;

void create()
{
	set("short", "ˮ�̸����໨��");
	set("long", @LONG
������ˮ�̸��������Ļ�����������ˮ�̸�����ţ��ϱߺ�����
Χ��һȦ�������ˣ��������������軨��������ˮ�̸�Ĳ��ţ�����
����Կ���ͨ��ˮ�̸��¥�Ľ��ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"weststair",
		"east" : __DIR__"entrance",
]));

	setup();
	replace_program(ROOM);
}
