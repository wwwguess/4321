// Room: /d/sanyen/road1.c

inherit ROOM;

void create()
{
	set("short", "ʯ����");
	set("long", @LONG
һ��������ʯ��Ĵ��, ������ֲһ����ҩ���������Ǵ��۱���
, һ���ϸ����ߵ���ΰ����, ���ܵ��ĸ�����������ֻ������Ľ�
��, �����»�������һ�������, ��紵��, ������������������
��������Сһ���ʯ��·, �����ҩ��ʹӶ��ߴ�����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
            "north" : "/d/sanyen/temple",
            "south" : "/d/sanyen/door",
            "east" : "/d/sanyen/road2",
	]));

	create_door("north", "����", "south");

	set("outdoors", "sanyen");
	set("objects", ([
		__DIR__"npc/monk" : 1
	]) );

	setup();
	replace_program(ROOM);
}
