// Room: /d/goathill/slope1.c

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
������һ����ʯб�£�б���ϵ���������ʯ���Ӳݣ����ߵ��ұڱ�
��һ��ʯ�ݣ���������������Իص�������ʯ��ɽ·��
LONG
	);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"mroad6",
		"west" : __DIR__"mroad5",
]));

	setup();
	replace_program(ROOM);
}
