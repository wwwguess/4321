
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rcstogz4",
//	"northeast" : "/d/latemoon/sroad1",
        "south": "/d/tieflag/troad2",
]));
        set("objects", ([
                "/obj/npc/cityguard" : 2,
                "/obj/npc/wujiang1"+random(2) : 1,
        ]) );


	setup();
	replace_program(ROOM);
}
