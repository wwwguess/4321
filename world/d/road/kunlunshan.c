#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY "昆仑山脚下" NOR);
	set("long", @LONG
这里就是昆仑山脚下，抬头一望，昆仑山直入云霄。
天上不时飞过几只秃鹰，叫声凄厉，让人心中有点发毛。
东北有一个小镇,不时有一些白衣人出入.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rqhhtokl4",
	"northeast" : "/d/mingjiao/xiaozhen",
	"south" : "/d/road/rkltotgl0",
]));

	setup();
	replace_program(ROOM);
}
