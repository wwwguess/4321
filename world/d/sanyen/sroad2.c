// Room: /d/sanyen/sroad2.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����ɽ·������ת�˸��䣬��������һ��ɽ������������������
����˳��ɽ�ƻ�����ɽ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
//  "south" : "/d/sanyen/sroad1",
 "northdown": "/u/cloud/sunhill/road4",
 "east" : "/d/sanyen/gate",
]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
