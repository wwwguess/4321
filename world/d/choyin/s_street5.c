// Room: /d/choyin/s_street5.c

inherit ROOM;

void create()
{
	set("short", "�а���");
	set("long", @LONG
�����������س��ϵĳа��֣���������ͨ�����ֵ����Ź㳡������
��·������ͨ���ظ����ŵĲ�ƽ�֣��ֵ�������һЩ�����ճ��þߵ���
�꣬�ϱ�����һ��յأ���������Կ����ϱߵĳ�ǽ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"crossroad",
		"east" : __DIR__"s_street4",
]));
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
