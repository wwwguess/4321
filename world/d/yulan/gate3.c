
inherit ROOM;

void create()
{
	set("short", "长沙城大街");
	set("long", @LONG
	这条大街约有五丈来宽，是用一色的大青石砌成，由于人们
	经常走动的缘故，一点青苔也没有，光光的露出石头的原色。
	西面是到衙门的路，东边是出城的方向。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west"  : "/d/maintown/mt_road5",
  "east"  : "/d/yulan/gate2",
]));
        set("no_clean_up", 0);
        
	set("outdoors", "maintown");

	setup();
	replace_program(ROOM);
}

