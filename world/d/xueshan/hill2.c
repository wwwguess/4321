//room: hill2.c
//by dwolf  

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIW"雪山顶"NOR);
        set("long",@LONG
	  你眼前突然开阔，一个水池出现在你面前，一块大石碑卧在池旁，上书四
个大字：雪山绝顶。远处雪水融化形成的水流倒卷而下，激起无数水花，似烟似雾。
你发现瀑布后有条长长的铁链，直通向云天，瀑布下临深谷.半山腰处，隐隐可见一个
峡谷。
LONG
       );
       
       set("exits", ([ 
                "down" : __DIR__"road2",
                      ]));
        set("outdoors", "mountain");
        setup();
}

void init()
{
        add_action("do_hold", "hold");  
}

int do_hold(string arg)
{             

	object me;
	me = this_player();

        if( !arg || arg!= "铁链" )
                return notify_fail("你要抓住什么？\n");
        message_vision("$N伸手往不远处的铁链抓去....\n\n",me);
        if( random((int)me->query_skill("dodge")) < 100 ) {
        message_vision("\n$N只感到时空一阵扭曲，到了一个陌生的地方。\n\n",me);  
        me->move(__DIR__"jqgdi");        
      	} else {
        message_vision("$N随着铁链往前爬，来到一个山洞。\n\n",me);
        me->move(__DIR__"halfhole");  
        }
        return 1;
}

