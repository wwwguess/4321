// Room: /d/hhu/studentroom1.c

inherit ROOM;

void create()
{
        set("short","学生二舍");
	set("long", @LONG
学生二舍是1993年新盖的，学生4个人一个房间，
每个房间里有一台彩电，条件相当的好。但是
电视耽误了不少人的学习和休息，就象MUD游戏
一样，容易让人沉溺其中,这是一幢女生楼，楼
下常能看到伸长了脖子等人的痴情王子......
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"studentroom1",
  "north" :__DIR__"studentroom3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/student_2" :3,
]));
	set("no_clean_up", 0);

	setup();
}
