// Room: /d/taohua/yonglu7.c

inherit ROOM;

void create()
{
	set("short", "�·");
	set("long", @LONG
ֻ����ľ���񣬲Դ���죬�������ģ�������һ����ʯС����
��ǰ���������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "west": __DIR__"yonglu6",
  "east" : __DIR__"shufang",
  "north": __DIR__"qyfroom",
]));
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
