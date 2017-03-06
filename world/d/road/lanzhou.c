//lanzhou 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR "兰州" NOR);
	set("long", @LONG
这里是兰州城的东南门。通过城门看去，一条大路直通西北方向，路上的行人很多，
很多人是骑着骆驼，带着大批的货物，在匆匆地赶路。兰州是丝绸之路的必经之地，
如果你要继续西行，不妨在这里略做休整。兰州的沙枣和白兰瓜会让你大饱口福。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/lzdukoun",
	"southeast" : "/d/road/rcatolz3",
//	"west" : "/d/road/rqhhtolz2",
]));

	setup();
	replace_program(ROOM);
}
