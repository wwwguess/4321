// Room: /d/choyin/hollow2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
    �����Ϊ�ͱڣ��⻬���һ�󺮹����㣬������Ƣ��ȴ��֪���Ժη�������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hollow3",
  "south" : __DIR__"hollow1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
