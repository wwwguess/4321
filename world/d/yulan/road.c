
inherit ROOM;

void create()
{
	set("short", "青石小径");
	set("long", @LONG
这是一条普通的青石小径，弯弯曲曲往东而去，路两旁是一片玉兰树林，正
是早春时节，朵朵白玉兰挂满枝头，往东北是一条青石小径。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
//  "west" : "/d/road/changsha",
  "northwest" : "/d/road/ryytocs2",
  "northeast" : "/d/yulan/road1",
]));
	setup();
	replace_program(ROOM);
}
