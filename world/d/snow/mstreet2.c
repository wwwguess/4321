// Room: /d/snow/mstreet2.c

inherit ROOM;

void create()
{
	set("short", "ѩͤ��ֵ�");
	set("long", @LONG
������������ѩͤ��Ĵ�֣�����ֱ�߲�Զ�������ϵĹ㳡������
�Ķ�����һ���լԺ���������Ų����������������һ�Ҵ������ӣ�
������������������Զ�������õ����ֵ�������һֱͨ�����⡣
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : "/d/snow/mstreet3",
  "south" : "/d/snow/mstreet1",
  "west" : "/d/snow/smithy",
  "east" : "/d/snow/workplace",]));
	set("objects", ([
	__DIR__"npc/drunk" : 1,
                 __DIR__"npc/scavenger":4 ]));

	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
