// Room: /d/oldpine/npath2.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
������������һ���ּ��С·�ϣ�С·���Գ����˸��ʵ���������
�ּ䴫�������������С·���ϱ��������������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/d/oldpine/npath3",
  "north" : "/d/oldpine/npath1",
]));
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
