// Room: /d/taohua/qyfroom.c

inherit ROOM;

void create()
{
	set("short", "曲灵风居");
	set("long", @LONG
这里是桃花岛大师兄曲灵风的居所，屋内陈列
简朴，只有一些生活必备之物。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "south" : __DIR__"yonglu7",
  
]));
        set("objects",([
                CLASS_D("taohua") + "/qulingf.c" : 1,
            ]));	

	setup();
	
}
