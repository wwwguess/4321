// Room: /d/goathill/mroad2.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������������һ����᫵�ɽ·�ϣ�·�浽�������˼�ϥ���Ӳݴԣ�
��ʾ�����Ѿ���һ��ʱ��û�г������ˣ���������������Ұ��ɽ�ĵ�
�磬Ұ��ɽ��һ��ɽկ��ס������׶�ĵ��ˣ�������Ƶ����С�
LONG
	);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"mroad3",
		"south" : __DIR__"mroad1",
]));

	setup();
	replace_program(ROOM);
}
