
inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
������һ��������ɽɽ��,ɽ��ֱ������.����һ��ɽ·����
����ɽ���.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northeast" : "/d/road/rqhhtoxsh1",
        "westup"   : "/d/xingxiu/tianroad1",
]));

	setup();
	replace_program(ROOM);
}
