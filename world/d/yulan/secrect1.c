inherit ROOM;

void create()
{
	set("short", "地下密室");
	set("long", @LONG
这里是一间窄小的密室，你的面前只有一条漆黑的小路跟一些乾草。
LONG
	);

        set("exits", ([ /* sizeof() == 3 */
            "west" : "/d/yulan/secrect",
            "east" : "/d/yulan/secrect2",
]));

	setup();
	replace_program(ROOM);
}
