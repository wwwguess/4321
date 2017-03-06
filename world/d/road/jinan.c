//jinan  hhumud
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY "济南" NOR);
	set("long", @LONG
这里是济南的西南门，门口站立着两个守城的卫兵。
济南是一个很美丽的城市，素有泉城的美称，城里的泉水清冽甘甜，
而随处可见的垂柳在微风中婀娜摇曳，真是让你留恋不已。济南的
千佛山更是一个不能不去的地方，满山崖壁上千佛千面，足另你叹为观止。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rdktojn0",
	"south" : "/d/road/rjntoxz0",
	"east" : "/d/road/rjntopl0",
]));

	setup();
	replace_program(ROOM);
}
