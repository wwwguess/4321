inherit ROOM;

void create()
{
	set("short", "地下密室");
	set("long", @LONG
这里是一间窄小的密室，你的面前只有一条漆黑的小路，路的尽头现出一点亮光。
LONG
	);

        set("exits", ([ /* sizeof() == 3 */
            "west" : "/d/yulan/secrect1",
            "east" : "/d/yulan/xiaolu",
]));

	setup();
	replace_program(ROOM);
}
