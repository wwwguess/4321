// qin.c
// Made by ysgl (1997.10.23)


#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("焦尾琴", ({ "jiaowei qin", "qin", "焦尾琴"}) );
        set_weight(8000);
        set_max_encumbrance(8000);
        set("no_get", 1);
	set("no_drop", 1);
        set("no_shown", 1);
	set("skill", ([
                "name":                 "music",
                "exp_required": 	5000,                
                "sen_cost":             40,     
                "difficulty":   50,            
                "max_skill":    50,           
        ]) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "张");
                set("long", "一张焦尾琴，做得如此精致。\n");
                set("value", 100);
                set("material", "wood");
        }
}             

void init()
{
	 if(this_player()==environment())
		add_action("do_play","play");
}
                                   
int do_play(string arg)
{
	object me, obj;
	me = this_player();

	if( !arg || (arg != "焦尾琴" && arg != "琴" && arg != "qin") )
		return notify_fail("你想弹什么？\n");
	if( !(obj = present("jiaowei qin", me)) )
		return notify_fail("没有琴，你弹什么弹？\n");
	if( me->query_skill("music", 1) > 30 ){
		tell_object(me,
	GRN"你弹起一曲高山流水，琴音如阵阵天籁，从空中直泻而下，让人如痴如醉。\n"NOR);		
		return 1;
	}
        tell_object(me,
	GRN"你弹起一曲下里巴人，但是由于你技艺不精，琴音晦涩，使人掩耳相僻。\n"NOR);
	return 1;
}

int is_container() { return 1; }

void owner_is_killed() 
{ 
        remove_call_out("dest");
        call_out("dest", 1, this_object());
}

void dest(object ob)
{
	destruct(ob);
}
