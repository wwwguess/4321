// Room: /d/taohua/yonglu1.c

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
  "north": __DIR__"yonglu2",
  "south" : __DIR__"houting",
 
]));
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
