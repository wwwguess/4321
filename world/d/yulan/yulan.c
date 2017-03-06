#include <room.h>

inherit ROOM;

void create()
{
	set("short", "玉兰山庄前院");
	set("long", @LONG
你现在正站在一间大庄院的前院，西边是一个高大的红漆大门，
东边是一个玉兰山庄的大厅。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/yulan/yulan_gate",
  "east" : "/d/yulan/yulanhall",
]));

        set("objects", ([
             __DIR__"npc/chicken" :2,
        ]) );


       set("outdoors", "yulan");
       create_door("west", "红漆大门", "east", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
