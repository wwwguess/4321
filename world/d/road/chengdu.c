// chengdu 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR "成都" NOR);
	set("long", @LONG
这里就是天府之国的成都。这里土地肥沃，人民勤恳。
大家过得还不错。西南方向是川中最有实力的唐门；
东北则是去兰州、长安的驿道了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"southeast" : "/d/road/rcdtodk0",
	"southwest" : "/d/road/rcdtojs0",
	"northeast" : "/d/road/rjmtocd2",
]));

	setup();
	replace_program(ROOM);
}
