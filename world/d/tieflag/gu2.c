// Room: dong0
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "桥上");
        set("long", @LONG
小桥上，朱栏低垂，垂柳下，少女轻笑。
小溪缓缓流过，几尾金色鲤鱼越水而出。
LONG
        );

       set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"gu1",
  "westdown" : __DIR__"gu3",
 
]));
	set("outdoors","tieflag"); 	 
	
         
      setup();

}

