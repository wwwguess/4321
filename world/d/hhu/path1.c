// Room: /d/hhu/path1.c

inherit ROOM;

void create()
{
	set("short", "林荫道");
	set("long", @LONG
这是一条林荫道，四周风景非常美丽，路边竖着一个牌子(sign).
LONG
	);
        set("item_desc",([
            "sign":"欢迎你来到现代社会，这是二十世纪九十年代的南京市。\n这条路叫汉口西路，向西通向河海大学。You are welcome！\n",
        ]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"path2.c",
]));
	set("no_clean_up", 0);

	setup();
}
