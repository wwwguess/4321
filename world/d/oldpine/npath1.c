// Room: /d/oldpine/npath1.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
������������һ���ּ��С·��������Զ���߳��������Ӿ���ѩͤ
��С·���Գ����������ʵ�������ѩͤ��ľ��񶼰������������
���֡�����˵����������������ǧ�����������������顣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/oldpine/npath2",
  "north" : "/d/snow/eroad3",
]));
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
