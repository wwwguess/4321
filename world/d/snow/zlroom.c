// Room: /d/snow/guestroom.c

inherit ROOM;

void create()
{
	set("short", "淳风武馆南厅");
	set("long", @LONG
这里是淳风武馆的南厅，布置得相当雅致，厅中摆放着一张红木圆桌和
几条红木圆凳，这儿一般是派中长老议事的地方。从窗子向北望就是正厅了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/snow/schoolhall",
]));
	set("objects",
		([
		   CLASS_D("swordsman")+"/zhanglao1":1,
		   CLASS_D("swordsman")+"/zhanglao2" : 1
]) );	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
