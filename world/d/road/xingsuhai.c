
inherit ROOM;

void create()
{
	set("short", "无名山脚");
	set("long", @LONG
这里是一座无名大山山脚,山峰直入云霄.西边一条山路蜿蜒
伸向山的深处.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northeast" : "/d/road/rqhhtoxsh1",
        "westup"   : "/d/xingxiu/tianroad1",
]));

	setup();
	replace_program(ROOM);
}
