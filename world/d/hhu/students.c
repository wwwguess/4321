// Room: /d/hhu/students.c

inherit ROOM;

void create()
{
	set("short", "学生城");
	set("long", @LONG
学生城内装修的富丽堂皇，
    一楼是学生餐厅，有许多学生在此打饭。
    靠着一根柱子有个汤锅，有许多学生在那里打汤喝(drink),
    你的肚子不禁咕咕叫了几声，是不是该吃点东西了？
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"hhu1road3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/seller.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
}
void init ()
{
        add_action("do_drink","drink");
}

int do_drink(string arg)
{
        if (!arg||arg=="")
           return notify_fail("你要喝什么？\n");
        if (arg=="water")
           {
            return notify_fail("喝生水是要生病的，你可以喝点汤(soup)\n");
           }

        if (arg!="soup")
           return notify_fail("很抱歉，学生城不提供"+arg+"\n");
        if ((int)this_player()->query("water") >= (int)this_player()->max_water_capacity())
        return notify_fail("你再也喝不下一点汤了\n");
       message_vision("$N用勺子舀起一勺汤，喝了下去\n",this_player());
        this_player()->add("water",40);
        return 1;
}
