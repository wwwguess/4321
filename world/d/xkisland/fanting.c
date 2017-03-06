//xk island.宴会厅.c
//dan
#include <ansi.h>

inherit ROOM;

void create()
{


 set("short", "宴会厅");
    set("long", @LONG
千年古洞,四处留下岁月年痕.四壁已经斑斑驳驳,依稀可见有
些裂痕了.墙上象是用油彩绘着一些字画. 有一些武林豪杰正
在边讨论边吃点心。你如果想吃东西，向弟子yao即可.
LONG
    );
    set("exits", ([ /* sizeof() == 2 */
      
      "east" : __DIR__"cave", 
      
    ]));
    set("objects",([
		__DIR__"npc/lisi" : 1, 
                
	]));
	set("no_fight", 1);
	set("no_sleep", 1);
	setup();
   
    
}    
void init()
{
        add_action("do_yao", "yao");

}

int do_yao()
{
	this_player()->start_busy(5);
	write(YEL "弟子给你一些点心和茶水.\n" NOR);
	write(YEL "你吃饱喝足，擦擦嘴，想继续练功了。\n" NOR);	
	this_player()->set("food",350);
	this_player()->set("water",350);
	return 1;
}
