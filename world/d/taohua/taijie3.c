// Room: /d/taohua/taijie3.c

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
   "north" : __DIR__"qianting",
  "south" : __DIR__"taijie2",
]));
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
