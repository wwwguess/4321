// Room: /d/taohua/taijie2.c

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
   "north" : __DIR__"taijie3",
  "south" : __DIR__"taijie1",
]));
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
