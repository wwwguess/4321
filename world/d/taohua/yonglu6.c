// Room: /d/taohua/yonglu6.c

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
  "west": __DIR__"houhuayuan",
  "east" : __DIR__"yonglu7",
  "north": __DIR__"lchfroom",
  "south" :__DIR__"fmfroom",
]));
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
