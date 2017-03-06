
inherit ROOM;

void create()
{
	set("short", "襄阳");
	set("long", @LONG
这里就是襄阳城，城门上斗大的两个“襄阳”二字气势磅礴。
这里车水马龙，热闹非凡。西北方向不时有着道衣装束的武者
来往。北面则是到洛阳古城。东南则到南方去了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rlytoxy3",
	"west" : "/d/road/rxytowds0",
	"northwest" : "/d/wudang/wdroad1",
	"southeast" : "/d/road/rxytohk0",
]));

	setup();
	replace_program(ROOM);
}
