// Room: /d/hhu/hhu1road3.c

inherit ROOM;

void create()
{
	set("short", "林荫道");
	set("long", @LONG
你现在走在河海大学校内的林荫道上
    路南是河海大学的学生城，
    路北是河海大学的宿舍楼，
    向西看可以望见河海大学的西门，
    经常有学生从这里通过，
    四周风景很美。
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"downroad",
  "west" : __DIR__"hhugate_west",
  "south" : __DIR__"students",
  "north" : __DIR__"studentroom1",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/student_1" : 2,
  __DIR__"npc/student_2" : 1,
]));
	set("no_clean_up", 0);

	setup();
}
