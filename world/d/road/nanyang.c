
inherit ROOM;

void create()
{
	set("short", "南阳");
	set("long", @LONG
这儿就是南阳，相传诸葛孔明就在南阳西南的隆中结庐隐居。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rlytoxy0",
	"south" : "/d/road/rlytoxy1",
]));

	setup();
	replace_program(ROOM);
}
