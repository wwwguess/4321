// Room: /d/temple/ladder4.c

inherit ROOM;

void create()
{
	set("short", "ʯӢ��ʯ��");
	set("long", @LONG
��������һ��������ʯӢ�ҽ�����, ���ݵ�������ֲ��һ�Ÿ���
��������ѩͤ����ڶ��߲�Զ��ɽ��, ����Լ�������������ϴ�����
��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"ladder3",
  "eastdown" : __DIR__"ladder5",
]));
	set("no_clean_up", 0);
	set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
