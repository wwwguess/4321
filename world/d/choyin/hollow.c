// Room: /d/choyin/hollow.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ϊ�ͱڣ��⻬���һ�󺮹����㣬������Ƣ��ȴ��֪���Ժη�������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hollow1",
]));
	set("no_magic", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
