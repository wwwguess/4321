// Room: /d/choyin/s_street4.c

inherit ROOM;

void create()
{
	set("short", "�а���");
	set("long", @LONG
�����������سǳ��ϵĳа��֣��ֵ�ʮ�ֿ����ϱ����߶���һЩ
�����ϱ���������Ʒ���̵꣬������Ȼ�����������˳�������Ƶ����Ҫ
�壬����ȴû�и��ִ�����֣������߱������Ź㳡���������ǺͲ�ƽ
�ֵĽ���·�ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"s_street5",
		"east" : __DIR__"s_street1",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
