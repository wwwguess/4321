// Room: /d/temple/ladder3.c

inherit ROOM;

void create()
{
	set("short", "ʯӢ��ʯ��");
	set("long", @LONG
��������һ��������ʯӢ�ҽ�����, ���ݵ�������ֲ��һ�Ÿ���
��������ѩͤ����ڶ��߲�Զ��ɽ��, ����Լ�������������ϴ�����
�����������ݴ����������ϱߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"ladder2",
  "eastdown" : __DIR__"ladder4",
]));
	set("no_clean_up", 0);
	set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
