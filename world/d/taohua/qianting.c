// Room: /d/new_taohua/qianting.c

inherit ROOM;

void create()
{
	set("short", "ǰ��");
	set("long", @LONG
��ǰһ����һʯ�������顰���һ������Ӳ������ڣ��������Ը�����
��������һ��ľ�ƣ������һ����������ԡ� 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "north": __DIR__"dating",
  "south" : __DIR__"taijie3",
  "east" : __DIR__"nvpuroom",
  "west" : __DIR__"nanpuroom",
]));
	

	setup();
	replace_program(ROOM);
}
