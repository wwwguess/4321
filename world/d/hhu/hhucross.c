// Room: /d/hhu/hhucross.c

inherit ROOM;

void create()
{
	set("short", "河海大学交通中心");
	set("long", @LONG
由此向东南到河海东门（正门），向东北到河海东二门，
    由此向西南到河海西门，向西北到河海体育场。
    正西有一座雕像(statue)，正北通向河海科学馆。
    四周风景很美。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "statue" : "这是河海大学校友张闻天的塑像，他是我国著名的无产阶级革命家。
",
]));
	set("exits", ([ /* sizeof() == 5 */
  "northeast" : __DIR__"hhu2road1",
  "southeast" : __DIR__"hhupath4",
  "northup" : __DIR__"uproad",
  "northwest" : __DIR__"hhu3road1",
  "southwest" : __DIR__"hhu1road1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/msg_student" : 1,
]));
	set("no_clean_up", 0);

	setup();
}
