// Room: /d/sanyen/road2.c

inherit ROOM;

void create()
{
	set("short", "ʯ��С��");
	set("long", @LONG
��������һ����ʯ�������С����, ������ֲ��һ����ҩ������
ҩ��������˹���, ԭ��������Ƭ����ҩ�ԡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/sanyen/road1",
  "east" : "/d/sanyen/drag_field",
]));
	set("objects", ([
		__DIR__"npc/bonze":1 ]) );
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
