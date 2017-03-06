
inherit ROOM;

void create()
{
	set("short", "玉兰山庄大厅");
	set("long", @LONG
这是玉兰山庄的正厅，大厅四周放着红木架子，架子上摆放着古玩玉器，
正对厅门放着一个汉白玉石龛, 石龛上放着一朵白玉雕的玉兰花。
往西是玉兰山庄大门，往东是玉兰山庄后院。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"east" : "/d/yulan/yulanc",
	"west" : "/d/yulan/yulan",
	"north" : "/d/yulan/woshi",
	"south" : "/d/yulan/shufang",
]));
	set("objects", ([
                __DIR__"obj/yulan" : 1,
]));

	setup();
	replace_program(ROOM);
}
