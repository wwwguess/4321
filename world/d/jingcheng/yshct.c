#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"叶氏草堂"NOR);
	set("long", @LONG
这里是叶诚治先生算卦测字的地方。提起叶诚治，京城无人不晓，
他乃是当朝钦天监台正先生的师父。小屋里整日访客络绎不绝。
但叶先生是个坐不住的人，经常在京城里闲逛，所以这个小屋里
也常常没有人。
LONG         
	);

	set("exits", ([ 
 "east"  :__DIR__"ql3",
 	]));
	setup();
	
}

