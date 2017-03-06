
inherit ROOM;

void create()
{
	set("short", "洛阳");
	set("long", @LONG
这里是洛阳的南城门，高大的城门使你不仅暗叹这不愧是九朝故都。洛阳城
可是不能过而不入，洛阳牡丹可是天下闻名，你不妨去找一找秋翁，坐在他
的牡丹园中，观赏着牡丹，听一听他偶遇花仙的经历，别有一番情趣。另外，
龙门石窟、关林和白马寺也不能不去，说不定你会有意外的惊喜。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/rlytotg0",
	"east" : "/d/road/rjdtoly4",
	"south" : "/d/road/rlytoxy0",
]));

	setup();
	replace_program(ROOM);
}
