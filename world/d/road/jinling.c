//jinling   hhumud
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR "金陵" NOR);
	set("long", @LONG
这儿就是六朝古都金陵的西门外。
金陵，有称石头城的。有句话就是赞美这儿的"钟灵毓秀石头城"。
西面是到马鞍山的驿道，往东南则到”上有天堂，下有苏杭“
的苏州城了。西南面是金陵城的驿站，不时可以看到有差人
从那儿进进出出。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : __DIR__"jldukoun",
	"southeast" : __DIR__"rjltosz0",
	"southwest" :"/d/hhu/yizhan",
//	"east" : "/d/hhu/out-hohai",
	"west"     : __DIR__"rcstoyt4",
]));
	set("outdoors","road");
	setup();
	replace_program(ROOM);
}
