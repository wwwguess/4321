// xiangcha.c 香茶
// By Marz 03/29/96

inherit ITEM;

void init();
void do_eat();

void create()
{
	set_name("香茶",({"tea", "cha", "xiang cha"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一杯热茶，悠悠地冒着香气～～～\n");
		set("unit", "杯");
		set("value", 1000);
        set("remaining", 2);
        set("drink_supply", 25);
    }
	
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{

	int heal, recover, sen, e_sen, m_sen;
	
	recover = 5;
	
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("你上一个动作还没有完成。\n");
    if(   (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )
     return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

	set("value", 0);
    this_player()->add("water", (int)query("drink_supply"));
    sen = (int)this_player()->query("sen");
    e_sen = (int)this_player()->query("eff_sen");
    m_sen = (int)this_player()->query("max_sen");

// No heal effect for 香茶
/***

    if ( e_sen < m_sen )
	{ 	
		if ( (e_sen + heal) >= m_sen )
		{
			this_player()->set("eff_sen", m_sen);
		} else
		{	
			this_player()->set("eff_sen", e_sen+heal);
		}	
	} 
***/

	if (sen < e_sen )
	{
        if ( (sen + recover) >= e_sen )
        {
            this_player()->set("sen", e_sen);
        } else
        {   
            this_player()->set("sen", sen+recover);
        }   
	}

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") )
	{
   		 message_vision("$N端起杯香茶，有滋有味地品了几口。\n"+
      		"一股香气直入心脾，$N觉得精神好多了。\n", this_player());
	} else 
	{ 
   		 message_vision("$N端起雕花小杯，把剩下的香茶一饮而尽。\n"+
      		"一股香气直入心脾，$N觉得精神好多了。\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
