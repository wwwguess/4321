// Room: /d/choyin/n_gate.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
      ��Ұ֮��, һƬï�ܵ�����, ��û�˶��е�С·. ����, ��Զ��
һ��������С��, ������������. 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west"  : "/u/cloud/sunhill/road1",
		"south" : __DIR__"n_gate",
	]));
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
