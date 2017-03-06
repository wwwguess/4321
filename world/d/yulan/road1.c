
inherit ROOM;

void create()
{
	set("short", "青石小径");
	set("long", @LONG
这是一条普通的青石小径，弯弯曲曲往东而去，路两旁是一片玉兰树林，正
是早春时节，朵朵白玉兰挂满枝头，往东是一座小石桥，向西南是通往县城
的路。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : "/d/yulan/road2",
  "southwest" : "/d/yulan/road",
]));

	setup();
	replace_program(ROOM);
}
