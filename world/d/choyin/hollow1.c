// Room: /d/choyin/hollow1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ϊ�ͱڣ��⻬���һ�󺮹����㣬������Ƣ��ȴ��֪���Ժη�������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"hollow2",
  "south" : __DIR__"hollow1",
  "west" : __DIR__"hollow"
]));
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
