// Room: /d/taohua/taijie1.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ��С·�������ۣ���ʱ·���Ѷϣ���
��Ȼһת����������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
"northeast":__DIR__"haitan1",
  "south" : __DIR__"taolin",
  "north" : __DIR__"taijie2",
]));
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
