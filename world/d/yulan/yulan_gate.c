#include <room.h>

inherit ROOM;

void create()
{
	set("short", "玉兰山庄大门");
	set("long", @LONG
你现在正站在一间大庄院的入口，眼前是一个高大的红漆大门，
门的上方高挂着一个金匾，上书玉兰山庄四个大字，西边是一个
小石桥。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/yulan/road2",
  "east" : "/d/yulan/yulan",
]));
	set("outdoors", "yulan");

	create_door("east", "红漆大门", "west", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
