// Room: gold


inherit ROOM;
#include <room.h>

void create()
{
	set("short", "藏宝室");
	set("long", @LONG 
四面墙壁均是用玉做成，正对着你的是一块极大的玉壁。
而房中壁上案头更都摆满了奇珍异宝，无一件不是美到极处，华贵之极的精品,
其中一柄剑鞘嵌满珠宝的长剑已经出鞘，剑光晶莹夺目，不可方物。
LONG
        );
         
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"gu5",
	]));
         
    set("item_desc", ([
                "sword": "
这一看就是一把价值连城的宝剑，剑身是弯的。\n",
                "宝剑": "
这一看就是一把价值连城的宝剑，剑身是弯的。\n",
		"玉壁": "
一整块晶莹的美玉，仿佛经常有人用手触摸。 \n", 
                "jade": "
一整块晶莹的美玉，仿佛经常有人用手触摸。 \n",
    ]) );
    setup();
      
}
 
 void init()
{
   add_action("do_open","push"); 
   
   add_action("do_get","pick");
}

         


int do_open(string arg)
{
    object me;  
	me=this_player();
	switch (arg)
         {
         case "jade":
         case "玉壁":
             if(query("exits/girl")) return notify_fail("门已经是开的了");
             message_vision("$N伸手在玉壁上一按，玉壁上出现一扇小门\n",this_player());
             set("exits/enter",__DIR__"girlroom");
             return 1;
         }
//        default: return notify_fail("你要开什么？\n");
	 
}

int do_get(string arg)
{
    object swo;
	if( query_temp("mark/been_get")) return notify_fail("剑已被拔走了。\n");
        if(random(this_player()->query("kar")) > 19 && random(100)>90) 
        { 
		swo=new(__DIR__"obj/leavehook");
		swo->move(this_player());
		set_temp("mark/been_get",1);
		write("你从墙上拔下了一柄离别钩。\n" );
	}
	else
        { 
		write("你试着去拔剑，却被剑光所伤。\n");
        	this_player()->receive_damage("kee",50);
	}
        
        return 1;

}
void reset()
{
    ::reset();
	delete_temp("mark/been_get");
    if(query("exits/enter"))
    	delete("exits/enter");
}