// Room: /u/dan/room/cave/cave.c
//dan
inherit ROOM;

void create()
{
    set("short", "洞中");
    set("long", @LONG
千年古洞,四处留下岁月年痕.四壁已经斑斑驳驳,依稀可见有
些裂痕了.墙上象是用油彩绘着一些字画.
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
      "south" : __DIR__"shatan1",
      "north" : __DIR__"cave1", 
      "east"  : __DIR__"sleeproom",   
      "west"  : __DIR__"fanting",
    ]));
    
    set("no_clean_up", 0);

    setup();
    replace_program(ROOM);
}
