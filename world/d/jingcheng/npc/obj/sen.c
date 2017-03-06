#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(MAG"人参"NOR,({"sen"}) );
	set("long",	
		YEL"这是一棵有点象干憋的萝卜的东西，闻了闻有一种上等药材的味道。\n"NOR);
	set("unit", "棵");
	set("base_unit", "棵");
	set("base_weight", 200);
set("value",100000);
	set_amount(1);
}

void init()
{
	if( this_player()==environment() )
		add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	int num= this_player()->query("max_gin");
	object ob=this_player();
         if( !arg || arg != "sen")  return notify_fail("^D^C^R^J^S^T^I^U^C^T^D^X? \n");
         if( (int)this_player()->query("combat_exp") < 100000 ){
                message_vision(
                   RED"$N拿出一棵人参，一口给吞了下去。\n"
                   "$N只觉浑身热不可耐，仿佛坠入一个大火炉中一般。"
			 "急忙盘膝而坐，运功相抗。\n" NOR
			 ,this_player() );
        this_player()->set("force",(int)this_player()->query("force")/2 );
         ob->receive_heal("eff_gin", num);
	}
	else{
		message_vision(
		   YEL"$N拿出一棵人参，一口给吞了下去。\n"
		   "$N的丹田中一股热气缓缓提升，周游全身奇经八脉，顿时精神倍增。\n"NOR,this_player() );
		if( (int)this_player()->query("force") <(int)this_player()->query("max_force") )
this_player()->set("force",(int)this_player()->query("max_force"));
        this_player()->set("eff_gin", num);
	}
	add_amount(-1);
	return 1;
}
