// Room: /d/goathill/mroad5.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ����խ��ɽ·��������Զ�����ұڱ�����һ��ʯ�ݣ�·��
�����˼����ĳ��ݣ�ɽ�紵��һ��һ�������粨��һ�㣬�ϱ���������
���ʯ�����������Ǹ�����ĺõص㣬������һ��ɽ·��ת�ǡ�
LONG
	);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 3 */
		"northeast" : __DIR__"mroad6",
		"east" : __DIR__"slope1",
		"west" : __DIR__"mroad4",
]));

	setup();
	replace_program(ROOM);
}
