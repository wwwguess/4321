// Room: /d/snow/inneryard.c

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
  这里是淳风武倌中的天井，往西走可以到正厅，往北走
是书房，南边是招待客人的厢房，往东一条长廊通往武倌
内院，天井中种满了奇花异晁，中间立着一根石柱(pill
ar)，上面似乎刻着字
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
		"pillar" : "石柱上刻著：剑气指天、剑心内敛、剑芒不显、剑神如电。
",
]));
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 5 */
		"west" : __DIR__"schoolhall",
		"north" : __DIR__"nyard",
		"south" : __DIR__"guestroom",
		"east" : __DIR__"innerhall",
]));
     set("no_clean_up",0);
     set("outdoors", "snow");
replace_program(ROOM);
	setup();
}
