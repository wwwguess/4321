// Room: /d/sanyen/corridor.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������һ��������, ������ֲ��һ���¹������ϱߵĲ�᣺���
���, �������Ǻ������Ǹ���С�Ĺ㳡, �㳡����ɹ��һЩ��֪
����ҩ�ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/sanyen/corridor1",
  "north" : "/d/sanyen/back_temple",
  "south" : "/d/sanyen/temple",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
