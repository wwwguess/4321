// Room: /d/taohua/yonglu5.c

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
  "south": __DIR__"yonglu4",
  "north": __DIR__"wifemu",	
]));
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
