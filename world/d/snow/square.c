// Room: /d/snow/square.c

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
������ѩͤ����ǰ�㳡�Ŀյأ����������������ʯ�塣�㳡������
һ��ľͷ��ļ��ӣ���������ķ紵��ɹ���ܣ������ǳ��ƾɡ����ܽ���
��������������Կ���һ���ջ�����������ƺ��ܺá�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"mstreet1",
		"west" : __DIR__"inn",
		"south" : __DIR__"sroad1",
		"east" : __DIR__"temple",
	]));
     set("no_fight",1);
     set("no_beg",1);
     set("no_sleep",1);
	set("objects", ([
		__DIR__"npc/trav_blade" : 3,
		__DIR__"npc/zhuhongxue" : 1,
	  ]) );

	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
