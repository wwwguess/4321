// Room: /d/taohua/yonglu2.c

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
  "north": __DIR__"houhuayuan",
  "south" : __DIR__"yonglu1",
 
]));
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
