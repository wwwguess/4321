
inherit ROOM;

void create()
{
	set("short", "杭州城外");
	set("long", @LONG
这儿就是杭州了，往东走就进城了。人来人往，十分热闹。
往南就要进入武夷山区了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rhztosz2",
	"south": "/d/road/rfztoyt4",
	"southwest" : "/d/road/rhztoyt0",
]));

	setup();
	replace_program(ROOM);
}
