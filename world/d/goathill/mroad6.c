// Room: /d/goathill/mroad6.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������������һ����᫵�ɽ·�ϣ�������һ��Ͽ�ȣ�ͨ�����ɻ���
�������·�����������Կ���һ���塢���ɿ��ʯ��κ�����ؿ��Ͽ��
��ɽ·������ת�����ϱ�����һƬ��ʯб�¡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"canyon1",
		"southwest" : __DIR__"mroad5",
		"south" : __DIR__"slope1",
]));
	set("outdoors", "goathill");

	setup();
	replace_program(ROOM);
}
