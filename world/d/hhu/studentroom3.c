// Room: /d/hhu/studentroom1.c

inherit ROOM;

void create()
{
        set("short","学生三舍");
	set("long", @LONG
学生三舍是1992年盖的，学生4个人一个房间，
每个房间里有一台彩电，条件相当的好。但是
电视耽误了不少人的学习和休息，就象MUD游戏
一样，容易让人沉溺其中。。。。
那时，这个MUD的元老们都住在那里。每天点
上蜡烛吹牛，第二天再强打精神写MUD。。。
让我们永远记住这里。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
]));
	set("exits", ([ /* sizeof() == 1 */
  "south":__DIR__"studentroom2",
  "northeast" : __DIR__"hhusport",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/student_1.c" : 2,
   "/obj/money/silver" : 2,
]));
	set("no_clean_up", 0);

	setup();
}
